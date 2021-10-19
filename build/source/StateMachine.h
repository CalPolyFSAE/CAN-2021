#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "AnalogObject.h"
//#include "Apps.h"
//#include "Bspd.h"

/*
typedef struct{
    //AnalogObject *brakePressure;
    //AnalogObject *throttle;
    AnalogObject *sensor1;
    AnalogObject *sensor2;
    AnalogObject *sensor3;
    AnalogObject *sensor4;
    //Apps *apps;
    //Bspd *bspd;
}CANFirstSensors;

typedef struct{
    //AnalogObject *brakePressure;
    //AnalogObject *throttle;
    AnalogObject *sensor5;
    AnalogObject *sensor6;
    AnalogObject *sensor7;
    AnalogObject *sensor8;
    //Apps *apps;
    //Bspd *bspd;
}CANLastSensors;

typedef struct{
    AnalogObject *sensor9;
    AnalogObject *sensor10;
    AnalogObject *sensor11;
    AnalogObject *sensor12;
}CANFourSGauges;

typedef struct{
    AnalogObject *sensor13;
}CANLastSGauge;
*/




class StateMachine {
public:
    static void readSensorsAdcValues();
    static StateMachine *getInstance();
    static AnalogObject * getSensors();
    static AnalogObject *  getSGauges();
    static AnalogObject ADC_sensors[8];
    static AnalogObject sgauges[5];
    /*
    static void readFirstSensorsAdcValues();
    static void readLastSensorsAdcValues();
    static void readFirstSGaugesAdcValues();
    static void readLastSGaugeAdcValues();
    //static PedalboxFaults getFaults();
    static CANFirstSensors getFirstSensorsCANSensors();
    static CANLastSensors getLastSensorsCANSensors();
    static CANFourSGauges getFourSGaugesCANSensors();
    static CANLastSGauge getLastSGaugeCANSensors();
    */
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

    /*CANFirstSensors cansensors1;
    CANLastSensors cansensors2;
    CANFourSGauges cansensors3;
    CANLastSGauge cansensors4;*/
    //PedalboxFaults pedalboxFaults;
};


#endif //STATEMACHINE_H
