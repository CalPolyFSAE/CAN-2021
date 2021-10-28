#include "clock_config.h"
#include "adc.h"
#include "pin_mux.h"
#include "MKE18F16.h"
#include "AnalogObject.h"

// For tick count imports
#include "FreeRTOS.h"
#include "task.h"

using namespace BSP;

// AnalogObject class function definitions

// AnalogObject constructor, sets adc and channel values
AnalogObject::AnalogObject(ADC_Type *adc, int adcChannel)
{
    this->adc = adc;
    this->adcChannel = adcChannel;
}

// readValules() reads data from the pin associated to adc and channel values of the analogObject
// The data is stored in pin_data_1
void AnalogObject::readValues()
{
    adc::ADC &add = adc::ADC::StaticClass();
    this->pin_data_1 = add.read(adc, adcChannel);
}

// Universal
void AnalogObject::initADC()
{
    adc::ADC::ConstructStatic(NULL);
}
