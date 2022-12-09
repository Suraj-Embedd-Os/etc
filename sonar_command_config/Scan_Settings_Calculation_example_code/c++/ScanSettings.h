#ifndef SCANSETTINGS_H_INCLUDED
#define SCANSETTINGS_H_INCLUDED


#include"enum.h"
#include "ScanSettingCalculator.h"
#include<stdbool.h>
#include<iostream>
#include<stdint.h>
#include<math.h>



class ScanSettings : public ScanSettingsCalculator
    {
		public:
        double range = 1.0;
        double velocityOfSound = 1500.0;

        uint16_t samples = 400;
        uint8_t oversamples = 1;
        uint16_t sampleRate = 200;
        unsigned char pulseWidth = PulseWidth[width2us];
        uint8_t txPower = 4;
        unsigned char repeatRate = RepeatRate[rate7ms];
        unsigned char stepSize = StepSize[step09Degree];
        unsigned char arcSize = ArcSize[arc360Degree];
        unsigned char centreAngle = CentreAngle[centre180Degree];

         uint16_t getSamples() const{ return samples; }
         void  setSamples(uint16_t value)
            {
                if(samples != value)
                {
                    samples = value;
                    OnPropertyChanged("Samples");
                }
            }


        /// <summary>
        /// Oversamples
        /// </summary>
         uint8_t getOversamples() const{ return oversamples; }
         void  setOversamples(uint8_t value)
            {
                if (oversamples != value)
                {
                    oversamples = value;
                   // OnPropertyChanged("Oversamples");
                }
            }

        /// <summary>
        /// Sample rate in ns to the nearest 20ns
        /// </summary>
         uint16_t getSampleRate()const { return sampleRate; }
         void  setSampleRate(uint16_t value)
            {
                if(sampleRate != value)
                {
                    sampleRate = value;
                   // OnPropertyChanged("SampleRate");
                }
            }


        /// <summary>
        /// Pulse width (enum)
        /// </summary>
         unsigned char getPulseWidth() const { return pulseWidth; }
         void  setPulseWidth(unsigned char value )
            {
                if (pulseWidth != value)
                {
                    pulseWidth = value;
                    //OnPropertyChanged("PulseWidth");
                }
            }


        /// <summary>
        /// Transmit power (0 - 7) min to max
        /// </summary>
         uint8_t getTxPower()const { return txPower; }
         void   setTxPower(uint8_t value)
            {
                if(txPower != value)
                {
                    txPower = value;
                    //OnPropertyChanged("TxPower");
                }
            }


        /// <summary>
        /// Repeat Rate. Time between pings during a sweep. (enum)
        /// </summary>
         unsigned char getRepeatRate()const { return repeatRate; }
         void  setRepeatRate(unsigned char value)
            {
                if(repeatRate != value)
                {
                    repeatRate = value;
                    //OnPropertyChanged("RepeatRate");
                }
            }


        /// <summary>
        /// Step Size (enum)
        /// </summary>
         unsigned char getStepSize()const{ return stepSize; }
         void   setStepSize(unsigned char value)
            {
                if(stepSize != value)
                {
                    stepSize = value;
                    //OnPropertyChanged("StepSize");
                }
            }


         unsigned char getArcSize()const { return arcSize; }
           void setArcSize(unsigned char value)
            {
                if (arcSize != value)
                {
                    arcSize = value;
                    //OnPropertyChanged("ArcSize");
                }
            }


         unsigned char getCentreAngle()const { return centreAngle; }
         void setCentreAngle(unsigned char value)
            {
                if(centreAngle != value)
                {
                    centreAngle = value;
                    //OnPropertyChanged("CentreAngle");
                }
            }


         double getVelocityOfSound()const{ return velocityOfSound; }
          void  setVelocityOfSound(double value)
            {
                if(velocityOfSound != value)
                {
                    velocityOfSound = value;
                    OnPropertyChanged("VelocityOfSound");
                }
            }


         double getRange()const { return range; }
          void  setRange(double value)
            {
                if(range != value)
                {
                    range = value;
                    OnPropertyChanged("Range");
                }
            }


         int Sectors
        {
              return GetNumberOfPings(arcSize, centreAngle, stepSize);
        }

        //region Events
         event PropertyChangedEventHandler PropertyChanged;

         void OnPropertyChanged(string info)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(info));
        }
        //endregion

         ScanSettings()
        {
            SetSamplingParameters(this, 1.0, 400, 1500.0);
        }

         bool IncrementArcSize()
        {
			static int _arcSize=arc360Degree;
            if (arcSize < ArcSize[arc360Degree])
            {
                ArcSize++;

                if (VerifyCentreAngle(arcSize,  centreAngle))
                    OnPropertyChanged("CentreAngle");
                return true;
            }

            return false;
        }

         bool DecrementArcSize()
        {
            if (ArcSize > ArcSize.arc30Degree)
            {
                ArcSize--;

                if (VerifyCentreAngle(arcSize,centreAngle))
                    OnPropertyChanged("CentreAngle");
                return true;
            }

            return false;
        }

         bool IncrementCentreAngle()
        {
            if (CentreAngle < CentreAngle.centre330Degree)
            {
                if (CentreAngle < CentreAngle.centre270Degree)
                    CentreAngle++;
                else if (CentreAngle == CentreAngle.centre270Degree)
                    CentreAngle = CentreAngle.centre300Degree;
                else if (CentreAngle == CentreAngle.centre300Degree)
                    CentreAngle = CentreAngle.centre330Degree;

                if (VerifyArcSize(arcSize, centreAngle))
                    OnPropertyChanged("ArcSize");
                return true;
            }
            return false;
        }

         bool DecrementCentreAngle()
        {
            if (CentreAngle > CentreAngle.centre30Degree)
            {
                if (CentreAngle < CentreAngle.centre300Degree)
                    CentreAngle--;
                else if (CentreAngle == CentreAngle.centre300Degree)
                    CentreAngle = CentreAngle.centre270Degree;
                else if (CentreAngle == CentreAngle.centre330Degree)
                    CentreAngle = CentreAngle.centre300Degree;

                if (VerifyArcSize( arcSize, centreAngle)
                    OnPropertyChanged("ArcSize");
                return true;
            }
            return false;
        }

         object Clone()
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
    };



#endif // SCANSETTINGS_H_INCLUDED
