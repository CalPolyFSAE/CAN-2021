#ifndef CONSTANTS_H
#define CONSTANTS_H

/*definiting data variables for 8 sensors and 5 strain  gauges below. for each sensor/strain gauge, define name, adc converter,
and channel to read data from */

#define Sensor1_Name ""
#define Sensor1_ADC ADC2
#define Sensor1_Channel 13

#define Sensor2_Name ""
#define Sensor2_ADC ADC2
#define Sensor2_Channel 13

#define Sensor3_Name ""
#define Sensor3_ADC ADC2
#define Sensor3_Channel 13

#define Sensor4_Name ""
#define Sensor4_ADC ADC2
#define Sensor4_Channel 13

#define Sensor5_Name ""
#define Sensor5_ADC ADC2
#define Sensor5_Channel 13

#define Sensor6_Name ""
#define Sensor6_ADC ADC2
#define Sensor6_Channel 13

#define Sensor7_Name ""
#define Sensor7_ADC ADC2
#define Sensor7_Channel 13

#define Sensor8_Name ""
#define Sensor8_ADC ADC2
#define Sensor8_Channel 13

// constants below are for the 5 strain gauges

#define Sensor9_Name ""
#define Sensor9_ADC ADC2
#define Sensor9_Channel 13

#define Sensor10_Name ""
#define Sensor10_ADC ADC2
#define Sensor10_Channel 13

#define Sensor11_Name ""
#define Sensor11_ADC ADC2
#define Sensor11_Channel 13

#define Sensor12_Name ""
#define Sensor12_ADC ADC2
#define Sensor12_Channel 13

#define Sensor13_Name ""
#define Sensor13_ADC ADC2
#define Sensor13_Channel 13

//priority of our project -- higher hex value means lower priority project (ours is low priority)
#define CAN_ID_TIME  0x0700
//first 4 sensors = 701
//last 4 sensors = 702
//first 5 sgauges = 703




#define CAN_BUS 0
#define CAN_BAUD_RATE 1000000



#endif