// configNVIC.c
/*
 * @file configNVIC.c
 * @brief Contiene la configuracion del NVIC
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

void configNVIC(void)
{
    NVIC_SetPriority(EINT0_IRQn, 0); /* Set the priority of the EINT0 interrupt */
    NVIC_SetPriority(PWM1_IRQn, 1);  /* Set the priority of the PWM interrupt */
    NVIC_SetPriority(ADC_IRQn, 2);   /* Set the priority of the ADC interrupt */

    NVIC_EnableIRQ(EINT0_IRQn);
    NVIC_EnableIRQ(PWM1_IRQn);
    NVIC_EnableIRQ(ADC_IRQn);
    NVIC_EnableIRQ(SysTick_IRQn);
}