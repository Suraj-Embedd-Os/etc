#ifndef ENUM_H_INCLUDED
#define ENUM_H_INCLUDED
enum class CommResult : unsigned char
{
	Success = 0,
    Timeout = 1,
    BadChecksum = 2,
    InvalidResponse = 3,
    Failed = 4

};

enum class ProfilerFileType
{
        IMG = 0,
        IMG2 = 1,
        IMG3 = 2,
        PST = 3,
};


enum class CableCounterType
{
        None,
        OnBoard,
};

enum class UWUType
 {
        None = 0,
        Profiler1512 = 1,
        Profiler2512 = 2,
};

 enum  class ActiveTool
 {
        None,
        MeasurementLine,
        MeasurementCircle,
        Profile,
 };

enum class PulseWidth : unsigned char
{
        width2us = (unsigned char)'E',
        width4us = (unsigned char)'F',
        width8us = (unsigned char)'G',
        width12us = (unsigned char)'H',
        width16us = (unsigned char)'I',
        width20us = (unsigned char)'J'
};

 enum class StepSize : unsigned char
{
        step09Degree = (unsigned char)':',
        step18Degree = (unsigned char)';',
        step27Degree = (unsigned char)'<',
        step36Degree = (unsigned char)'>'
};

 enum class ArcSize : unsigned char
{
        arc30Degree = (unsigned char)'0',
        arc60Degree = (unsigned char)'1',
        arc90Degree = (unsigned char)'2',
        arc120Degree = (unsigned char)'3',
        arc150Degree = (unsigned char)'4',
        arc180Degree = (unsigned char)'5',
        arc210Degree = (unsigned char)'6',
        arc240Degree = (unsigned char)'7',
        arc270Degree = (unsigned char)'8',
        arc360Degree = (unsigned char)'9'
};

 enum class CentreAngle : unsigned char
 {
        centre30Degree = (unsigned char)'"',
        centre60Degree = (unsigned char)'#',
        centre90Degree = (unsigned char)'$',
        centre120Degree = (unsigned char)'%',
        centre150Degree = (unsigned char)'&',
        centre180Degree = (unsigned char)'\'',
        centre210Degree = (unsigned char)'(',
        centre240Degree = (unsigned char)')',
        centre270Degree = (unsigned char)'*',
        centre300Degree = (unsigned char)',',
        centre330Degree = (unsigned char)'.'
};

 enum class RepeatRate : unsigned char
{
        rate200us = (unsigned char)'K',
        rate500us = (unsigned char)'L',
        rate1ms = (unsigned char)'M',
        rate1p5ms = (unsigned char)'N',
        rate2ms = (unsigned char)'O',
        rate3ms = (unsigned char)'P',
        rate4ms = (unsigned char)'Q',
        rate5ms = (unsigned char)'R',
        rate7ms = (unsigned char)'S',
        rate10ms = (unsigned char)'T',
        rate13p3ms = (unsigned char)'{',
        rate18ms = (unsigned char)'|',
        rate26p7ms = (unsigned char)'}',
        rate36ms = (unsigned char)'~'
};

#endif
