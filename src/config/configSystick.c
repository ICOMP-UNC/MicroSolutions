// configSystick.c
/*
 * @file configSystick.c
 * @brief Contiene la configuracion del Systick
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
 * @def SYSTICK_TIME
 * @brief Intervalo de interrupción del Systick.
 * Valor expresado en milisegundos
 */
#define SYSTICK_TIME 1000

/**
 * @brief Initialize systick configuration
 */
void configSystick(void)
{
    SYSTICK_InternalInit(SYSTICK_TIME); /* Initialize the SysTick timer with a time interval of 1000 ms */
    SYSTICK_IntCmd(ENABLE);             /* Enable SysTick interrupt */
    SYSTICK_Cmd(ENABLE);                /* Enable SysTick counter */
}