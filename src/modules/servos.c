// servos.c
/*
 * @file servos.c
 * @brief Modulo que contiene la implementación de las funciones
 * necesarias para la utilizacion de los servos motores SG90 controlados mediante PWM.
 */

#include "servos.h"

/**
 * @brief Initialize the servos pins.
 * Servo eje x: PWM1[2]: P2[1]
 * Servo eje y: PWM1[3]: P2[2]
 */
void configPinServos(void)
{
    PINSEL_CFG_Type pinCfg;
    /* Configuración pines PMW1 para los dos servos */
    pinCfg.Portnum = PINSEL_PORT_2;
    pinCfg.Funcnum = PINSEL_FUNC_1; /* Function number is 1 (PWM1) */
    pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
    pinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;

    for (size_t pin = PINSEL_PIN_1; pin <= PINSEL_PIN_2; pin++)
    {
        pinCfg.Pinnum = pin;
        PINSEL_ConfigPin(&pinCfg);
    }
}

/**
 * @brief Actualiza la configuracion de los canales PWM para los servos horizontal y vertical
 * de acuerdo a las comparaciones hechas de los valores sensados
 */
void actualizarPWM(void)
{
    /* Conversión al rango de 1000-2000 para determinar el ciclo de trabajo de los PWM para los servos */
    uint32_t matchValueSV = 1000 + (angulo_SV * 1000) / 180;
    uint32_t matchValueSH = 1000 + (angulo_SH * 1000) / 180;

    PWM_MatchUpdate(LPC_PWM1, PWM_CHANNEL_SV, matchValueSV, PWM_MATCH_UPDATE_NEXT_RST);
    PWM_MatchUpdate(LPC_PWM1, PWM_CHANNEL_SH, matchValueSH, PWM_MATCH_UPDATE_NEXT_RST);
}