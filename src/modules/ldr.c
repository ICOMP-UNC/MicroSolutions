// ldr.c
/*
 * @file ldr.c
 * @brief Modulo que contiene la implementación de las funciones
 * necesarias para el sensado de radiación solar recibido por los 4 sensores ldr
 * para la orientación del panel solar del sistema.
 */

#include "ldr.h"

angulo_SV = 90;
angulo_SH = 90;

/**
 * @brief Initialize the GPIO pins.
 */
void configPinLDR(void)
{
    PINSEL_CFG_Type pinCfg;

    pinCfg.Portnum = PINSEL_PORT_1;
    pinCfg.Funcnum = PINSEL_FUNC_2; /* Function number is 2 (ADC) */
    pinCfg.Pinmode = PINSEL_PINMODE_TRISTATE;
    pinCfg.OpenDrain = PINSEL_PINMODE_NORMAL;

	for(size_t pin = PINSEL_PIN_30; pin <= PINSEL_PIN_31; pin ++)
	{
		pinCfg.Pinnum = pin;
		PINSEL_ConfigPin(&pinCfg);
	}

    pinCfg.Portnum = PINSEL_PORT_0;

    for(size_t pin = PINSEL_PIN_2; pin <= PINSEL_PIN_3; pin ++)
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
    if (abs(S1 - S2) > UMBRAL_SENSIBILIDAD) {
        // Rotar servo vertical
        if (S1 > S2) {
            // Rotar 10° hacia 0°
            angulo_SV = angulo_SV - 10;
        } else {
            // Rotar 10° hacia 180°
            angulo_SV = angulo_SV + 10;
        }
    }
    else if (abs(S3 - S4) > UMBRAL_SENSIBILIDAD) {
        // Rotar servo vertical
        if (S3 > S4) {
            // Rotar 10° hacia 0°
            angulo_SV = angulo_SV - 10;
        } else {
            // Rotar 10° hacia 180°
            angulo_SV = angulo_SV + 10;
        }
    }

    if (abs(S1 - S3) > UMBRAL_SENSIBILIDAD) {
        // Rotar servo horizontal
        if (S1 > S3) {
            // Rotar 10° hacia 0°
            angulo_SH = angulo_SH - 10;
        } else {
            // Rotar 10° hacia 180°
            angulo_SH = angulo_SH + 10;
        }
    }
    else if (abs(S2 - S4) > UMBRAL_SENSIBILIDAD) {
        // Rotar servo horizontal
        if (S2 > S4) {
            // Rotar 10° hacia 0°
            angulo_SH = angulo_SH + 10;
        } else {
            // Rotar 10° hacia 180°
            angulo_SH = angulo_SH + 10;
        }
    }
    (angulo_SV < 0)? angulo_SV = 0;
    (angulo_SV > 180)? angulo_SV = 180;
    (angulo_SH < 0)? angulo_SH = 0;
    (angulo_SH > 180)? angulo_SH = 180;
}