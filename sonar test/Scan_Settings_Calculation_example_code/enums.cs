using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PipeProfiler3
{
    public enum CommResult : byte
    {
        Success = 0,
        Timeout = 1,
        BadChecksum = 2,
        InvalidResponse = 3,
        Failed = 4
    }

    public enum ProfilerFileType
    {
        IMG = 0,
        IMG2 = 1,
        IMG3 = 2,
        PST = 3,
    }

    public enum CableCounterType
    {
        None,
        OnBoard,
    }

    public enum UWUType
    {
        None = 0,
        Profiler1512 = 1,
        Profiler2512 = 2,
    }

    public enum ActiveTool
    {
        None,
        MeasurementLine,
        MeasurementCircle,
        Profile,
    }

    public enum PulseWidth : byte
    {
        width2us = (byte)'E',
        width4us = (byte)'F',
        width8us = (byte)'G',
        width12us = (byte)'H',
        width16us = (byte)'I',
        width20us = (byte)'J'
    }

    public enum StepSize : byte
    {
        step09Degree = (byte)':',
        step18Degree = (byte)';',
        step27Degree = (byte)'<',
        step36Degree = (byte)'>'
    }

    public enum ArcSize : byte
    {
        arc30Degree = (byte)'0',
        arc60Degree = (byte)'1',
        arc90Degree = (byte)'2',
        arc120Degree = (byte)'3',
        arc150Degree = (byte)'4',
        arc180Degree = (byte)'5',
        arc210Degree = (byte)'6',
        arc240Degree = (byte)'7',
        arc270Degree = (byte)'8',
        arc360Degree = (byte)'9'
    }

    public enum CentreAngle : byte
    {
        centre30Degree = (byte)'"',
        centre60Degree = (byte)'#',
        centre90Degree = (byte)'$',
        centre120Degree = (byte)'%',
        centre150Degree = (byte)'&',
        centre180Degree = (byte)'\'',
        centre210Degree = (byte)'(',
        centre240Degree = (byte)')',
        centre270Degree = (byte)'*',
        centre300Degree = (byte)',',
        centre330Degree = (byte)'.'
    }

    public enum RepeatRate : byte
    {
        rate200us = (byte)'K',
        rate500us = (byte)'L',
        rate1ms = (byte)'M',
        rate1p5ms = (byte)'N',
        rate2ms = (byte)'O',
        rate3ms = (byte)'P',
        rate4ms = (byte)'Q',
        rate5ms = (byte)'R',
        rate7ms = (byte)'S',
        rate10ms = (byte)'T',
        rate13p3ms = (byte)'{',
        rate18ms = (byte)'|',
        rate26p7ms = (byte)'}',
        rate36ms = (byte)'~'
    }
}
