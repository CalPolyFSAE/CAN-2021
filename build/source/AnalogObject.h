#ifndef ANALOGOBJECT
#define ANALOGOBJECT

//#include "CanMessageStructs.h"
#include "MKE18F16.h"

typedef struct{
    ADC_Type *adcNumber1;
    int adcChannel1;
    //ADC_Type *adcNumber2;
    //int adcChannel2;
} AnalogObjectData;

class AnalogObject{
protected:
    AnalogObjectData data;

public:
    AnalogObject(AnalogObjectData data);
    void readValues();
    static void initADC();
    uint16_t pin_data_1;
    uint16_t pin_data_2;
};

#endif