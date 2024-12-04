// PWM_IRQHandler.c
/*
 * @file PWM_IRQHandler.c
 * @brief Contiene el handler para la IRQ del PWM
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/**
 * @brief PWM Interrupt Handler.
 */
void PWM_IRQHandler(void) {}