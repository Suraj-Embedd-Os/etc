#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED

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

enum
{
        width2us,
        width4us,
        width8us,
        width12us ,
        width16us ,
        width20us ,
		TL_width
};
 
unsigned char PulseWidth[TL_width]={'E','F','G','H','I','J'};
 
enum
{
    step09Degree,
    step18Degree,
    step27Degree,
    step36Degree ,
	TL_stepDegree
};

unsigned char StepSize[TL_stepDegree]={':',';','<','>'};

enum
{
        arc30Degree,
        arc60Degree,
        arc90Degree,
        arc120Degree,
        arc150Degree,
        arc180Degree,
        arc210Degree,
        arc240Degree,
        arc270Degree,
        arc360Degree,
		TL_arccDegree
};

unsigned char ArcSize[TL_arccDegree]={'0','1','2','3', '4','5','6','7', '8','9'};

enum
{
        centre30Degree ,
        centre60Degree ,
        centre90Degree ,
        centre120Degree,
        centre150Degree ,
        centre180Degree ,
        centre210Degree,
        centre240Degree,
        centre270Degree ,
        centre300Degree,
        centre330Degree,
		TL_centreDegree
};

unsigned char CentreAngle[TL_centreDegree]={'"','#','$','%','&','\'','(',')','*',',','.'};

enum   
{
        rate200us,
        rate500us,
        rate1ms,
        rate1p5ms,
        rate2ms, 
        rate3ms, 
        rate4ms, 
        rate5ms,
        rate7ms ,
        rate10ms, 
        rate13p3ms,
        rate18ms ,
        rate26p7ms, 
        rate36ms,
		TL_RepeatRate
};

unsigned char RepeatRate[TL_RepeatRate]={'K','L','M','N','O','P','Q','R','S','T','{','|','}','~'};

#endif
