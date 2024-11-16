// joystick.h
/*
 * @file joystick.h
 * @brief Contiene la definicion de constantes, variable, structs y funciones
 * necesarios para la utilizacion del modulo joystick para realizar
 * el switching entre modo MANUAL/AUTOMATICO mediante su pulsador
 * y la orientacion manual del panel mediante los ejes x e y.
 */

#ifndef JOYSTICK_H
#define JOYSTICK_H

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Pin Definitions */
#define EJE_X ((uint32_t)(1 << 24)) // P0[24]
#define EJE_Y ((uint32_t)(1 << 25)) // P0[25]
#define PULSADOR ((uint32_t)(1 << 10))  // P2[10]

/* Macros Definitions */
#define MANUAL 1
#define AUTOMATICO 0
#define MUESTRAS 10

/* Global variables Definitions */
uint8_t modo = AUTOMATICO;

uint16_t eje_x[MUESTRAS] = {};
uint16_t eje_y[MUESTRAS] = {};

uint16_t promedio_eje_x;
uint16_t promedio_eje_y;

/**
 * @brief Initialize the GPIO pins.
 */
void configPinJoystick(void);

/**
 * @brief Alterna entre el modo MANUAL y AUTOMATICO de orientacion del panel solar
 */
void switchModoOrientacion(void);

/**
 * @brief Habilita y deshabilita los canales del ADC de acuerdo al modo de orientacion
 * (MANUAL o AUTOMATICO)
 */
void configuracionCanalesADC(void);

/**
 * @brief Promedia los valores almacenados sensados para cada Eje
 */
promediarValoresEjesJoystick();

/**
 * @brief Compara los valores promedios de los valores sensados para cada Eje
 */
compararValoresEjesJoystick();

#endif