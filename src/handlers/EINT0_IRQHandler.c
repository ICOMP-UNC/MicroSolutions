// EINT0_IRQHandler.c
/*
 * @file EINT0_IRQHandler.c
 * @brief Contiene el handler para la IRQ de EINT0
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/**
 * @brief Overwrite the interrupt handle routine for EINT0
 */
void EINT0_IRQHandler(void)
{}