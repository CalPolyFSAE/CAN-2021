#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "AnalogObject.h"
//#include "Apps.h"
//#include "Bspd.h"

typedef struct{
    //AnalogObject *brakePressure;
    //AnalogObject *throttle;
    AnalogObject *sensor1;
    AnalogObject *sensor2;
    AnalogObject *sensor3;
    AnalogObject *sensor4;
    AnalogObject *sensor5;
    AnalogObject *sensor6;
    AnalogObject *sensor7;
    AnalogObject *sensor8;
    //Apps *apps;
    //Bspd *bspd;
}CANSensors;

class StateMachine {
public:
    static void readAdcValues();
    static PedalboxFaults getFaults();
    static PedalBoxSensors getPedalboxSensors();
    static void setBspdInfoTrue();
    static void setBspdInfoFalse();
    static void setBspdCriticalTrue();
    static void setBspdCriticalFalse();
    static void checkFaults();
    static void setOverUnderVoltageInfoTrue();
    static void setOverUnderVoltageInfoFalse();
    static void setOverUnderVoltageCriticalTrue();
    static void setOverUnderVoltageCriticalFalse();

private:
    StateMachine();
    static StateMachine *instance;
    static StateMachine *getInstance();
    CANSensors cansensors;
    PedalboxFaults pedalboxFaults;
};


#endif //STATEMACHINE_H
