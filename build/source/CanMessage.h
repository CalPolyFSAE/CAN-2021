#ifndef CANMESSAGE_H
#define CANMESSAGE_H

class CanMessage {
public:
    static void sendTime();
    static void sendSixtyHz();
    static void sendHunHz();

private:
    static CanMessage *getInstance();
    void sendTimeHelper();
    void sendSixtyHzHelper();
    void sendHunHzHelper();
    CanMessage();
    void initCan();
    static CanMessage* instance;
};


#endif //CANMESSAGE_H
