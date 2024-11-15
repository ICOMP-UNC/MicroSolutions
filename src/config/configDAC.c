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

/* Define macros */
#define CLOCK_DAC_MHZ 25 // DAC clock: 25 MHz (CCLK divided by 4)
#define WAVE_FREQUENCY 1 // Sine wave frequency: 1 Hz
#define MHZ 1000000      // 1 MHz en Hz

void configDAC(void)
{
    DAC_Init(LPC_DAC);      // Initialize the DAC
    DAC_CONVERTER_CFG_Type DACCfg;
    uint32_t update_interval;
    // Configure DAC settings
    DACCfg.CNT_ENA = SET;   // Enable DAC counter mode (timeout mode)
    DACCfg.DMA_ENA = SET; // Disable DAC DMA mode
    // Calculate sample update interval for the desired waveform frequency
    update_interval = (CLOCK_DAC_MHZ * MHZ) / (WAVE_FREQUENCY);
    DAC_SetDMATimeOut(LPC_DAC, update_interval); // Set the DAC timeout between samples
    // Set Minimum current (350 uA) for DAC
    DAC_SetBias(LPC_DAC, SET);
    // Apply the DAC configuration
    DAC_ConfigDAConverterControl(LPC_DAC, &DACCfg);
}