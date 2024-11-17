// configTimers.c
/*
 * @file configTimers.c
 * @brief Contiene la configuracion de los timers con sus respectivos matches y captures
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
 * @def PRESCALE_VALUE
 * @brief Valor del pre-escaler del Timer0.
 * Valor expresado en microsegundos
 */
#define PRESCALE_VALUE 100
/**
 * @def MILISECOND
 * @brief Valor de un milisegundo en microsegudnos.
 * Valor expresado en microsegundos
 */
#define MILISECOND 1000
/**
 * @def CANT_MS
 * @brief Cantidad de milisegudnos.
 * Valor expresado en milisegundos
 */
#define CANT_MS 100

/**
 * @brief Configure Timer0 to trigger an interrupt every 60 seconds.
 */
void configTimer0AndMatch(void)
{
    TIM_TIMERCFG_Type timerCfg;
    TIM_MATCHCFG_Type matchCfg;

    /* Configure Timer0 in microsecond mode with a prescaler */
    timerCfg.PrescaleOption = TIM_PRESCALE_USVAL; /* Prescaler in microseconds */
    timerCfg.PrescaleValue = PRESCALE_VALUE;      /* Prescaler for 100 MHz clock -> 100 µs resolution */
    TIM_Init(LPC_TIM0, TIM_TIMER_MODE, &timerCfg);

    /* Configure Match0.1 channel for ADC */
    matchCfg.MatchChannel = (uint8_t)(1);
    matchCfg.IntOnMatch = DISABLE;
    matchCfg.StopOnMatch = DISABLE;
    matchCfg.ResetOnMatch = ENABLE;
    matchCfg.ExtMatchOutputType = TIM_EXTMATCH_NOTHING;
    matchCfg.MatchValue = (uint32_t)((MILISECOND * CANT_MS) / PRESCALE_VALUE); /* Match cada 100 milisegundos */
    TIM_ConfigMatch(LPC_TIM0, &matchCfg);

    TIM_Cmd(LPC_TIM0, ENABLE); /* Start Timer0 */
}