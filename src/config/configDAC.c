// configDAC.c
/*
 * @file configDAC.c
 * @brief Contiene la configuracion del DAC
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
 * @def DAC_FREQ
 * @brief Define la frecuencia de trabajo del DAC.
 * Valor expresado en MHz.
 */
#define DAC_FREQ 25 /* DAC frequency in 25 MHz (CCLK divided by 4) */
/**
 * @def WAVE_FREQUENCY
 * @brief Define la frecuencia de la señal de salida del DAC.
 * Valor expresado en Hz.
 */
#define WAVE_FREQUENCY 1 /* Sine wave frequency in 1 Hz */
/**
 * @def HZ
 * @brief Define el valor de 1MHz en Hz.
 */
#define HZ 1000000

/**
 * @brief Initialize DAC configuration.
 */
void configDAC(void)
{
    DAC_Init(LPC_DAC); /* Initialize the DAC */
    DAC_CONVERTER_CFG_Type DACCfg;
    uint32_t update_interval;
    /* Configure DAC settings */
    DACCfg.CNT_ENA = RESET; /* Disable DAC counter mode (timeout mode) */
    DACCfg.DMA_ENA = SET;   /*  Enable DAC DMA mode */
    /* Calculate sample update interval for the desired waveform frequency */
    update_interval = (DAC_FREQ * HZ) / (WAVE_FREQUENCY);
    DAC_SetDMATimeOut(LPC_DAC, update_interval); /* Set the DAC timeout between samples */
    /* Set Minimum current (350 uA) for DAC */
    DAC_SetBias(LPC_DAC, SET);
    /* Apply the DAC configuration */
    DAC_ConfigDAConverterControl(LPC_DAC, &DACCfg);
}