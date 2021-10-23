
#ifndef CANMESSAGESTRUCTS_H
#define CANMESSAGESTRUCTS_H
#include "MKE18F16.h"

//the struct below is for the 8 sensors and 5 strain gauges. Allocating 16 bits (2 bytes) for each sensor (each voltage message/reading takes in 12 bits.)

typedef struct{
    uint16_t AnalogData1;
    uint16_t AnalogData2;
    uint16_t AnalogData3;
    uint16_t AnalogData4;
}FirstSensorsStruct; //HundredHzStruct

typedef struct 
{
    uint16_t AnalogData5;
    uint16_t AnalogData6;
    uint16_t AnalogData7;
    uint16_t AnalogData8;
}LastSensorsStruct;

typedef struct 
{
    uint16_t AnalogData9;
    uint16_t AnalogData10;
    uint16_t AnalogData11;
    uint16_t AnalogData12;
}FourSGaugeStruct;

typedef struct
{
    uint16_t AnalogData13;
}LastSGaugeStruct;



//no longer necessary since all data will be collected at 100 Hz
/*
typedef struct{
    uint16_t AnalogData1;
    uint16_t AnalogData2;
    uint16_t AnalogData3;
    uint16_t AnalogData4;
}SixtyHzstruct; */

#endif //CANMESSAGESTRUCTS_H