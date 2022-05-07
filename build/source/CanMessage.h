#ifndef CANMESSAGE_H
#define CANMESSAGE_H

#include "canmessagestructs.h"

void sendSensors();
void sendFourSGauges();
void sendLastSGauge();
void sendTime();

void initCan();

#endif