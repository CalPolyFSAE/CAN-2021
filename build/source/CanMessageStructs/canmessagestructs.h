#ifndef CANMESSAGESTRUCTS_H
#define CANMESSAGESTRUCTS_H

// id 123456
typedef struct {
    uint8_t voltage_pin_1; // Can use any intx_t uintx_t char bool etc
    uint32_t big_value;
    uint8_t voltage_pin_2;
    uint8_t voltage_pin_3;
    uint8_t voltage_pin_4;
} Example;  // Must be 64 bits

//4 adc values percanmsgstruct
typedef struct {
    uint8_t voltage_channel_1; // Can use any intx_t uintx_t char bool etc
    uint8_t voltage_channel_2;
    uint8_t voltage_channel_3;
    uint8_t voltage_channel_4;
    uint8_t voltage_channel_5; // Can use any intx_t uintx_t char bool etc
    uint8_t voltage_channel_6;
    uint8_t voltage_channel_7;
    uint8_t voltage_channel_8;
} VoltageData;  // Must be 64 bits

typedef struct {
    uint8_t current_channel_1; // Can use any intx_t uintx_t char bool etc
    uint8_t current_channel_2;
    uint8_t current_channel_3;
    uint8_t current_channel_4;
    uint8_t current_channel_5; // Can use any intx_t uintx_t char bool etc
    uint8_t current_channel_6;
    uint8_t current_channel_7;
    uint8_t current_channel_8;
} CurrentData;  // Must be 64 bits

typedef struct {
    uint64_t voltage;
} BatteryData;  // Must be 64 bits

typedef struct {
    uint16_t data1;
    uint16_t data2;
    uint16_t data3;
    uint16_t data4;
} CANStruct1;  // Must be 64 bits = 8 bytes

typedef struct {
    uint16_t data1;  // 2 bytes
    uint16_t data2;
    uint16_t data3;
    uint16_t data4;
} CANStruct2;  // Must be 64 bits = 8 bytes

// The struct below is for the 8 sensors and 5 strain gauges. Allocating 16 bits (2 bytes) for each sensor (each voltage message/reading takes in 12 bits.)

typedef struct{
    uint16_t AnalogData1;
    uint16_t AnalogData2;
    uint16_t AnalogData3;
    uint16_t AnalogData4;
}FirstSensorsStruct;
typedef struct
{
    uint16_t AnalogData5;
    uint16_t AnalogData6;
    uint16_t AnalogData7;
    uint16_t AnalogData8;
}LastSensorsStruct;

typedef struct
{
    uint16_t AnalogData9;
    uint16_t AnalogData10;
    uint16_t AnalogData11;
    uint16_t AnalogData12;
}FourSGaugeStruct;

typedef struct
{
    uint16_t AnalogData13;
    uint16_t extra1;
    uint16_t extra2;
    uint16_t extra3;


}LastSGaugeStruct;

// Dashboard CAN Messages
typedef struct{ // One byte, part of DashDataOut
    uint8_t button1 : 1,
            button2 : 1,
            button3 : 1,
            button4 : 1,
            button5 : 1,
            button6 : 1;
} DashButtonState;

union DashButtons{
    DashButtonState dashButtonState;
    uint8_t bytes;
};

typedef struct{ // One byte, part of DashDataIn
    uint8_t row : 3;
    uint8_t location : 5;
} DashDataInfoByte;

union DashDataInfo{
    DashDataInfoByte dashDataInfo;
    uint8_t bytes;
};

// id 201
typedef struct {
    uint16_t unused_1;
    uint16_t unused_2;
    uint8_t unused_3;
    uint8_t pot_sw_1;
    uint8_t pot_sw_2;
    DashButtonState buttons;
} DashDataIn;

// id 200
typedef struct {
    DashDataInfoByte infoByte;
    uint8_t data[7];
} DashDataOut;


#endif
