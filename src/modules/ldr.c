// ldr.c
/*
 * @file ldr.c
 * @brief Modulo que contiene la implementación de las funciones
 * necesarias para el sensado de radiación solar recibido por los 4 sensores ldr
 * para la orientación del panel solar del sistema.
 */

#include "ldr.h"

/* Global variables Declarations */
uint16_t ldr_S1[MUESTRAS] = {};
uint16_t ldr_S2[MUESTRAS] = {};
uint16_t ldr_S3[MUESTRAS] = {};
uint16_t ldr_S4[MUESTRAS] = {};
uint16_t promedio_S1;
uint16_t promedio_S2;
uint16_t promedio_S3;
uint16_t promedio_S4;

/**
 * @brief Initialize the LDR pins.
 * LDR S1: ADC0[4]: P1[30]
 * LDR S2: ADC0[5]: P1[31]
 * LDR S3: ADC0[6]: PO[3]
 * LDR S4: ADC0[7]: PO[2]
 */
void configPinLDR(void)
{
    PINSEL_CFG_Type pinCfg;
    /* Configuración pines ADC para los 4 LDR */
    pinCfg.Portnum = PINSEL_PORT_1;
    pinCfg.Funcnum = PINSEL_FUNC_2; /* Function number is 2 (ADC) */
    pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
    pinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;

    for (size_t pin = PINSEL_PIN_30; pin <= PINSEL_PIN_31; pin++)
    {
        pinCfg.Pinnum = pin;
        PINSEL_ConfigPin(&pinCfg);
    }

    pinCfg.Portnum = PINSEL_PORT_0;

    for (size_t pin = PINSEL_PIN_2; pin <= PINSEL_PIN_3; pin++)
    {
        pinCfg.Pinnum = pin;
        PINSEL_ConfigPin(&pinCfg);
    }
}

/**
 * @brief Promedia los valores almacenados sensados para cada LDR
 */
void promediarValoresLDR(void)
{
    uint16_t suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + ldr_S1[i];
    }
    promedio_S1 = suma / MUESTRAS;
    suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + ldr_S2[i];
    }
    promedio_S2 = suma / MUESTRAS;
    suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + ldr_S3[i];
    }
    promedio_S3 = suma / MUESTRAS;
    suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + ldr_S4[i];
    }
    promedio_S4 = suma / MUESTRAS;
    suma = 0;
}

/**
 * @brief Compara los valores promedios de los valores sensados para cada LDR
 */
void compararValoresLDR(void)
{
    if (abs(promedio_S1 - promedio_S2) > UMBRAL_SENSIBILIDAD)
    {
        /* Rotar servo vertical */
        if (promedio_S1 > promedio_S2)
        {
            /* Rotar 10° hacia 0° */
            angulo_SV = angulo_SV - 10;
        }
        else
        {
            /* Rotar 10° hacia 180° */
            angulo_SV = angulo_SV + 10;
        }
    }
    else if (abs(promedio_S3 - promedio_S4) > UMBRAL_SENSIBILIDAD)
    {
        /* Rotar servo vertical */
        if (promedio_S3 > promedio_S4)
        {
            /* Rotar 10° hacia 0° */
            angulo_SV = angulo_SV - 10;
        }
        else
        {
            /* Rotar 10° hacia 180° */
            angulo_SV = angulo_SV + 10;
        }
    }

    if (abs(promedio_S1 - promedio_S3) > UMBRAL_SENSIBILIDAD)
    {
        /* Rotar servo horizontal */
        if (promedio_S1 > promedio_S3)
        {
            /* Rotar 10° hacia 0° */
            angulo_SH = angulo_SH - 10;
        }
        else
        {
            /* Rotar 10° hacia 180° */
            angulo_SH = angulo_SH + 10;
        }
    }
    else if (abs(promedio_S2 - promedio_S4) > UMBRAL_SENSIBILIDAD)
    {
        /* Rotar servo horizontal */
        if (promedio_S2 > promedio_S4)
        {
            /* Rotar 10° hacia 0° */
            angulo_SH = angulo_SH - 10;
        }
        else
        {
            /* Rotar 10° hacia 180° */
            angulo_SH = angulo_SH + 10;
        }
    }
    /* Verifico que los ángulos estén dentro del rango [0°, 180°] */
    angulo_SV = (angulo_SV < 0) ? 0 : angulo_SV;
    angulo_SV = (angulo_SV > 180) ? 180 : angulo_SV;
    angulo_SH = (angulo_SH < 0) ? 0 : angulo_SH;
    angulo_SH = (angulo_SH > 180) ? 180 : angulo_SH;
}