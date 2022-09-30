#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED
#include<stdint.h>
#include<stdbool.h>

/*enum CommResult1:unsigned char
{
	Success = 0,
    Timeout = 1,
    BadChecksum = 2,
    InvalidResponse = 3,
    Failed = 4

};
 unsigned char CommResult[5]={CommResult1::Success,CommResult1::Timeout,CommResult1::BadChecksum, /
 CommResult1::InvalidResponse,CommResult1::Failed};

enum  ProfilerFileType1
{
        IMG = 0,
        IMG2 = 1,
        IMG3 = 2,
        PST = 3,
};

 int ProfilerFileType[4]={ProfilerFileType1::Success,ProfilerFileType1::Timeout, /
 ProfilerFileType1::BadChecksum,ProfilerFileType1::InvalidResponse,Failed};*/

/*enum  CableCounterType
{
        None,
        OnBoard,
};

enum  UWUType
{
        None = 0,
        Profiler1512 = 1,
        Profiler2512 = 2,
};

enum   ActiveTool
{
        None,
        MeasurementLine,
        MeasurementCircle,
        Profile,
};*/

enum PULSEWIDTH
{
        width2us=0, width4us, width8us, width12us , width16us , width20us ,TL_width
};

enum STEPSIZE
{
        step09Degree=0,step18Degree,step27Degree,step36Degree ,TL_stepDegree
};


enum ARCSIZE
{
         arc30Degree=0, arc60Degree, arc90Degree, arc120Degree, arc150Degree, arc180Degree, arc210Degree, \
        arc240Degree, arc270Degree, arc360Degree,TL_arccDegree
};

enum CENTERANGLE
{
        centre30Degree=0 , centre60Degree,centre90Degree , centre120Degree, centre150Degree ,
        centre180Degree ,centre210Degree,centre240Degree,centre270Degree ,centre300Degree,centre330Degree,
	TL_centreDegree
};

enum  REPEATRATE
{
         rate200us=0, rate500us, rate1ms, rate1p5ms, rate2ms,  rate3ms,  rate4ms,  rate5ms, rate7ms ,
        rate10ms,  rate13p3ms, rate18ms , rate26p7ms,  rate36ms,TL_RepeatRate
};

struct sonar_config_para
{
    double range;
    double velocityofsound;
    uint16_t sample;
    uint16_t samplerate;
    uint8_t oversample;
    uint8_t pulsewidth;
    uint8_t txpower;
    uint8_t repeatrate;
    uint8_t stepsize;
    uint8_t arcsize;
    char centerangle;

};


unsigned char PulseWidth[TL_width];//={'E','F','G','H','I','J'};
unsigned char StepSize[TL_stepDegree];//={':',';','<','>'};
unsigned char ArcSize[TL_arccDegree];//={'0','1','2','3', '4','5','6','7', '8','9'};
unsigned char CentreAngle[TL_centreDegree];//={'"','#','$','%','&','\'','(',')','*',',','.'};
unsigned char RepeatRate[TL_RepeatRate];//={'K','L','M','N','O','P','Q','R','S','T','{','|','}','~'};



/*


*/
int16_t Sectors();
void ScanSettings();
bool IncrementArcSize();
bool DecrementArcSize();
bool IncrementCentreAngle();
bool DecrementCentreAngle();



/**************************************************************************************************/
void sonar_initializations();
bool SetSamplingParameters(struct sonar_config_para *s_ptr  , double range, uint16_t requestedSamples, double vos);
bool VerifyArcSize( uint8_t * arcSize, uint8_t centreAngle);
bool VerifyCentreAngle(uint8_t arcSize, uint8_t * centreAngle);
int GetPulseWidthMicroseconds(uint8_t pulseWidth);
int16_t GetStepsPerPing(uint8_t stepSize);
int16_t GetCentreAngleGradians(uint8_t centreAngle);
int16_t GetHalfArcSizeGradians(uint8_t arcSize);
double GetAngleFromArcSize(uint8_t arcSize, bool radians);
double GetAngleFromCentreAngle(uint8_t centreAngle, bool radians);
int16_t GetNumberOfPings(uint8_t arcSize, uint8_t centreAngle, uint8_t stepSize);
uint8_t CalculateRepeatRate(uint16_t samples, int8_t oversamples, float sampleRate);
uint8_t GetRepeatRateEnum(double repeatRatems);
double GetRepeatRateSeconds(uint8_t repeatRate);
double GetStepSizeDegrees(uint8_t stepSize);

#endif
