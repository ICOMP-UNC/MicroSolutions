// joystick.c
/*
 * @file joystick.c
 * @brief Modulo que contiene la implementación de las funciones
 * necesarias para la utilizacion del modulo joystick para realizar
 * el switching entre modo MANUAL/AUTOMATICO mediante su pulsador
 * y la orientacion manual del panel mediante los ejes x e y.
 */

#include "joystick.h"

/**
 * @brief Initialize the GPIO pins.
 */
void configPinJoystick(void)
{
    PINSEL_CFG_Type pinCfg;

    pinCfg.Portnum = PINSEL_PORT_0;
    pinCfg.Funcnum = PINSEL_FUNC_1; /* Function number is 1 (ADC) */
    pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
    pinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;

    for (size_t pin = PINSEL_PIN_24; pin <= PINSEL_PIN_25; pin++)
    {
        pinCfg.Pinnum = pin;
        PINSEL_ConfigPin(&pinCfg);
    }

    pinCfg.Portnum = PINSEL_PORT_2;
    pinCfg.Pinnum = PINSEL_PIN_10;
    PINSEL_ConfigPin(&pinCfg);
}

/**
 * @brief Alterna entre el modo MANUAL y AUTOMATICO de orientacion del panel solar
 */
void switchModoOrientacion(void)
{
    if (modo == AUTOMATICO)
    {
        modo = MANUAL;
    }
    else
    {
        modo = AUTOMATICO;
    }
}

/**
 * @brief Habilita y deshabilita los canales del ADC de acuerdo al modo de orientacion
 * (MANUAL o AUTOMATICO)
 */
void configuracionCanalesADC(void)
{
    if (modo == MANUAL)
    {
        /* Habilito canales ADC Eje X e Y joystick */
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_1, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_1, ENABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_2, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_2, ENABLE);

        /* Deshabilito canales ADC de los LDR */
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_4, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_4, DISABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_5, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_5, DISABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_6, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_6, DISABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_7, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_7, DISABLE);
    }
    else
    {
        /* Deshabilito canales ADC Eje X e Y joystick */
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_1, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_1, DISABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_2, DISABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_2, DISABLE);

        /* Habilito canales ADC de los LDR */
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_4, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_4, ENABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_5, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_5, ENABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_6, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_6, ENABLE);
        ADC_ChannelCmd(LPC_ADC, ADC_CHANNEL_7, ENABLE);
        ADC_IntConfig(LPC_ADC, ADC_CHANNEL_7, ENABLE);
    }
}

/**
 * @brief Promedia los valores almacenados sensados para cada Eje
 */
void promediarValoresEjesJoystick(void)
{
    uint16_t suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + eje_x[i];
    }
    promedio_eje_x = suma / MUESTRAS;
    suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + eje_y[i];
    }
    promedio_eje_y = suma / MUESTRAS;
    suma = 0;
}

/**
 * @brief Compara los valores promedios de los valores sensados para cada Eje
 */
void compararValoresEjesJoystick(void)
{
    if (promedio_eje_x > 3072)
    {
        angulo_SH = angulo_SH + 10;
    }
    else if (promedio_eje_x < 1024)
    {
        angulo_SH = angulo_SH - 10;
    }
    if (promedio_eje_y > 3072)
    {
        angulo_SV = angulo_SV + 10;
    }
    else if (promedio_eje_y < 1024)
    {
        angulo_SV = angulo_SV - 10;
    }
    /* Verifico que los ángulos estén dentro del rango [0°, 180°] */
    angulo_SV = (angulo_SV < 0) ? 0 : angulo_SV;
    angulo_SV = (angulo_SV > 180) ? 180 : angulo_SV;
    angulo_SH = (angulo_SH < 0) ? 0 : angulo_SH;
    angulo_SH = (angulo_SH > 180) ? 180 : angulo_SH;
}
