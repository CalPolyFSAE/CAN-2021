#include "StateMachine.h"
#include "AnalogObject.h"
#include "constants.h"
/*#include "main.h"
#include "Apps.h"
#include "Bspd.h"
#include "Functions.h"*/

StateMachine *StateMachine::instance;

StateMachine::StateMachine() {
    pedalboxFaults = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    //AnalogObjectData not needed at all
    AnalogObjectData throttleData = (AnalogObjectData){THROTTLE_ADC_1, THROTTLE_CHANNEL_1,
                                                       THROTTLE_ADC_1, THROTTLE_CHANNEL_1};
    AnalogObject *throttle = new AnalogObject(throttleData);

    AnalogObjectData brakePressureData = (AnalogObjectData){BRAKE_PRESSURE_1_ADC, BRAKE_PRESSURE_1_CHANNEL,
                                                            BRAKE_PRESSURE_2_ADC, BRAKE_PRESSURE_2_CHANNEL};
    AnalogObject *brakePressure = new AnalogObject(brakePressureData);

    AnalogObjectData appsData = (AnalogObjectData){APPS_1_ADC, APPS_1_Channel,
                                                   APPS_2_ADC, APPS_2_Channel};
    //Apps *apps = new Apps(appsData);

    //BspdData bspdData = (BspdData){THROTTLE_ADC_1, THROTTLE_CHANNEL_1, BRAKE_PRESSURE_1_ADC, BRAKE_PRESSURE_1_CHANNEL,
                                   BRAKE_PRESSURE_2_ADC, BRAKE_PRESSURE_2_CHANNEL};
    //Bspd *bspd = new Bspd(bspdData);

    this->pedalBoxSensors = {brakePressure, throttle, apps, bspd};
}

StateMachine *StateMachine::getInstance() {
    if(instance == 0){
        instance = new StateMachine();
    }
    return instance;
}

PedalBoxSensors StateMachine::getPedalboxSensors(){
    StateMachine *s = getInstance();
    return s->pedalBoxSensors;
}

void StateMachine::readAdcValues() {
    StateMachine *s = getInstance();

    s->pedalBoxSensors.brakePressure->readValues();
    s->pedalBoxSensors.throttle->readValues();
    s->pedalBoxSensors.apps->readValues();
}

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
}




