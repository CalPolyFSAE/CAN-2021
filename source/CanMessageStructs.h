
#ifndef CANMESSAGESTRUCTS_H
#define CANMESSAGESTRUCTS_H
#include "MKE18F16.h"

//the 2 structs below are for the 8 sensors. Allocating 16 bits for each sensor (each voltage message/reading takes in 12 bits.)

typedef struct{
    uint16_t AnalogData1;
    uint16_t AnalogData2;
    uint16_t AnalogData3;
    uint16_t AnalogData4;
}BrakePresThrottleAndFaultsCanstruct;

typedef struct{
    uint16_t AnalogData5;
    uint16_t AnalogData6;
    uint16_t AnalogData7;
    uint16_t AnalogData8;
}BrakePresThrottleAndFaultsCanstruct;



typedef struct{
    uint16_t AppsPin1;
    uint16_t AppsPin2;
}AppsCanstruct;

#endif //CANMESSAGESTRUCTS_H