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

#include "bateria.h"
#include "config.h"
#include "joystick.h"
#include "ldr.h"
#include "servos.h"

/* Macros Definitions */
/**
 * @def TRUE
 * @def FALSE
 * @brief Logic Values Definitions.
 */
#define TRUE  1
#define FALSE 0

int main(void)
{
    SystemInit(); /* Initialize the system clock (default: 100 MHz) */

    configPinLDR();      /* Configure LDR pins */
    configPinJoystick(); /* Configure joystick pins */
    configPinServos();   /* Configure servos pins */
    configPinBateria();  /* Configure bateria pins */

    configSystick();           /* Configure SysTick timer */
    configExternalInterrupt(); /* Configure external interrupt */
    configTimer0AndMatch();    /* Configure Timer0 */
    configADC();               /* Configure ADC */
    configDAC();               /* Configure DAC */
    configGPDMA(&dac_output);  /* Configure DMA */
    configPWM();               /* Configure PWM */
    configNVIC();              /* Configure NVIC - Seteo de prioridades y hablitaciones */

    while (TRUE)
    {
        __asm("nop");
    }

    return 0; /* Should never reach this */
}