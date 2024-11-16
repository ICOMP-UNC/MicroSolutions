// SysTick_Handler.c
/*
 * @file SysTick_Handler.c
 * @brief Contiene el handler para la IRQ del Systick
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"
#include "ldr.h"
#include "joystick.h"
#include "servos.h"
#include "bateria.h"

/**
 * @brief SysTick Interrupt Handler.
 */
void SysTick_Handler(void)
{
    if(modo == AUTOMATICO)
    {
        promediarValoresLDR();
        compararValoresLDR();
    }
    else
    {
        promediarValoresEjesJoystick();
        compararValoresEjesJoystick();
    }

    actualizarPWM();

    promediarValoresBateria();
    compararValoresBateria();
    actualizarDAC();

    SYSTICK_ClearCounterFlag();
}