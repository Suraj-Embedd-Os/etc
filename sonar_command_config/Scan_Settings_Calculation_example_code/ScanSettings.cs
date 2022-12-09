using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PipeProfiler3
{
    public class ScanSettings : INotifyPropertyChanged, ICloneable
    {
        double range = 1.0;
        double velocityOfSound = 1500.0;

        UInt16 samples = 400;
        byte oversamples = 1;
        UInt16 sampleRate = 200;
        PulseWidth pulseWidth = PulseWidth.width2us;
        byte txPower = 4;
        RepeatRate repeatRate = RepeatRate.rate7ms;
        StepSize stepSize = StepSize.step09Degree;
        ArcSize arcSize = ArcSize.arc360Degree;
        CentreAngle centreAngle = CentreAngle.centre180Degree;

        public UInt16 Samples
        {
            get { return samples; }
            set
            {
                if(samples != value)
                {
                    samples = value;
                    OnPropertyChanged("Samples");
                }
            }
        }

        /// <summary>
        /// Oversamples
        /// </summary>
        public byte Oversamples
        {
            get { return oversamples; }
            set
            {
                if (oversamples != value)
                {
                    oversamples = value;
                    OnPropertyChanged("Oversamples");
                }
            }
        }

        /// <summary>
        /// Sample rate in ns to the nearest 20ns
        /// </summary>
        public UInt16 SampleRate
        {
            get { return sampleRate; }
            set
            {
                if(sampleRate != value)
                {
                    sampleRate = value;
                    OnPropertyChanged("SampleRate");
                }
            }
        }

        /// <summary>
        /// Pulse width (enum)
        /// </summary>
        public PulseWidth PulseWidth
        {
            get { return pulseWidth; }
            set
            {
                if (pulseWidth != value)
                {
                    pulseWidth = value;
                    OnPropertyChanged("PulseWidth");
                }
            }
        }

        /// <summary>
        /// Transmit power (0 - 7) min to max
        /// </summary>
        public byte TxPower
        {
            get { return txPower; }
            set
            {
                if(txPower != value)
                {
                    txPower = value;
                    OnPropertyChanged("TxPower");
                }
            }
        }

        /// <summary>
        /// Repeat Rate. Time between pings during a sweep. (enum)
        /// </summary>
        public RepeatRate RepeatRate
        {
            get { return repeatRate; }
            set
            {
                if(repeatRate != value)
                {
                    repeatRate = value;
                    OnPropertyChanged("RepeatRate");
                }
            }
        }

        /// <summary>
        /// Step Size (enum)
        /// </summary>
        public StepSize StepSize
        {
            get { return stepSize; }
            set
            {
                if(stepSize != value)
                {
                    stepSize = value;
                    OnPropertyChanged("StepSize");
                }
            }
        }

        public ArcSize ArcSize
        {
            get { return arcSize; }
            set
            {
                if (arcSize != value)
                {
                    arcSize = value;
                    OnPropertyChanged("ArcSize");
                }
            }
        }

        public CentreAngle CentreAngle
        {
            get { return centreAngle; }
            set
            {
                if(centreAngle != value)
                {
                    centreAngle = value;
                    OnPropertyChanged("CentreAngle");
                }
            }
        }

        public double VelocityOfSound
        {
            get { return velocityOfSound; }
            set
            {
                if(velocityOfSound != value)
                {
                    velocityOfSound = value;
                    OnPropertyChanged("VelocityOfSound");
                }
            }
        }

        public double Range
        {
            get { return range; }
            set
            {
                if(range != value)
                {
                    range = value;
                    OnPropertyChanged("Range");
                }
            }
        }

        public int Sectors
        {
            get { return ScanSettingsCalculator.GetNumberOfPings(arcSize, centreAngle, stepSize); }
        }

        #region Events
        public event PropertyChangedEventHandler PropertyChanged;

        protected void OnPropertyChanged(string info)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(info));
        }
        #endregion

        public ScanSettings()
        {
            ScanSettingsCalculator.SetSamplingParameters(this, 1.0, 400, 1500.0);
        }

        public bool IncrementArcSize()
        {
            if (ArcSize < ArcSize.arc360Degree)
            {
                ArcSize++;

                if (ScanSettingsCalculator.VerifyCentreAngle(arcSize, ref centreAngle))
                    OnPropertyChanged("CentreAngle");
                return true;
            }

            return false;
        }

        public bool DecrementArcSize()
        {
            if (ArcSize > ArcSize.arc30Degree)
            {
                ArcSize--;

                if (ScanSettingsCalculator.VerifyCentreAngle(arcSize, ref centreAngle))
                    OnPropertyChanged("CentreAngle");
                return true;
            }

            return false;
        }

        public bool IncrementCentreAngle()
        {
            if (CentreAngle < CentreAngle.centre330Degree)
            {
                if (CentreAngle < CentreAngle.centre270Degree)
                    CentreAngle++;
                else if (CentreAngle == CentreAngle.centre270Degree)
                    CentreAngle = CentreAngle.centre300Degree;
                else if (CentreAngle == CentreAngle.centre300Degree)
                    CentreAngle = CentreAngle.centre330Degree;

                if (ScanSettingsCalculator.VerifyArcSize(ref arcSize, centreAngle))
                    OnPropertyChanged("ArcSize");
                return true;
            }
            return false;
        }

        public bool DecrementCentreAngle()
        {
            if (CentreAngle > CentreAngle.centre30Degree)
            {
                if (CentreAngle < CentreAngle.centre300Degree)
                    CentreAngle--;
                else if (CentreAngle == CentreAngle.centre300Degree)
                    CentreAngle = CentreAngle.centre270Degree;
                else if (CentreAngle == CentreAngle.centre330Degree)
                    CentreAngle = CentreAngle.centre300Degree;

                if (ScanSettingsCalculator.VerifyArcSize(ref arcSize, centreAngle))
                    OnPropertyChanged("ArcSize");
                return true;
            }
            return false;
        }

        public object Clone()
        {
            return new ScanSettings
            {
                Samples = this.Samples,
                Oversamples = this.Oversamples,
                StepSize = this.StepSize,
                ArcSize = this.ArcSize,
                CentreAngle = this.CentreAngle,
                PulseWidth = this.PulseWidth,
                RepeatRate = this.RepeatRate,
                SampleRate = this.SampleRate,
                TxPower = this.TxPower,
                Range = this.range,
                VelocityOfSound = this.velocityOfSound,
            };
        }
    }
}
