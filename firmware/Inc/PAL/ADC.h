#pragma once

#include "stm32l4xx_hal_adc.h"

namespace pal {
    
    class Adc {
    public:
        explicit Adc(ADC_HandleTypeDef adc_handle);
        ~Adc();
        uint32_t GetData(int pos);
    private:
        uint16_t data_[2];
        ADC_HandleTypeDef adc_handle_;
    };

}