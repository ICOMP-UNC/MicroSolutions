// configADC.c
/*
 * @file configADC.c
 * @brief Contiene la configuracion del ADC y sus respectivos canales
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Macros Definitions */
/**
 * @def ADC_FREQ
 * @brief Define la frecuencia de trabajo del ADC.
 * Valor expresado en Hz.
 */
#define ADC_FREQ 100000 /* ADC frequency in 100 kHz */

/**
 * @brief Initialize ADC configuration
 */
void configADC(void)
{
    ADC_Init(LPC_ADC, ADC_FREQ); /* Initialize the ADC peripheral with a 100 kHz sampling frequency */

    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_0, ENABLE); /* Enable ADC channel 0 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_0, ENABLE);  /* Enable interrupt for ADC channel 0 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_1, ENABLE); /* Enable ADC channel 1 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_1, ENABLE);  /* Enable interrupt for ADC channel 1 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_2, ENABLE); /* Enable ADC channel 2 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_2, ENABLE);  /* Enable interrupt for ADC channel 2 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_4, ENABLE); /* Enable ADC channel 4 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_4, ENABLE);  /* Enable interrupt for ADC channel 4 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_5, ENABLE); /* Enable ADC channel 5 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_5, ENABLE);  /* Enable interrupt for ADC channel 5 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_6, ENABLE); /* Enable ADC channel 6 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_6, ENABLE);  /* Enable interrupt for ADC channel 6 */
    ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_7, ENABLE); /* Enable ADC channel 7 */
    ADC_IntConfig(LPC_ADC, ADC_CHANNEL_7, ENABLE);  /* Enable interrupt for ADC channel 7 */

    ADC_EdgeStartConfig(LPC_ADC, ADC_START_ON_RISING); /* Start conversion on a rising edge of the MAT signal*/
    ADC_StartCmd(LPC_ADC, ADC_START_ON_MAT01);         /* Start the ADC conversion en el Match0.1*/
}
