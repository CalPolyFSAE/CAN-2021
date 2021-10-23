#ifndef CANMESSAGE_H
#define CANMESSAGE_H

class CanMessage {
public:
    static void sendTime();
    //static void sendSixtyHz();
    static void sendSensors();
    static void sendFourSGauges();
    static void sendLastSGauge();

private:
    static CanMessage *getInstance();
    void sendTimeHelper();
    //void sendSixtyHzHelper();
    void sendSensorsHelper();
    void sendFourSGaugesHelper();
    void sendLastSGaugeHelper();
    CanMessage();
    void initCan();
    static CanMessage* instance;
};


#endif //CANMESSAGE_H
