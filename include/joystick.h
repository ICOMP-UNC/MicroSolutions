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

/* Pins Definitions */
/**
 * @def PIN_EJE_X
 * @def PIN_EJE_Y
 * @def PIN_PULSADOR
 * @brief Definición de pines modulo joystick.
 */
#define PIN_EJE_X    ((uint32_t)(1 << 24)) /* P0[24] */
#define PIN_EJE_Y    ((uint32_t)(1 << 25)) /* P0[25] */
#define PIN_PULSADOR ((uint32_t)(1 << 10)) /* P2[10] */

/* Macros Definitions */
/**
 * @def MANUAL
 * @def AUTOMATICO
 * @brief Modos de orientación del panel solar.
 * MANUAL: mediante módulo joystick.
 * AUTOMATICO: mediante sensores LDR.
 */
#define MANUAL     1
#define AUTOMATICO 0
/**
 * @def MUESTRAS
 * @brief Cantidad de muestras de tensión de la batería.
 */
#define MUESTRAS 10

/* Global variables Definitions */
/**
 * @brief Determina el modo de orientación del panel solar.
 * Puede tomar el valor MANUL o AUTOMATICO
 */
extern uint8_t modo;
/**
 * @brief Arrays que guardan las muestras de tensión de los ejes x e y
 * del modulo joystick tomadas por el ADC.
 */
extern uint16_t eje_x[MUESTRAS];
extern uint16_t eje_y[MUESTRAS];
/**
 * @brief Valores promedios de las muestras de tensión de los ejes x e y
 * del modulo joystick tomadas por el ADC.
 */
extern uint16_t promedio_eje_x;
extern uint16_t promedio_eje_y;

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
void promediarValoresEjesJoystick(void);

/**
 * @brief Compara los valores promedios de los valores sensados para cada Eje
 */
void compararValoresEjesJoystick(void);

#endif