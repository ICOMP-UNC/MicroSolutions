// ldr.h
/*
 * @file ldr.h
 * @brief Contiene la definicion de constantes, variable, structs y funciones
 * necesarios para el sensado de radiación solar recibido por los 4 sensores ldr
 * para la orientación del panel solar del sistema.
 */

#ifndef LDR_H
#define LDR_H

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Pin Definitions */
#define PIN_LDR_S1 ((uint32_t)(1 << 30)) // P1[30]
#define PIN_LDR_S2 ((uint32_t)(1 << 31)) // P1[31]
#define PIN_LDR_S3 ((uint32_t)(1 << 3))  // PO[3]
#define PIN_LDR_S4 ((uint32_t)(1 << 2))  // PO[2]

/* Macros Definitions */
#define MUESTRAS 10
#define UMBRAL_SENSIBILIDAD 50

/* Global variables Definitions */
uint16_t ldr_S1[MUESTRAS] = {};
uint16_t ldr_S2[MUESTRAS] = {};
uint16_t ldr_S3[MUESTRAS] = {};
uint16_t ldr_S4[MUESTRAS] = {};

uint16_t promedio_S1;
uint16_t promedio_S2;
uint16_t promedio_S3;
uint16_t promedio_S4;

/**
 * @brief Initialize the GPIO pins.
 */
void configPinLDR(void);

/**
 * @brief Promedia los valores almacenados sensados para cada LDR
 */
void promediarValoresLDR(void);

/**
 * @brief Compara los valores promedios de los valores sensados para cada LDR
 */
void compararValoresLDR(void);

#endif