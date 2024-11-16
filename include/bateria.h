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

/* Pin Definitions */
#define PIN_TENSION_BATERIA ((uint32_t)(1 << 23)) // P0[23]
#define PIN_LED_BATERIA     ((uint32_t)(1 << 26)) // P0[26]

/* Macros Definitions */
#define MUESTRAS              10
#define TENSION_BATERIA_MIN   2.5
#define TENSION_BATERIA_MAX   3.3
#define RANGO_TENSION_BATERIA (TENSION_BATERIA_MAX - TENSION_BATERIA_MIN)
#define TENSION_DAC_MIN       2.7
#define TENSION_DAC_MAX       3.3
#define RANGO_TENSION_DAC     (TENSION_DAC_MAX - TENSION_DAC_MIN)

/* Global variables Definitions */
uint16_t tension_bateria[MUESTRAS] = {};
uint16_t promedio_tension;
uint32_t dac_output;

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