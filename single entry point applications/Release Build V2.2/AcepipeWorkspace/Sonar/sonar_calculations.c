#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>
#include<math.h>
#include<stdbool.h>
#include"common_enum.h"
#include "command.h"

unsigned char PulseWidth[TL_width]={'E','F','G','H','I','J'};
unsigned char StepSize[TL_stepDegree]={':',';','<','>'};
unsigned char ArcSize[TL_arccDegree]={'0','1','2','3', '4','5','6','7', '8','9'};
unsigned char CentreAngle[TL_centreDegree]={'"','#','$','%','&','\'','(',')','*',',','.'};
unsigned char RepeatRate[TL_RepeatRate]={'K','L','M','N','O','P','Q','R','S','T','{','|','}','~'};

struct sonar_config_para *sonar_config=NULL;
void sonar_initializations()
{

	sonar_config=(struct sonar_config_para*)calloc(1,sizeof(struct sonar_config_para));

    sonar_config->range=1.0;
    sonar_config->velocityofsound=1500.0;
    sonar_config->sample=400;
    sonar_config->samplerate=200; // 200 nano second
    sonar_config->oversample=1;
    sonar_config->pulsewidth=PulseWidth[width2us];
    sonar_config->txpower=4;
    sonar_config->repeatrate=RepeatRate[rate7ms];
    sonar_config->stepsize=StepSize[step09Degree];
    sonar_config->arcsize=ArcSize[arc360Degree];
    sonar_config->centerangle=CentreAngle[centre180Degree];

   

    printf("range %lf \n",sonar_config->range);
    printf("velocityofsound %lf \n",sonar_config->velocityofsound);
    printf("sample %hu \n",sonar_config->sample);
    printf("samplerate %hu \n",sonar_config->samplerate);
    printf("oversample %hhu \n",sonar_config->oversample);
    printf("pulsewidth %c \n",sonar_config->pulsewidth);
    printf("txpower %hhu \n",sonar_config->txpower);
    printf("repeatrate %hhu \n",sonar_config->repeatrate);
    printf("stepsize %c\n",sonar_config->stepsize);
    printf("arcsize %c \n",sonar_config->arcsize);
    printf("centerangle %c \n",sonar_config->centerangle);

    SetSamplingParameters(sonar_config,1,400.0,1500.0);

    
    // configure sonar parameter
    set_step_size();
    set_centre_angle();
    set_oversamples();
    set_number_of_samples();
    set_repeat_rate();
    set_scan_arc_size();
    set_tx_power();
    set_tx_pulse_width();

    //set motor head to zero positions
    locate_to_zero_position();

     
}

bool SetSamplingParameters(struct sonar_config_para *s_ptr, double range, uint16_t requestedSamples, double vos)
{

     uint16_t sampleRate = 200; // ns
     bool tuneSamples = false;
     int maxSamples = 1000;
     uint16_t calculatedSamples = 0;
     int oversamples = 0;
     uint16_t maxSampleRate = 440;


                 // Start with a low value for sample rate and gradually increase it until a usable parameters are found
    for (;sampleRate <= maxSampleRate; sampleRate += 20)
     {
                // Increase the oversamples until the we go one step too far then step it back and tune.
        for (oversamples = 0; oversamples < 8; oversamples++)
         {
             double tempRange = (requestedSamples * (sampleRate * pow(10.0, -9.0)) * pow(2.0, oversamples) * vos) / 2.0;
             double rangeDifference = range - tempRange;

             if (rangeDifference < 0)
                    {
                        if (oversamples > 0) oversamples--;
                        tuneSamples = true;
                        break;
                    }
        }

        if (tuneSamples)
         {
                    // Tune by stepping the sample rate until the number of samples are close to the requested
            for (; sampleRate <= maxSampleRate; sampleRate += 20)
                    {
                        calculatedSamples = (uint16_t)(range / (sampleRate * pow(10.0, -9.0) * pow(2.0, oversamples) * vos / 2.0));
                        if (calculatedSamples <= (requestedSamples + 100) && calculatedSamples <= maxSamples) break;
                    }
                    break;
         }
    }

    double actualRange = (calculatedSamples * (sampleRate * pow(10.0, -9.0)) * pow(2.0, oversamples) * vos) / 2.0;

            if (actualRange > 0.0 && calculatedSamples < maxSamples)
            {
                s_ptr->velocityofsound = vos;
                s_ptr->range = actualRange;
                s_ptr->samplerate = sampleRate;
                s_ptr->sample = calculatedSamples;
                s_ptr->oversample = (uint8_t)oversamples;
                s_ptr->repeatrate = CalculateRepeatRate(calculatedSamples, (uint8_t)oversamples, sampleRate);

                return true;
            }
            else return false;

}

// <summary>
        // Check ArcSize is valid for current CentreAngle
        // and reset to the closest valid value if not
        // </summary>
        // <returns>true if ArcSize is valid; false if invalid</returns>
 bool VerifyArcSize( uint8_t * arcSize, uint8_t centreAngle)
{
 switch (centreAngle)
    {

        case '"':
            if (*arcSize > ArcSize[arc60Degree]) { *arcSize = ArcSize[arc60Degree]; return false; }
            break;
        case '#':
            if (*arcSize > ArcSize[arc120Degree]) { *arcSize = ArcSize[arc120Degree]; return false; }
            break;
        case '$':
            if (*arcSize > ArcSize[arc180Degree]) { *arcSize = ArcSize[arc180Degree]; return false; }
            break;
        case '%':
            if (*arcSize > ArcSize[arc240Degree]) { *arcSize = ArcSize[arc240Degree]; return false; }
            break;
        case '&':
            if (*arcSize > ArcSize[arc270Degree]) { *arcSize = ArcSize[arc270Degree]; return false; }
            break;
        case '(':
            if (*arcSize > ArcSize[arc270Degree]) { *arcSize = ArcSize[arc270Degree]; return false; }
            break;
        case ')':
            if (*arcSize > ArcSize[arc240Degree]) { *arcSize = ArcSize[arc240Degree]; return false; }
            break;
        case '*':
            if (*arcSize > ArcSize[arc180Degree]) { *arcSize = ArcSize[arc180Degree]; return false; }
            break;
        case ',':
            if (*arcSize > ArcSize[arc120Degree]) { *arcSize = ArcSize[arc120Degree]; return false; }
            break;
        case '.':
            if (*arcSize > ArcSize[arc60Degree]) { *arcSize = ArcSize[arc60Degree]; return false; }
            break;
    }

    return true;
}


// <summary>
        // Check if CentreAngle is valid for the current ArcSize
        // and reset to the closest valid value if not
        // </summary>
        // <returns>true if CentreAngle is valid</returns>
 bool VerifyCentreAngle(uint8_t arcSize, uint8_t * centreAngle)
{
    switch (arcSize)
    {
        case '2':
            if (*centreAngle < CentreAngle[centre60Degree]) { *centreAngle = CentreAngle[centre60Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre300Degree]) { *centreAngle = CentreAngle[centre300Degree]; return false; }
            break;
        case '3':
            if (*centreAngle < CentreAngle[centre60Degree]) { *centreAngle = CentreAngle[centre60Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre300Degree]) { *centreAngle = CentreAngle[centre300Degree]; return false; }
            break;
        case '4':
            if (*centreAngle < CentreAngle[centre90Degree]) { *centreAngle = CentreAngle[centre90Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre270Degree]) { *centreAngle = CentreAngle[centre270Degree]; return false; }
            break;
        case '5':
            if (*centreAngle < CentreAngle[centre90Degree]) { *centreAngle = CentreAngle[centre90Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre270Degree]) { *centreAngle = CentreAngle[centre270Degree]; return false; }
            break;
        case '6':
            if (*centreAngle < CentreAngle[centre120Degree]) { *centreAngle = CentreAngle[centre120Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre240Degree]) { *centreAngle = CentreAngle[centre240Degree]; return false; }
            break;
        case '7':
            if (*centreAngle < CentreAngle[centre120Degree]) {*centreAngle = CentreAngle[centre120Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre240Degree]) { *centreAngle = CentreAngle[centre240Degree]; return false; }
            break;
        case '8':
            if (*centreAngle < CentreAngle[centre150Degree]) { *centreAngle = CentreAngle[centre150Degree]; return false; }
            else if (*centreAngle > CentreAngle[centre210Degree]) { *centreAngle = CentreAngle[centre210Degree]; return false; }
            break;
        case '9':
            if (*centreAngle != CentreAngle[centre180Degree]) { *centreAngle = CentreAngle[centre180Degree]; return false; }
            break;
    }

    return true;
}

int GetPulseWidthMicroseconds(uint8_t pulseWidth)
{
    switch(pulseWidth)
    {
        case 'E':
            return 2;
        case 'F':
            return 4;
        case 'G':
            return 8;
        case 'H':
            return 12;
        case 'I':
            return 16;
        case 'J':
            return 20;
        default:
            return 0;
    }
}

 int16_t GetStepsPerPing(uint8_t stepSize)
{
    switch (stepSize)
    {
        case ':':
            return 1;
        case ';':
            return 2;
        case '<':
            return 3;
        case '>':
            return 4;
        default:
            return 1;
    }
}

int16_t GetCentreAngleGradians(uint8_t centreAngle)
{
    switch (centreAngle)
    {
        case '"':
            return 33;
        case '#':
            return 67;
        case '$':
            return 100;
        case '%':
            return 133;
        case '&':
            return 167;
        case '\'':
            return 200;
        case '(':
            return 233;
        case ')':
            return 267;
        case '*':
            return 300;
        case ',':
            return 333;
        case '.':
            return 367;
        default:
            return 200;
    }
}

int16_t GetHalfArcSizeGradians(uint8_t arcSize)
{
    switch (arcSize)
    {
        case '0':
            return 17;
        case '1':
            return 33;
        case '2':
            return 50;
        case '3':
            return 67;
        case '4':
            return 83;
        case '5':
            return 100;
        case '6':
            return 117;
        case '7':
            return 133;
        case '8':
            return 150;
        case '9':
            return 200;
        default:
            return 200;
    }
}

double GetAngleFromArcSize(uint8_t arcSize, bool radians)
{
    double radiansPerDeg = 3.1411/ 180.0;
    double angle = 0.0;

    switch (arcSize)
    {
        case '0':
            angle = 30.0;
            break;
        case '1':
            angle = 60.0;
            break;
        case '2':
            angle = 90.0;
            break;
        case '3':
            angle = 120.0;
            break;
        case '4':
            angle = 150.0;
            break;
        case '5':
            angle = 180.0;
            break;
        case '6':
            angle = 210.0;
            break;
        case '7':
            angle = 240.0;
            break;
        case '8':
            angle = 270.0;
            break;
        case '9':
            angle = 360.0;
            break;
        default:
            angle = 360.0;
            break;
    }

    if (radians) angle = angle * radiansPerDeg;

    return angle;
}


 // <summary>
        // Converts CentreAngle enum into an angle in radians
        // </summary>
        // <param name="centreAngle"></param>
        // <returns>Angle in radians</returns>
  double GetAngleFromCentreAngle(uint8_t centreAngle, bool radians)
{
    double radiansPerDeg = 3.141 / 180.0;
    double angle = 0.0;

    switch (centreAngle)
    {
        case '"':
            angle = 30.0;
            break;
        case '#':
            angle = 60.0;
            break;
        case '$':
            angle = 90.0;
            break;
        case '%':
            angle = 120.0;
            break;
        case '&':
            angle = 150.0;
            break;
        case '\'':
            angle = 180.0;
            break;
        case '(':
            angle = 210.0;
            break;
        case ')':
            angle = 240.0;
            break;
        case '*':
            angle = 270.0;
            break;
        case ',':
            angle = 300.0;
            break;
        case '.':
            angle = 330.0;
            break;
        default:
            angle = 180.0;
            break;
    }

    if (radians) angle = angle * radiansPerDeg;

    return angle;
}

int16_t GetNumberOfPings(uint8_t arcSize, uint8_t centreAngle, uint8_t stepSize)
{
    int16_t stepsPerPing = GetStepsPerPing(stepSize);

    int sweepStart = GetCentreAngleGradians(centreAngle) - GetHalfArcSizeGradians(arcSize);
    int sweepStop = GetCentreAngleGradians(centreAngle) + GetHalfArcSizeGradians(arcSize) - 1;

    if (sweepStart < 0)
        sweepStart = 0;

    if (sweepStop > 399)
        sweepStop = 399;

    int16_t pingCount = 0;
    while (sweepStart <= sweepStop)
    {
        pingCount++;
        sweepStart += stepsPerPing;
    }

    return pingCount;
}

uint8_t CalculateRepeatRate(uint16_t samples, int8_t oversamples, float sampleRate)
{
    // Repeat rate is just the time that the receiver is active

    if (samples == 0) samples = 250;
    //if (oversamples > 7) oversamples = 7;
    if (sampleRate < 2.5) sampleRate = 2.5f;

    double rate = (sampleRate * pow(10.0, -9.0) * samples * pow(2.0, oversamples)) * 1000.0;

    return GetRepeatRateEnum(rate);
}

    // <summary>
    // Returns the best repeat rate to use for a given calculated repeat rate
    // </summary>
    // <param name="repeatRate">in ms</param>
    // <returns></returns>
uint8_t GetRepeatRateEnum(double repeatRatems)
{
    if (repeatRatems < 0.2) return RepeatRate[rate200us];
    if (repeatRatems < 0.5) return RepeatRate[rate500us];
    if (repeatRatems < 1.0) return RepeatRate[rate1ms];
    if (repeatRatems < 1.5) return RepeatRate[rate1p5ms];
    if (repeatRatems < 2.0) return RepeatRate[rate2ms];
    if (repeatRatems < 3.0) return RepeatRate[rate3ms];
    if (repeatRatems < 4.0) return RepeatRate[rate4ms];
    if (repeatRatems < 5.0) return RepeatRate[rate5ms];
    if (repeatRatems < 7.0) return RepeatRate[rate7ms];
    if (repeatRatems < 10.0) return RepeatRate[rate10ms];
    if (repeatRatems < 13.3) return RepeatRate[rate13p3ms];
    if (repeatRatems < 18.0) return RepeatRate[rate18ms];
    if (repeatRatems < 26.7) return RepeatRate[rate26p7ms];
    return RepeatRate[rate36ms];
}

    // <summary>
    // Converts the RepeatRate enum into a time in seconds
    // </summary>
    // <param name="repeatRate"></param>
    // <returns></returns>
double GetRepeatRateSeconds(uint8_t repeatRate)
{

    switch (repeatRate)
    {
        case 'K':   // 200us
            return 0.0002;
        case 'L':   //500us
            return 0.0005;
        case 'M':       // 1ms
            return 0.001;
        case 'N':       //1.5ms
            return 0.0015;
        case 'O':       //2 ms
            return 0.002;
        case 'P':           //3ms
            return 0.003;
        case 'Q':           //4ms
            return 0.004;
        case 'R':           //5ms
            return 0.005;
        case 'S':           //7ms
            return 0.007;
        case 'T':       //10 ms
            return 0.01;
        case '{':       // 13ms
            return 0.0133;
        case '|':       //18ms
            return 0.018;
        case '}':       //26.7ms
            return 0.0267;
        case '~':       //36 ms
            return 0.036;
        default:
            return 0.036;
    }
}

    // <summary>
    // Convert StepSize enum into corresponding angle in degrees
    // </summary>
    // <param name="stepSize"></param>
    // <returns>Step size in degrees</returns>
double GetStepSizeDegrees(uint8_t stepSize)
{
    switch (stepSize)
    {
        case ':':
            return 0.9;
        case ';':
            return 1.8;
        case '<':
            return 2.7;
        case '>':
            return 3.6;
    }

    return 0.9;
}

    // <summary>
    // Converts a step size to the corresponding enum
    // </summary>
    // <param name="stepAngleDegrees">Step size in degrees</param>
    // <returns></returns>
uint8_t GetStepSizeEnum(double stepAngleDegrees)
{
    if (stepAngleDegrees < 1.8)
        return StepSize[step09Degree];
    if (stepAngleDegrees < 2.7)
        return StepSize[step18Degree];
    if (stepAngleDegrees < 3.6)
        return StepSize[step27Degree];
    else return StepSize[step36Degree];
}
