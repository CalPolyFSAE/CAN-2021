#ifndef CANMESSAGE_H
#define CANMESSAGE_H


// CanMessage class declaration
class CanMessage {
public:
    static void sendTime();
    static void sendSensors();
    static void sendFourSGauges();
    static void sendLastSGauge();

private:
    static CanMessage *getInstance();
    void sendTimeHelper();
    void sendSensorsHelper();
    void sendFourSGaugesHelper();
    void sendLastSGaugeHelper();
    CanMessage();
    void initCan();
    static CanMessage* instance;
};


#endif 
