#include "StateMachine.h"
#include "AnalogObject.h"
#include "constants.h"
#include <array>
/*#include "main.h"
#include "Apps.h"
#include "Bspd.h"
#include "Functions.h"*/

StateMachine *StateMachine::instance;

StateMachine::StateMachine()
{

    // Initializing 8 sensor objects

    AnalogObject *sensor1 = new AnalogObject(Sensor1_ADC, Sensor1_Channel);
    AnalogObject *sensor2 = new AnalogObject(Sensor2_ADC, Sensor2_Channel);
    AnalogObject *sensor3 = new AnalogObject(Sensor3_ADC, Sensor3_Channel);
    AnalogObject *sensor4 = new AnalogObject(Sensor4_ADC, Sensor4_Channel);
    AnalogObject *sensor5 = new AnalogObject(Sensor5_ADC, Sensor5_Channel);
    AnalogObject *sensor6 = new AnalogObject(Sensor6_ADC, Sensor6_Channel);
    AnalogObject *sensor7 = new AnalogObject(Sensor7_ADC, Sensor7_Channel);
    AnalogObject *sensor8 = new AnalogObject(Sensor8_ADC, Sensor8_Channel);

    // Initializing 5 strain gauge objects
    AnalogObject *sensor9 = new AnalogObject(Sensor9_ADC, Sensor9_Channel);
    AnalogObject *sensor10 = new AnalogObject(Sensor10_ADC, Sensor10_Channel);
    AnalogObject *sensor11 = new AnalogObject(Sensor11_ADC, Sensor11_Channel);
    AnalogObject *sensor12 = new AnalogObject(Sensor12_ADC, Sensor12_Channel);
    AnalogObject *sensor13 = new AnalogObject(Sensor13_ADC, Sensor13_Channel);

    // Initializing 4 statemachine objects
    this->cansensors1 = {sensor1, sensor2, sensor3, sensor4};
    this->cansensors2 = {sensor5, sensor6, sensor7, sensor8};
    this->cansensors3 = {sensor9, sensor10, sensor11, sensor12};
    this->cansensors4 = {sensor13};
}

// Returns singleton instance of StateMachine
StateMachine *StateMachine::getInstance()
{
    if (instance == 0)
    {
        instance = new StateMachine();
    }
    return instance;
}

// 4 get functions below return statemachine data for corresponding sensor/strain gauge
CANFirstSensors StateMachine::getFirstSensorsCANSensors()
{
    StateMachine *s = getInstance();
    return s->cansensors1;
}

CANLastSensors StateMachine::getLastSensorsCANSensors()
{
    StateMachine *s = getInstance();
    return s->cansensors2;
}

CANFourSGauges StateMachine::getFourSGaugesCANSensors()
{
    StateMachine *s = getInstance();
    return s->cansensors3;
}

CANLastSGauge StateMachine::getLastSGaugeCANSensors()
{
    StateMachine *s = getInstance();
    return s->cansensors4;
}

// 4 read methods below read in data for each corresponding sensor/strain gauge
void StateMachine::readSensorsAdcValues()
{
    StateMachine *s = getInstance();
    s->cansensors1.sensor1->readValues();
    s->cansensors1.sensor2->readValues();
    s->cansensors1.sensor3->readValues();
    s->cansensors1.sensor4->readValues();
}

void StateMachine::readLastSensorsAdcValues()
{
    StateMachine *s = getInstance();

    s->cansensors2.sensor5->readValues();
    s->cansensors2.sensor6->readValues();
    s->cansensors2.sensor7->readValues();
    s->cansensors2.sensor8->readValues();
}

void StateMachine::readFirstSGaugesAdcValues()
{
    StateMachine *s = getInstance();

    s->cansensors3.sensor9->readValues();
    s->cansensors3.sensor10->readValues();
    s->cansensors3.sensor11->readValues();
    s->cansensors3.sensor12->readValues();
}

void StateMachine::readLastSGaugeAdcValues()
{
    StateMachine *s = getInstance();

    s->cansensors4.sensor13->readValues();
}