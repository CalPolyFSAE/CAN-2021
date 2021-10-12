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

CanMessage* CanMessage::getInstance() {
    if(instance == 0){
        instance = new CanMessage();
        instance->initCan();
    }
    return instance;
}

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

void CanMessage::sendTimeHelper(){
    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID;
    frame.ext = 1;
    frame.dlc = 8;
    uint64_t currentTime = xTaskGetTickCount();
    memcpy(frame.data, &currentTime, sizeof(frame.data));
    can.tx(CAN_BUS, frame);
}

void CanMessage::sendHunHzHelper(){
    CANSensors canSensors = StateMachine::getCANSensors();
    HundredHzstruct canStruct;

    canStruct.AnalogData5 = canSensors.sensor5->pin_data_1;
    canStruct.AnalogData6 = canSensors.sensor6->pin_data_1;
    canStruct.AnalogData7 = canSensors.sensor7->pin_data_1;
    canStruct.AnalogData8 = 0;

    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID;
    frame.ext = 1;
    frame.dlc = 8;
    memcpy(frame.data, &canStruct, sizeof(HundredHzstruct));
    can.tx(CAN_BUS, frame);
    can::CANlight::frame fHun = can.readrx(1);
}
void CanMessage::sendSixtyHzHelper(){
    CANSensors canSensors = StateMachine::getCANSensors();
    SixtyHzstruct canStruct;

    canStruct.AnalogData1 = canSensors.sensor1->pin_data_1;
    canStruct.AnalogData2 = canSensors.sensor2->pin_data_1;
    canStruct.AnalogData3 = canSensors.sensor3->pin_data_1;
    canStruct.AnalogData4 = 0;

    can::CANlight &can = can::CANlight::StaticClass();
    can::CANlight::frame frame;
    frame.id = CAN_ID;
    frame.ext = 1;
    frame.dlc = 8;
    memcpy(frame.data, &canStruct, sizeof(SixtyHzstruct));
    can.tx(CAN_BUS, frame);
    can::CANlight::frame fSixty = can.readrx(1);
}


void CanMessage::sendTime() {
    CanMessage *c = CanMessage::getInstance();
    c->sendTimeHelper();
}

void CanMessage::sendSixtyHz() {
    CanMessage *c = CanMessage::getInstance();
    c->sendSixtyHzHelper();
}
void CanMessage::sendHunHz() {
    CanMessage *c = CanMessage::getInstance();
    c->sendHunHzHelper();
}


