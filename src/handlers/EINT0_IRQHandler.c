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
#include "joystick.h"

/* Macros Definitions */
/**
 * @def ANTIREBOTE_TICKS
 * @brief Cantidad de ticks del SisTick necesarios para lograr un antirrebote por software.
 * El systick trabajando a 100 MHz genera un tick cada 10 ms.
 * ANTIREBOTE_TICKS = 5 para antirrebote de 50 ms.
 */
#define ANTIREBOTE_TICKS 5

/**
 * @brief Overwrite the interrupt handle routine for EINT0
 */
void EINT0_IRQHandler(void)
{
    static uint32_t last_value = 0;                     /* almacena el anterior current_value del SysTick */
    uint32_t current_value = SYSTICK_GetCurrentValue(); /* almacena el actual current_value del SysTick */

    /* Me aseguro que haya pasado el tiempo de antirrebote */
    if ((current_value - last_value) >= ANTIREBOTE_TICKS)
    {
        last_value = current_value;

        switchModoOrientacion();
        configuracionCanalesADC();
    }

    EXTI_ClearEXTIFlag(EXTI_EINT0); /* Clear the interrupt flag */
}