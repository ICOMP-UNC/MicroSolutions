// configPWM.c
/*
 * @file configPWM.c
 * @brief Contiene la configuracion del PWM y sus respectivos canales
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
 * @brief Valor del pre-escaler del PWM1.
 * Valor expresado en microsegundos
 */
#define PRESCALE_VALUE 1
/**
 * @def PWM_PERIOD
 * @brief Valor del periodo del PWM del PWM1.
 * Valor expresado en microsegundos
 */
#define PWM_PERIOD 20000 /* PWM period in 20 ms */
/**
 * @def PWM_DUTY_CYCLE
 * @brief Valor del duty cycle del PWM del PWM1 para posicionamiento central de los servos.
 * Valor expresado en microsegundos
 */
#define PWM_DUTY_CYCLE 1500 /* PWM duty cycle in 1.5 ms */
/**
 * @def PWM_CHANNEL_2
 * @def PWM_CHANNEL_3
 * @brief Canales de PWM utilizados para los servos.
 * PWM_CHANNEL_2: Servo Vertical
 * PWM_CHANNEL_3: Servo Horizontal
 */
#define PWM_CHANNEL_2 ((uint8_t)(2))
#define PWM_CHANNEL_3 ((uint8_t)(3))

/**
 * @brief Initialize PWM configuration.
 */
void configPWM(void)
{
    PWM_TIMERCFG_Type PWMCfg;
    PWM_MATCHCFG_Type MatchCfg;

    PWMCfg.PrescaleOption = PWM_TIMER_PRESCALE_USVAL;
    PWMCfg.PrescaleValue = PRESCALE_VALUE;

    PWM_Init(LPC_PWM1, PWM_MODE_TIMER, &PWMCfg);
    /* Habilitar el temporizador del PWM */
    PWM_Cmd(LPC_PWM1, ENABLE);

    MatchCfg.MatchChannel = 0;
    MatchCfg.IntOnMatch = DISABLE;
    MatchCfg.StopOnMatch = DISABLE;
    MatchCfg.ResetOnMatch = ENABLE;

    /* Establecer periodo PWM */
    PWM_MatchUpdate(LPC_PWM1, 0, PWM_PERIOD, PWM_MATCH_UPDATE_NOW);
    PWM_ConfigMatch(LPC_PWM1, &MatchCfg);

    /* Configuración del ciclo de trabajo para el Canal 2 (Servo 1) */
    MatchCfg.MatchChannel = PWM_CHANNEL_2;
    MatchCfg.ResetOnMatch = DISABLE;

    PWM_MatchUpdate(LPC_PWM1, PWM_CHANNEL_2, PWM_DUTY_CYCLE, PWM_MATCH_UPDATE_NOW);
    PWM_ConfigMatch(LPC_PWM1, &MatchCfg);

    /* Habilitar Canal 2 */
    PWM_ChannelConfig(LPC_PWM1, PWM_CHANNEL_2, PWM_CHANNEL_SINGLE_EDGE);
    PWM_ChannelCmd(LPC_PWM1, PWM_CHANNEL_2, ENABLE);

    /* Configuración del ciclo de trabajo para el Canal 3 (Servo 2) */
    MatchCfg.MatchChannel = PWM_CHANNEL_3;

    PWM_MatchUpdate(LPC_PWM1, PWM_CHANNEL_3, PWM_DUTY_CYCLE, PWM_MATCH_UPDATE_NOW);
    PWM_ConfigMatch(LPC_PWM1, &MatchCfg);

    /* Habilitar Canal 3 */
    PWM_ChannelConfig(LPC_PWM1, PWM_CHANNEL_3, PWM_CHANNEL_SINGLE_EDGE);
    PWM_ChannelCmd(LPC_PWM1, PWM_CHANNEL_3, ENABLE);
}