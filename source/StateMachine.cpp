#include "StateMachine.h"
#include "AnalogObject.h"
#include "constants.h"
/*#include "main.h"
#include "Apps.h"
#include "Bspd.h"
#include "Functions.h"*/

StateMachine *StateMachine::instance;

StateMachine::StateMachine() {
    //pedalboxFaults = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    //AnalogObjectData not needed at all
    /*AnalogObjectData throttleData = (AnalogObjectData){THROTTLE_ADC_1, THROTTLE_CHANNEL_1,
                                                       THROTTLE_ADC_1, THROTTLE_CHANNEL_1};
    AnalogObject *throttle = new AnalogObject(throttleData);*/

    AnalogObject *sensor1 = new AnalogObject(Sensor1_ADC,Sensor1_Channel);
    AnalogObject *sensor2 = new AnalogObject(Sensor2_ADC,Sensor2_Channel);
    AnalogObject *sensor3 = new AnalogObject(Sensor3_ADC,Sensor3_Channel);
    AnalogObject *sensor4 = new AnalogObject(Sensor4_ADC,Sensor4_Channel);
    AnalogObject *sensor5 = new AnalogObject(Sensor5_ADC,Sensor5_Channel);
    AnalogObject *sensor6 = new AnalogObject(Sensor6_ADC,Sensor6_Channel);
    AnalogObject *sensor7 = new AnalogObject(Sensor7_ADC,Sensor7_Channel);
    AnalogObject *sensor8 = new AnalogObject(Sensor8_ADC,Sensor8_Channel);

    

    
    //Apps *apps = new Apps(appsData);

    //BspdData bspdData = (BspdData){THROTTLE_ADC_1, THROTTLE_CHANNEL_1, BRAKE_PRESSURE_1_ADC, BRAKE_PRESSURE_1_CHANNEL,
    //                               BRAKE_PRESSURE_2_ADC, BRAKE_PRESSURE_2_CHANNEL};
    //Bspd *bspd = new Bspd(bspdData);

    this->cansensors = {sensor1,sensor2,sensor3,sensor4,sensor5,sensor6,sensor7,sensor8};
}

StateMachine *StateMachine::getInstance() {
    if(instance == 0){
        instance = new StateMachine();
    }
    return instance;
}

CANSensors StateMachine::getCANSensors(){
    StateMachine *s = getInstance();
    return s->cansensors;
}

void StateMachine::readAdcValues() {
    StateMachine *s = getInstance();

    s->cansensors.sensor1->readValues();
<<<<<<< HEAD
    s->cansensors.sensor2->readValues();
    s->cansensors.sensor3->readValues();
    s->cansensors.sensor4->readValues();
    s->cansensors.sensor5->readValues();
    s->cansensors.sensor6->readValues();
    s->cansensors.sensor7->readValues();
    s->cansensors.sensor8->readValues();
=======
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
    s->cansensors.sensor1->readValues();
>>>>>>> 10775e88639ac53ba13eed7406d6228e763e0706
}

/*
void StateMachine::checkFaults() {
    StateMachine *s = getInstance();

    Apps *apps = s->pedalBoxSensors.apps;
    AnalogObject *brakePressure = s->pedalBoxSensors.brakePressure;
    Bspd *bspd = s->pedalBoxSensors.bspd;

    appsBrakePlausibilityCheck(&(s->pedalboxFaults), apps->pin_data_1, apps->pin_data_2, brakePressure->pin_data_1, brakePressure->pin_data_2);
    apps->checkVoltDiff(&(s->pedalboxFaults));
    //bspd->checkBspdFault(&(s->pedalboxFaults));
}

PedalboxFaults StateMachine::getFaults() {
    StateMachine *s = getInstance();
    return s->pedalboxFaults;
}

void StateMachine::setBspdInfoTrue() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.bspdInfo = 1;
    s->pedalboxFaults.bspdInfoHist = 1;
}

void StateMachine::setBspdInfoFalse() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.bspdInfo = 0;
}

void StateMachine::setBspdCriticalTrue() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.bspdCritical = 1;
    s->pedalboxFaults.bspdCriticalHist = 1;
}

void StateMachine::setBspdCriticalFalse() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.bspdCritical = 0;
}

void StateMachine::setOverUnderVoltageInfoTrue() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.overUnderVoltageInfo = 1;
    s->pedalboxFaults.overUnderVoltageInfoHist = 1;
}

void StateMachine::setOverUnderVoltageInfoFalse() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.overUnderVoltageInfo = 0;
}

void StateMachine::setOverUnderVoltageCriticalTrue() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.overUnderVoltageCritical = 1;
    s->pedalboxFaults.overUnderVoltageCriticalHist = 1;
}

void StateMachine::setOverUnderVoltageCriticalFalse() {
    StateMachine *s = getInstance();
    s->pedalboxFaults.overUnderVoltageCritical = 0;
}*/




