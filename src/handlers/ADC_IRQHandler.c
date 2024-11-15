// ADC_IRQHandler.c
/*
 * @file ADC_IRQHandler.c
 * @brief Contiene el handler para la IRQ del ADC
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"
#include "ldr.h"
#include "joystick.h"

#define DONE 1

/**
 * @brief ADC Interrupt Handler.
 * Canales LDR: ADC_CHANNEL_4, ADC_CHANNEL_5, ADC_CHANNEL_6 y ADC_CHANNEL_7
 */
void ADC_IRQHandler(void)
{
    static uint8_t pos = 0;
    uint16_t adc_value;
    if(modo == AUTOMATICO)
    {
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_4, DONE))
        {
            ldr_S1[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_4);
        }
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_5, DONE))
        {
            ldr_S2[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_5);
        }
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_6, DONE))
        {
            ldr_S3[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_6);
        }
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_7, DONE))
        {
            ldr_S4[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_7);
        }
    }
    else
    {
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_1, DONE))
        {
            eje_x[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_1);
        }
        if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_2, DONE))
        {
            eje_y[pos] = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_2);
        }
    }
    if(ADC_ChannelGetStatus(LPC_ADC, ADC_CHANNEL_0, DONE))
    {
        adc_value = ADC_ChannelGetData(LPC_ADC, ADC_CHANNEL_0);
    }

    (pos == 9)? pos=0 : pos++;
}