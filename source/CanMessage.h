#ifndef CANMESSAGE_H
#define CANMESSAGE_H

void sendTimeHelper();
void sendSensors();
void sendFourSGauges();
void sendLastSGauge();

void sendTime();
void sendSensorsHelper();
void sendFourSGaugesHelper();
void sendLastSGaugeHelper();

void initCan();

#endif