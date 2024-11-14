// configPeripherals.c
/*
 * @file configPeripherals.c
 * @brief Contiene la configuracion de todos los periféricos utilizados en el proyecto
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Define frequency variables */
#define ADC_FREQ 100000 /* 100 kHz */
/* Define time variables */
#define SYSTICK_TIME 100   /* Expressed in milliseconds */
#define SECOND       10000 /* 1 second */

void configSystick(void)
{
    SYSTICK_InternalInit(SYSTICK_TIME); /* Initialize the SysTick timer with a time interval of 100 ms */
    SYSTICK_IntCmd(ENABLE); /* Enable SysTick interrupt */
    SYSTICK_Cmd(ENABLE);    /* Enable SysTick counter */
}

void configExternalInterrupt(void)
{
}

void configTimer0AndMatch(void)
{
}

void configADC(void)
{
}

void configDAC(void)
{
}

void configGPDMA(void)
{
}

void configPWM(void)
{
}