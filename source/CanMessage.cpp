//#include "CanMessage.h"
#include "FreeRTOS.h"
#include "task.h"
#include "can.h"
#include "constants.h"
#include "StateMachine.h"
#include "canmessagestructs.h"

using namespace BSP;

//initializes various CAN settings
void initCan()
{
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
