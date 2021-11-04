#ifndef CANMESSAGE_H
#define CANMESSAGE_H

void sendSensors();
void sendFourSGauges();
void sendLastSGauge();
void sendTime();

void initCan();

#endif