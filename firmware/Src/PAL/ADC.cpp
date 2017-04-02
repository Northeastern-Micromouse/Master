#include "ADC.h"

#include <cstdint>

namespace {
    uint32_t ADC_DATA_SIZE = 16;
}

namespace pal {
    
    Adc::Adc(ADC_HandleTypeDef adc_handle) {
        adc_handle_ = adc_handle;
        HAL_ADC_Start_DMA(&adc_handle_, reinterpret_cast<uint32_t*>(data_), ADC_DATA_SIZE);
    }
 
    Adc::~Adc() {
        HAL_ADC_Stop_DMA(&adc_handle_);
    }
 
    uint32_t Adc::GetData(int pos) {
        return data_[pos];
    }
    
}