// main.c
/*
 * @file main.c
 * @brief Main file for the project
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Define macros */
#define TRUE 1
#define FALSE 0

void configNVIC(void)
{
    NVIC_SetPriority(EINT0_IRQn, 0);  /* Set the priority of the EINT0 interrupt */
    NVIC_SetPriority(TIMER0_IRQn, 1); /* Set the priority of the TIMER0 interrupt */
    NVIC_SetPriority(TIMER1_IRQn, 2); /* Set the priority of the TIMER1 interrupt */
    NVIC_SetPriority(EINT3_IRQn, 3);  /* Set the priority of the GPIO interrupt */
}

int main(void)
{
    SystemInit();                   /* Initialize the system clock (default: 100 MHz) */

    configPins();
    configSystick();                /* Configure SysTick timer */
    configExternalInterrupt();      /* Configure external interrupt */
    configTimer0AndMatch();         /* Configure Timer0 */
    configADC();                    /* Configure ADC */
    configDAC();                    /* Configure DAC */
    configGPDMA();                  /* Configure DMA */
    configPWM();                    /* Configure PWM */
    configNVIC();

    while(TRUE)
    {
        __wfi();
    }

    return 0;                       /* Should never reach this */
}