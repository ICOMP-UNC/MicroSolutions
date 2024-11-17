// bateria.c
/*
 * @file bateria.c
 * @brief Modulo que contiene la implementación de las funciones
 * necesarias para el monitoreo del tension de la bateria y control de sus respectivos leds.
 */

#include "bateria.h"

/* Global variables Declarations */
uint16_t tension_bateria[MUESTRAS] = {};
uint16_t promedio_tension;

/**
 * @brief Initialize the batery pins.
 * Voltaje batería: ADC0[0]: PO[23]
 * LED batería: DAC[AOUT]: PO[26]
 */
void configPinBateria(void)
{
    PINSEL_CFG_Type pinCfg;

    /* Configuración pin ADC para voltaje batería */
    pinCfg.Portnum = PINSEL_PORT_0;
    pinCfg.Pinnum = PINSEL_PIN_23;
    pinCfg.Funcnum = PINSEL_FUNC_1; /* Function number is 1 (ADC) */
    pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
    pinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;

    PINSEL_ConfigPin(&pinCfg);

    /* Configuración pin DAC para LED batería */
    pinCfg.Pinnum = PINSEL_PIN_26;
    pinCfg.Funcnum = PINSEL_FUNC_2; /* Function number is 2 (AOUT) */

    PINSEL_ConfigPin(&pinCfg);
}

/**
 * @brief Promedia los valores almacenados sensados para la tension de la bateria
 */
void promediarValoresTensionBateria(void)
{
    uint16_t suma = 0;
    for (size_t i = 0; i < MUESTRAS; i++)
    {
        suma = suma + tension_bateria[i];
    }
    promedio_tension = suma / MUESTRAS;
}

/**
 * @brief Compara el valor promedio para la tension de la bateria
 * y determina el valor de tension de alimentacion del LED mediante el DAC
 * Rango de tension de alimentacion LPC 2.4 a 3.3
 * Rango de tension de bateria de litio 2.5 a 3.3
 * Rango de tension de alimentacion LED de 1.8 a 2.4
 * Rango de tension del DAC de 2.7 a 3.3
 * Resistencia serie de 68 o 56 ohms
 * Mapeo lineal al rango del DAC
 */
void compararValoresTensionBateria(void)
{
    uint16_t tension_decimal = (promedio_tension * 3.3) / 4095;

    uint16_t tension_led =
        TENSION_DAC_MIN + ((tension_decimal - TENSION_BATERIA_MIN) / RANGO_TENSION_BATERIA) * RANGO_TENSION_DAC;

    dac_output = (uint32_t)((tension_led / 3.3) * 1023);
}

/**
 * @brief Actualiza la configuracion del DAC de acuerdo
 * a las comparaciones hechas de los valores sensados de la tension de la bateria
 */
void actualizarDAC(void)
{
    DAC_UpdateValue(LPC_DAC, dac_output);
    configGPDMA(&dac_output);
}