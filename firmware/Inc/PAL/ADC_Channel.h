#include "ADC.h"

namespace pal {
    
    class AdcChannel {
    
    public:
        AdcChannel(ADC_ChannelConfTypeDef adc_chan, Adc adc);
        ~AdcChannel();
        uint16_t GetData();
    private:
        Adc adc_;
        ADC_ChannelConfTypeDef adc_chan_;
        
    };
    
}