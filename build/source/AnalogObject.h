#ifndef ANALOGOBJECT
#define ANALOGOBJECT

#include "MKE18F16.h"

// AnalogObject class declaration
class AnalogObject
{
protected:
    ADC_Type *adc;
    int adcChannel;

public:
    // Function definitions
    AnalogObject(ADC_Type *adc, int adcChannel);
    void readValues();
    static void initADC();
    uint16_t pin_data_1;
};

#endif