#include "clock_config.h"
#include "adc.h"
#include "pin_mux.h"
#include "MKE18F16.h"
#include "AnalogObject.h"
#include "CanMessageStructs.h"
#include "main.h"

//for tick count imports
#include "FreeRTOS.h"
#include "task.h"

using namespace BSP;

//universal
AnalogObject::AnalogObject(AnalogObjectData data){
    this->data = data;
}

// Universal
void AnalogObject::readValues(){
    adc::ADC& add = adc::ADC::StaticClass();
    this->pin_data_1 = add.read(data.adcNumber1, data.adcChannel1);
    this->pin_data_2 = add.read(data.adcNumber2, data.adcChannel2);
}

// Universal
void AnalogObject::initADC(){
    adc::ADC::ConstructStatic(NULL);
}
