#include "clock_config.h"
#include "adc.h"
#include "pin_mux.h"
#include "MKE18F16.h"
#include "AnalogObject.h"
//#include "CanMessageStructs.h"
//#include "main.h"

//for tick count imports
#include "FreeRTOS.h"
#include "task.h"

using namespace BSP;

//universal
AnalogObject::AnalogObject(ADC_Type *adc,int adcChannel){
    this->adc=adc;
    this->adcChannel=adcChannel;
}

// Universal
void AnalogObject::readValues(){
    adc::ADC& add = adc::ADC::StaticClass();
    //read data into each sensor's pin_data_1 attribute (for testing purposes)
    this->pin_data_1 = add.read(adc,adcChannel);
    //this->pin_data_2 = add.read(data.adcNumber2, data.adcChannel2);
}

// Universal
void AnalogObject::initADC(){
    adc::ADC::ConstructStatic(NULL);
}
