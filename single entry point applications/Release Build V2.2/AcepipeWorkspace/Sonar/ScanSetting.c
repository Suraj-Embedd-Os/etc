


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdint.h>
#include<stdbool.h>
#include"common_enum.h"

extern struct sonar_config_para *sonar_config;


 int16_t Sectors()
{
    return GetNumberOfPings(sonar_config->arcsize, sonar_config->centerangle, sonar_config->stepsize);
}


void ScanSettings()
{
    SetSamplingParameters(sonar_config, 1.0, 400, 1500.0);
}

 bool IncrementArcSize()
{
    if (sonar_config->arcsize < ArcSize[arc360Degree])
    {
        sonar_config->arcsize++;

        if (VerifyCentreAngle(sonar_config->arcsize, &sonar_config->centerangle))
             {

             }
        return true;
    }

    return false;
}

 bool DecrementArcSize()
{
    if (sonar_config->arcsize > ArcSize[arc30Degree])
    {
        sonar_config->arcsize--;

        if (VerifyCentreAngle(sonar_config->arcsize, &sonar_config->centerangle))
             {

            }
        return true;
    }

    return false;
}

bool IncrementCentreAngle()
{
    if (sonar_config->centerangle < CentreAngle[centre330Degree])
    {
        if (sonar_config->centerangle < CentreAngle[centre270Degree])
            sonar_config->centerangle++;
        else if (sonar_config->centerangle == CentreAngle[centre270Degree])
            sonar_config->centerangle = CentreAngle[centre300Degree];
        else if (sonar_config->centerangle == CentreAngle[centre300Degree])
            sonar_config->centerangle = CentreAngle[centre330Degree];

        if (VerifyArcSize( &sonar_config->arcsize, sonar_config->centerangle))
             {

            }
        return true;
    }
    return false;
}

bool DecrementCentreAngle()
{
    if (sonar_config->centerangle > CentreAngle[centre30Degree])
    {
        if (sonar_config->centerangle < CentreAngle[centre300Degree])
            sonar_config->centerangle--;
        else if (sonar_config->centerangle == CentreAngle[centre300Degree])
            sonar_config->centerangle = CentreAngle[centre270Degree];
        else if (sonar_config->centerangle == CentreAngle[centre330Degree])
            sonar_config->centerangle = CentreAngle[centre300Degree];

        if (VerifyArcSize(&sonar_config->arcsize, sonar_config->centerangle))
            {

            }
        return true;
    }
    return false;
}
