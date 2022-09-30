using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PipeProfiler3
{
    class ScanSettingsCalculator
    {
        /// <summary>
        /// Fits the sampling parameters 
        /// </summary>
        /// <param name="range">Desired range in metres</param>
        /// <param name="requestedSamples">Desired range resolution</param>
        /// <param name="vos">Velocity of sound in m/s</param>
        public static bool SetSamplingParameters(ScanSettings scanSettings, double range, UInt16 requestedSamples, double vos)
        {
            UInt16 sampleRate = 200; // ns
            bool tuneSamples = false;
            int maxSamples = 1000;
            UInt16 calculatedSamples = 0;
            int oversamples = 0;
            UInt16 maxSampleRate = 440;

            // Start with a low value for sample rate and gradually increase it until a usable parameters are found
            for (; sampleRate <= maxSampleRate; sampleRate += 20)
            {
                // Increase the oversamples until the we go one step too far then step it back and tune. 
                for (oversamples = 0; oversamples < 8; oversamples++)
                {
                    double tempRange = (requestedSamples * (sampleRate * Math.Pow(10.0, -9.0)) * Math.Pow(2.0, oversamples) * vos) / 2.0;
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
                        calculatedSamples = (ushort)(range / (sampleRate * Math.Pow(10.0, -9.0) * Math.Pow(2.0, oversamples) * vos / 2.0));
                        if (calculatedSamples <= (requestedSamples + 100) && calculatedSamples <= maxSamples) break;
                    }
                    break;
                }
            }

            double actualRange = (calculatedSamples * (sampleRate * Math.Pow(10.0, -9.0)) * Math.Pow(2.0, oversamples) * vos) / 2.0;

            if (actualRange > 0.0 && calculatedSamples < maxSamples)
            {
                scanSettings.VelocityOfSound = vos;
                scanSettings.Range = actualRange;
                scanSettings.SampleRate = sampleRate;
                scanSettings.Samples = calculatedSamples;
                scanSettings.Oversamples = (byte)oversamples;
                scanSettings.RepeatRate = ScanSettingsCalculator.CalculateRepeatRate(calculatedSamples, (byte)oversamples, sampleRate);

                return true;
            }
            else return false;
        }

        /// <summary>
        /// Check ArcSize is valid for current CentreAngle
        /// and reset to the closest valid value if not
        /// </summary>
        /// <returns>true if ArcSize is valid; false if invalid</returns>
        public static bool VerifyArcSize(ref ArcSize arcSize, CentreAngle centreAngle)
        {
            switch (centreAngle)
            {
                case CentreAngle.centre30Degree:
                    if (arcSize > ArcSize.arc60Degree) { arcSize = ArcSize.arc60Degree; return false; }
                    break;
                case CentreAngle.centre60Degree:
                    if (arcSize > ArcSize.arc120Degree) { arcSize = ArcSize.arc120Degree; return false; }
                    break;
                case CentreAngle.centre90Degree:
                    if (arcSize > ArcSize.arc180Degree) { arcSize = ArcSize.arc180Degree; return false; }
                    break;
                case CentreAngle.centre120Degree:
                    if (arcSize > ArcSize.arc240Degree) { arcSize = ArcSize.arc240Degree; return false; }
                    break;
                case CentreAngle.centre150Degree:
                    if (arcSize > ArcSize.arc270Degree) { arcSize = ArcSize.arc270Degree; return false; }
                    break;
                case CentreAngle.centre210Degree:
                    if (arcSize > ArcSize.arc270Degree) { arcSize = ArcSize.arc270Degree; return false; }
                    break;
                case CentreAngle.centre240Degree:
                    if (arcSize > ArcSize.arc240Degree) { arcSize = ArcSize.arc240Degree; return false; }
                    break;
                case CentreAngle.centre270Degree:
                    if (arcSize > ArcSize.arc180Degree) { arcSize = ArcSize.arc180Degree; return false; }
                    break;
                case CentreAngle.centre300Degree:
                    if (arcSize > ArcSize.arc120Degree) { arcSize = ArcSize.arc120Degree; return false; }
                    break;
                case CentreAngle.centre330Degree:
                    if (arcSize > ArcSize.arc60Degree) { arcSize = ArcSize.arc60Degree; return false; }
                    break;
            }

            return true;
        }

        /// <summary>
        /// Check if CentreAngle is valid for the current ArcSize
        /// and reset to the closest valid value if not
        /// </summary>
        /// <returns>true if CentreAngle is valid</returns>
        public static bool VerifyCentreAngle(ArcSize arcSize, ref CentreAngle centreAngle)
        {
            switch (arcSize)
            {
                case ArcSize.arc90Degree:
                    if (centreAngle < CentreAngle.centre60Degree) { centreAngle = CentreAngle.centre60Degree; return false; }
                    else if (centreAngle > CentreAngle.centre300Degree) { centreAngle = CentreAngle.centre300Degree; return false; }
                    break;
                case ArcSize.arc120Degree:
                    if (centreAngle < CentreAngle.centre60Degree) { centreAngle = CentreAngle.centre60Degree; return false; }
                    else if (centreAngle > CentreAngle.centre300Degree) { centreAngle = CentreAngle.centre300Degree; return false; }
                    break;
                case ArcSize.arc150Degree:
                    if (centreAngle < CentreAngle.centre90Degree) { centreAngle = CentreAngle.centre90Degree; return false; }
                    else if (centreAngle > CentreAngle.centre270Degree) { centreAngle = CentreAngle.centre270Degree; return false; }
                    break;
                case ArcSize.arc180Degree:
                    if (centreAngle < CentreAngle.centre90Degree) { centreAngle = CentreAngle.centre90Degree; return false; }
                    else if (centreAngle > CentreAngle.centre270Degree) { centreAngle = CentreAngle.centre270Degree; return false; }
                    break;
                case ArcSize.arc210Degree:
                    if (centreAngle < CentreAngle.centre120Degree) { centreAngle = CentreAngle.centre120Degree; return false; }
                    else if (centreAngle > CentreAngle.centre240Degree) { centreAngle = CentreAngle.centre240Degree; return false; }
                    break;
                case ArcSize.arc240Degree:
                    if (centreAngle < CentreAngle.centre120Degree) { centreAngle = CentreAngle.centre120Degree; return false; }
                    else if (centreAngle > CentreAngle.centre240Degree) { centreAngle = CentreAngle.centre240Degree; return false; }
                    break;
                case ArcSize.arc270Degree:
                    if (centreAngle < CentreAngle.centre150Degree) { centreAngle = CentreAngle.centre150Degree; return false; }
                    else if (centreAngle > CentreAngle.centre210Degree) { centreAngle = CentreAngle.centre210Degree; return false; }
                    break;
                case ArcSize.arc360Degree:
                    if (centreAngle != CentreAngle.centre180Degree) { centreAngle = CentreAngle.centre180Degree; return false; }
                    break;
            }

            return true;
        }

        public static int GetPulseWidthMicroseconds(PulseWidth pulseWidth)
        {
            switch(pulseWidth)
            {
                case PulseWidth.width2us:
                    return 2;
                case PulseWidth.width4us:
                    return 4;
                case PulseWidth.width8us:
                    return 8;
                case PulseWidth.width12us:
                    return 12;
                case PulseWidth.width16us:
                    return 16;
                case PulseWidth.width20us:
                    return 20;
                default:
                    return 0;
            }
        }

        public static Int16 GetStepsPerPing(StepSize stepSize)
        {
            switch (stepSize)
            {
                case StepSize.step09Degree:
                    return 1;
                case StepSize.step18Degree:
                    return 2;
                case StepSize.step27Degree:
                    return 3;
                case StepSize.step36Degree:
                    return 4;
                default:
                    return 1;
            }
        }

        public static Int16 GetCentreAngleGradians(CentreAngle centreAngle)
        {
            switch (centreAngle)
            {
                case CentreAngle.centre30Degree:
                    return 33;
                case CentreAngle.centre60Degree:
                    return 67;
                case CentreAngle.centre90Degree:
                    return 100;
                case CentreAngle.centre120Degree:
                    return 133;
                case CentreAngle.centre150Degree:
                    return 167;
                case CentreAngle.centre180Degree:
                    return 200;
                case CentreAngle.centre210Degree:
                    return 233;
                case CentreAngle.centre240Degree:
                    return 267;
                case CentreAngle.centre270Degree:
                    return 300;
                case CentreAngle.centre300Degree:
                    return 333;
                case CentreAngle.centre330Degree:
                    return 367;
                default:
                    return 200;
            }
        }

        public static Int16 GetHalfArcSizeGradians(ArcSize arcSize)
        {
            switch (arcSize)
            {
                case ArcSize.arc30Degree:
                    return 17;
                case ArcSize.arc60Degree:
                    return 33;
                case ArcSize.arc90Degree:
                    return 50;
                case ArcSize.arc120Degree:
                    return 67;
                case ArcSize.arc150Degree:
                    return 83;
                case ArcSize.arc180Degree:
                    return 100;
                case ArcSize.arc210Degree:
                    return 117;
                case ArcSize.arc240Degree:
                    return 133;
                case ArcSize.arc270Degree:
                    return 150;
                case ArcSize.arc360Degree:
                    return 200;
                default:
                    return 200;
            }
        }

        public static double GetAngleFromArcSize(ArcSize arcSize, bool radians)
        {
            double radiansPerDeg = Math.PI / 180.0;
            double angle = 0.0;

            switch (arcSize)
            {
                case ArcSize.arc30Degree:
                    angle = 30.0;
                    break;
                case ArcSize.arc60Degree:
                    angle = 60.0;
                    break;
                case ArcSize.arc90Degree:
                    angle = 90.0;
                    break;
                case ArcSize.arc120Degree:
                    angle = 120.0;
                    break;
                case ArcSize.arc150Degree:
                    angle = 150.0;
                    break;
                case ArcSize.arc180Degree:
                    angle = 180.0;
                    break;
                case ArcSize.arc210Degree:
                    angle = 210.0;
                    break;
                case ArcSize.arc240Degree:
                    angle = 240.0;
                    break;
                case ArcSize.arc270Degree:
                    angle = 270.0;
                    break;
                case ArcSize.arc360Degree:
                    angle = 360.0;
                    break;
                default:
                    angle = 360.0;
                    break;
            }

            if (radians) angle = angle * radiansPerDeg;

            return angle;
        }

        /// <summary>
        /// Converts CentreAngle enum into an angle in radians
        /// </summary>
        /// <param name="centreAngle"></param>
        /// <returns>Angle in radians</returns>
        public static double GetAngleFromCentreAngle(CentreAngle centreAngle, bool radians)
        {
            double radiansPerDeg = Math.PI / 180.0;
            double angle = 0.0;

            switch (centreAngle)
            {
                case CentreAngle.centre30Degree:
                    angle = 30.0;
                    break;
                case CentreAngle.centre60Degree:
                    angle = 60.0;
                    break;
                case CentreAngle.centre90Degree:
                    angle = 90.0;
                    break;
                case CentreAngle.centre120Degree:
                    angle = 120.0;
                    break;
                case CentreAngle.centre150Degree:
                    angle = 150.0;
                    break;
                case CentreAngle.centre180Degree:
                    angle = 180.0;
                    break;
                case CentreAngle.centre210Degree:
                    angle = 210.0;
                    break;
                case CentreAngle.centre240Degree:
                    angle = 240.0;
                    break;
                case CentreAngle.centre270Degree:
                    angle = 270.0;
                    break;
                case CentreAngle.centre300Degree:
                    angle = 300.0;
                    break;
                case CentreAngle.centre330Degree:
                    angle = 330.0;
                    break;
                default:
                    angle = 180.0;
                    break;
            }

            if (radians) angle = angle * radiansPerDeg;

            return angle;
        }

        public static Int16 GetNumberOfPings(ArcSize arcSize, CentreAngle centreAngle, StepSize stepSize)
        {
            Int16 stepsPerPing = GetStepsPerPing(stepSize);

            int sweepStart = GetCentreAngleGradians(centreAngle) - GetHalfArcSizeGradians(arcSize);
            int sweepStop = GetCentreAngleGradians(centreAngle) + GetHalfArcSizeGradians(arcSize) - 1;

            if (sweepStart < 0)
                sweepStart = 0;

            if (sweepStop > 399)
                sweepStop = 399;

            Int16 pingCount = 0;
            while (sweepStart <= sweepStop)
            {
                pingCount++;
                sweepStart += stepsPerPing;
            }

            return pingCount;
        }

        #region Static Methods
        public static RepeatRate CalculateRepeatRate(ushort samples, byte oversamples, float sampleRate)
        {
            // Repeat rate is just the time that the receiver is active

            if (samples == 0) samples = 250;
            //if (oversamples > 7) oversamples = 7;
            if (sampleRate < 2.5) sampleRate = 2.5f;

            double rate = (sampleRate * Math.Pow(10.0, -9.0) * samples * Math.Pow(2.0, oversamples)) * 1000.0;

            return ScanSettingsCalculator.GetRepeatRateEnum(rate);
        }

        /// <summary>
        /// Returns the best repeat rate to use for a given calculated repeat rate
        /// </summary>
        /// <param name="repeatRate">in ms</param>
        /// <returns></returns>
        public static RepeatRate GetRepeatRateEnum(double repeatRatems)
        {
            if (repeatRatems < 0.2) return RepeatRate.rate200us;
            if (repeatRatems < 0.5) return RepeatRate.rate500us;
            if (repeatRatems < 1.0) return RepeatRate.rate1ms;
            if (repeatRatems < 1.5) return RepeatRate.rate1p5ms;
            if (repeatRatems < 2.0) return RepeatRate.rate2ms;
            if (repeatRatems < 3.0) return RepeatRate.rate3ms;
            if (repeatRatems < 4.0) return RepeatRate.rate4ms;
            if (repeatRatems < 5.0) return RepeatRate.rate5ms;
            if (repeatRatems < 7.0) return RepeatRate.rate7ms;
            if (repeatRatems < 10.0) return RepeatRate.rate10ms;
            if (repeatRatems < 13.3) return RepeatRate.rate13p3ms;
            if (repeatRatems < 18.0) return RepeatRate.rate18ms;
            if (repeatRatems < 26.7) return RepeatRate.rate26p7ms;
            return RepeatRate.rate36ms;
        }

        /// <summary>
        /// Converts the RepeatRate enum into a time in seconds
        /// </summary>
        /// <param name="repeatRate"></param>
        /// <returns></returns>
        public static double GetRepeatRateSeconds(RepeatRate repeatRate)
        {
            switch (repeatRate)
            {
                case RepeatRate.rate200us:
                    return 0.0002;
                case RepeatRate.rate500us:
                    return 0.0005;
                case RepeatRate.rate1ms:
                    return 0.001;
                case RepeatRate.rate1p5ms:
                    return 0.0015;
                case RepeatRate.rate2ms:
                    return 0.002;
                case RepeatRate.rate3ms:
                    return 0.003;
                case RepeatRate.rate4ms:
                    return 0.004;
                case RepeatRate.rate5ms:
                    return 0.005;
                case RepeatRate.rate7ms:
                    return 0.007;
                case RepeatRate.rate10ms:
                    return 0.01;
                case RepeatRate.rate13p3ms:
                    return 0.0133;
                case RepeatRate.rate18ms:
                    return 0.018;
                case RepeatRate.rate26p7ms:
                    return 0.0267;
                case RepeatRate.rate36ms:
                    return 0.036;
                default:
                    return 0.036;
            }
        }

        /// <summary>
        /// Convert StepSize enum into corresponding angle in degrees
        /// </summary>
        /// <param name="stepSize"></param>
        /// <returns>Step size in degrees</returns>
        public static double GetStepSizeDegrees(StepSize stepSize)
        {
            switch (stepSize)
            {
                case StepSize.step09Degree:
                    return 0.9;
                case StepSize.step18Degree:
                    return 1.8;
                case StepSize.step27Degree:
                    return 2.7;
                case StepSize.step36Degree:
                    return 3.6;
            }

            return 0.9;
        }

        /// <summary>
        /// Converts a step size to the corresponding enum
        /// </summary>
        /// <param name="stepAngleDegrees">Step size in degrees</param>
        /// <returns></returns>
        public static StepSize GetStepSizeEnum(double stepAngleDegrees)
        {
            if (stepAngleDegrees < 1.8)
                return StepSize.step09Degree;
            if (stepAngleDegrees < 2.7)
                return StepSize.step18Degree;
            if (stepAngleDegrees < 3.6)
                return StepSize.step27Degree;
            else return StepSize.step36Degree;
        }
        #endregion
    }
}
