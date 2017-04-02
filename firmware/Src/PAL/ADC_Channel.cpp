#include "ADC_Channel.h"

#include <cstdint>

namespace pal {
    
    AdcChannel::AdcChannel(ADC_ChannelConfTypeDef adc_chan, Adc adc)
        : adc_chan_(adc_chan)
        , adc_(adc) { }
    
    AdcChannel::~AdcChannel() { }
    
    uint16_t AdcChannel::GetData() {
        
    }
    
}