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

/**
 * @brief ADC Interrupt Handler.
 */
void ADC_IRQHandler(void)
{}