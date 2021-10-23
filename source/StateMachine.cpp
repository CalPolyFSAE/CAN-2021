#include "StateMachine.h"
#include "AnalogObject.h"
#include "constants.h"
#include <array>
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

    //initializing 8 sensor objects
    
    AnalogObject *sensor1 = new AnalogObject(Sensor1_ADC,Sensor1_Channel);
    AnalogObject *sensor2 = new AnalogObject(Sensor2_ADC,Sensor2_Channel);
    AnalogObject *sensor3 = new AnalogObject(Sensor3_ADC,Sensor3_Channel);
    AnalogObject *sensor4 = new AnalogObject(Sensor4_ADC,Sensor4_Channel);
    AnalogObject *sensor5 = new AnalogObject(Sensor5_ADC,Sensor5_Channel);
    AnalogObject *sensor6 = new AnalogObject(Sensor6_ADC,Sensor6_Channel);
    AnalogObject *sensor7 = new AnalogObject(Sensor7_ADC,Sensor7_Channel);
    AnalogObject *sensor8 = new AnalogObject(Sensor8_ADC,Sensor8_Channel);

    //initializing 5 strain gauge objects
    AnalogObject *sensor9 = new AnalogObject(Sensor9_ADC,Sensor9_Channel);
    AnalogObject *sensor10 = new AnalogObject(Sensor10_ADC,Sensor10_Channel);
    AnalogObject *sensor11 = new AnalogObject(Sensor11_ADC,Sensor11_Channel);
    AnalogObject *sensor12 = new AnalogObject(Sensor12_ADC,Sensor12_Channel);
    AnalogObject *sensor13 = new AnalogObject(Sensor13_ADC,Sensor13_Channel);
    
    this->cansensors1 = {sensor1,sensor2,sensor3,sensor4};
    this->cansensors2 = {sensor5,sensor6,sensor7,sensor8};
    this->cansensors3 = {sensor9,sensor10,sensor11,sensor12};
    this->cansensors4 = {sensor13};

    //Apps *apps = new Apps(appsData);

    //BspdData bspdData = (BspdData){THROTTLE_ADC_1, THROTTLE_CHANNEL_1, BRAKE_PRESSURE_1_ADC, BRAKE_PRESSURE_1_CHANNEL,
    //                               BRAKE_PRESSURE_2_ADC, BRAKE_PRESSURE_2_CHANNEL};
    //Bspd *bspd = new Bspd(bspdData);
}

StateMachine *StateMachine::getInstance() {
    if(instance == 0){
        instance = new StateMachine();
    }
    return instance;
}

CANFirstSensors StateMachine::getFirstSensorsCANSensors(){
    StateMachine *s = getInstance();
    return s->cansensors1;
}

CANLastSensors StateMachine::getLastSensorsCANSensors(){
    StateMachine *s = getInstance();
    return s->cansensors2;
}

CANFourSGauges StateMachine::getFourSGaugesCANSensors(){
    StateMachine *s = getInstance();
    return s->cansensors3;
}

CANLastSGauge StateMachine::getLastSGaugeCANSensors(){
    StateMachine *s = getInstance();
    return s->cansensors4;
}


void StateMachine::readSensorsAdcValues() {
    StateMachine *s = getInstance();
    s->cansensors1.sensor1->readValues();
    s->cansensors1.sensor2->readValues();
    s->cansensors1.sensor3->readValues();
    s->cansensors1.sensor4->readValues();
}

void StateMachine::readLastSensorsAdcValues() {
    StateMachine *s = getInstance();

    s->cansensors2.sensor5->readValues();
    s->cansensors2.sensor6->readValues();
    s->cansensors2.sensor7->readValues();
    s->cansensors2.sensor8->readValues();
}

void StateMachine::readFirstSGaugesAdcValues() {
    StateMachine *s = getInstance();

    s->cansensors3.sensor9->readValues();
    s->cansensors3.sensor10->readValues();
    s->cansensors3.sensor11->readValues();
    s->cansensors3.sensor12->readValues();
}

void StateMachine::readLastSGaugeAdcValues() {
    StateMachine *s = getInstance();

    s->cansensors4.sensor13->readValues();
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




