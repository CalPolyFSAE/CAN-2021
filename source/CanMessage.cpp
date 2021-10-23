#include "CanMessage.h"
#include "FreeRTOS.h"
#include "task.h"
#include "can.h"
#include "constants.h"
#include "StateMachine.h"
#include "CanMessageStructs.h"

using namespace BSP;

CanMessage* CanMessage::instance;

CanMessage::CanMessage(){}

// returns CanMessage object
CanMessage* CanMessage::getInstance() {
    if(instance == 0){
        instance = new CanMessage();
        instance->initCan();
    }
    return instance;
}

//initializes various CAN settings
void CanMessage::initCan() {
    can::can_config config;
    can::CANlight::canx_config canx_config;

    // Initialize CAN driver
    can::CANlight::ConstructStatic(&config);
    can::CANlight &can = can::CANlight::StaticClass();

    // Configure CAN bus
    canx_config.baudRate = CAN_BAUD_RATE;
    can.init(CAN_BUS, &canx_config);
    can.init(1, &canx_config);
}

//Helper function which sends a time value as a Can Message for each instance of logged data
void CanMessage::sendTimeHelper(){
    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID_TIME;
    frame.ext = 1;
    frame.dlc = 8;
    uint64_t currentTime = xTaskGetTickCount();
    memcpy(frame.data, &currentTime, sizeof(frame.data));
    can.tx(CAN_BUS, frame);
}

//Helper function which sends CAN message of 8 sensor values
void CanMessage::sendSensorsHelper(){
    CANFirstSensors cansensors1 = StateMachine::getFirstSensorsCANSensors();
    CANLastSensors cansensors2 = StateMachine::getLastSensorsCANSensors();
    FirstSensorsStruct canStruct;
    LastSensorsStruct canLastStruct;

    canStruct.AnalogData1 = cansensors1.sensor1->pin_data_1;
    canStruct.AnalogData2 = cansensors1.sensor2->pin_data_1;
    canStruct.AnalogData3 = cansensors1.sensor3->pin_data_1;
    canStruct.AnalogData4 = cansensors1.sensor4->pin_data_1;;

    canLastStruct.AnalogData5 = cansensors2.sensor5->pin_data_1;
    canLastStruct.AnalogData6 = cansensors2.sensor6->pin_data_1;
    canLastStruct.AnalogData7 = cansensors2.sensor7->pin_data_1;
    canLastStruct.AnalogData8 = cansensors2.sensor8->pin_data_1;
    

    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame1;
    frame1.id = CAN_ID_TIME+1;
    frame1.ext = 1;
    frame1.dlc = 8;
    memcpy(frame1.data, &canStruct, sizeof(canStruct));
    can.tx(CAN_BUS, frame1);

    can::CANlight &can1 = can::CANlight::StaticClass();
    can::CANlight::frame frame2;
    frame2.id = CAN_ID_TIME+2;
    frame2.ext = 1;
    frame2.dlc = 8;
    memcpy(frame2.data, &canLastStruct, sizeof(canLastStruct));
    can.tx(CAN_BUS, frame2);
}

//Sends CAN message of the first 4 gauges. limited to 4 data values per Can message.
// (CAN message data field limited to 8 bytes, each data value is 2 bytes)
void CanMessage::sendFourSGaugesHelper(){
    CANFourSGauges cansensors3 = StateMachine::getFourSGaugesCANSensors();
    FourSGaugeStruct canFourSGaugesStruct;

    canFourSGaugesStruct.AnalogData9 = cansensors3.sensor9->pin_data_1;
    canFourSGaugesStruct.AnalogData10 = cansensors3.sensor10->pin_data_1;
    canFourSGaugesStruct.AnalogData11 = cansensors3.sensor11->pin_data_1;
    canFourSGaugesStruct.AnalogData12 = cansensors3.sensor12->pin_data_1;

    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID_TIME+3;
    frame.ext = 1;
    frame.dlc = 8;
    memcpy(frame.data, &canFourSGaugesStruct, sizeof(canFourSGaugesStruct));
    can.tx(CAN_BUS, frame);
    can::CANlight::frame fHun = can.readrx(1);
}

//Sends CAN message for the data of the fifth strain gauge
void CanMessage::sendLastSGaugeHelper(){
    CANLastSGauge cansensors4 = StateMachine::getLastSGaugeCANSensors();
    LastSGaugeStruct canLastSGaugeStruct;

    canLastSGaugeStruct.AnalogData13 = cansensors4.sensor13->pin_data_1;

    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID_TIME+4;
    frame.ext = 1;
    frame.dlc = 8;
    memcpy(frame.data, &canLastSGaugeStruct, sizeof(cansensors4));
    can.tx(CAN_BUS, frame);
    can::CANlight::frame fHun = can.readrx(1);
}

//The following are public functions which call private helper functions to send CAN messages

void CanMessage::sendTime() {
    CanMessage *c = CanMessage::getInstance();
    c->sendTimeHelper();
}


void CanMessage::sendSensors() {
    CanMessage *c = CanMessage::getInstance();
    c->sendSensorsHelper();
}

void CanMessage::sendFourSGauges() {
    CanMessage *c = CanMessage::getInstance();
    c->sendFourSGaugesHelper();
}

void CanMessage::sendLastSGauge() {
    CanMessage *c = CanMessage::getInstance();
    c->sendLastSGaugeHelper();
}


