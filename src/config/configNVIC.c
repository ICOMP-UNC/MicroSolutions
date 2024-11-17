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

/**
 * @brief Initialize NVIC configuration.
 * Setea las prioridades para las interrupciones utilizadas
 * y habilita las interrupciones correspondientes.
 */
void configNVIC(void)
{
    /* Set the priority of the interrupts */
    NVIC_SetPriority(EINT0_IRQn, 0);
    NVIC_SetPriority(PWM1_IRQn, 1);
    NVIC_SetPriority(ADC_IRQn, 2);
    /* Enablement of the interrupts */
    NVIC_EnableIRQ(EINT0_IRQn);
    NVIC_EnableIRQ(PWM1_IRQn);
    NVIC_EnableIRQ(ADC_IRQn);
    NVIC_EnableIRQ(SysTick_IRQn);
}