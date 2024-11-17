// bateria.h
/*
 * @file bateria.h
 * @brief Contiene la definicion de constantes, variable, structs y funciones
 * necesarios para el monitoreo del tension de la bateria y control de sus respectivos leds.
 */

#ifndef BATERIA_H
#define BATERIA_H

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Pins Definitions */
/**
 * @def PIN_TENSION_BATERIA
 * @def PIN_LED_BATERIA
 * @brief Definición de pines modulo batería.
 */
#define PIN_TENSION_BATERIA ((uint32_t)(1 << 23)) /* P0[23] */
#define PIN_LED_BATERIA     ((uint32_t)(1 << 26)) /* P0[26] */

/* Macros Definitions */
/**
 * @def MUESTRAS
 * @brief Cantidad de muestras de tensión de la batería.
 */
#define MUESTRAS 10
/**
 * @def TENSION_BATERIA_MIN
 * @def TENSION_BATERIA_MAX
 * @brief Valores de tensión mínimo y máximo de la batería.
 */
#define TENSION_BATERIA_MIN 2.5
#define TENSION_BATERIA_MAX 3.3
/**
 * @def RANGO_TENSION_BATERIA
 * @brief Rango de tensión de trabajo de la batería.
 */
#define RANGO_TENSION_BATERIA (TENSION_BATERIA_MAX - TENSION_BATERIA_MIN)
/**
 * @def TENSION_DAC_MIN
 * @def TENSION_DAC_MIN
 * @brief Valores de tensión mínimo y máximo de salida del DAC.
 */
#define TENSION_DAC_MIN 2.7
#define TENSION_DAC_MAX 3.3
/**
 * @def RANGO_TENSION_DAC
 * @brief Rango de tensión de trabajo para el DAC.
 */
#define RANGO_TENSION_DAC (TENSION_DAC_MAX - TENSION_DAC_MIN)

/* Global variables Definitions */
/**
 * @brief Array con las muestras de tensión de la batería tomadas por el ADC.
 * Los valores deben estar en el RANGO_TENSION_BATERIA.
 */
extern uint16_t tension_bateria[MUESTRAS] = {};
/**
 * @brief Promedio de tensión de la batería de las muestras tomadas por el ADC.
 * El valor debe estar en el RANGO_TENSION_BATERIA.
 */
extern uint16_t promedio_tension;

/**
 * @brief Initialize the GPIO pins.
 */
void configPinBateria(void);

/**
 * @brief Promedia los valores almacenados sensados para la tension de la bateria
 */
void promediarValoresTensionBateria(void);

/**
 * @brief Compara el valor promedio para la tension de la bateria
 */
void compararValoresTensionBateria(void);

/**
 * @brief Actualiza la configuracion del DAC de acuerdo
 * a las comparaciones hechas de los valores sensados de la tension de la bateria
 */
void actualizarDAC(void);

#endif