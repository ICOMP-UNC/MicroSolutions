// servos.h
/*
 * @file servos.h
 * @brief Contiene la definicion de constantes, variable, structs y funciones
 * necesarios para la utilizacion de los servos motores SG90 controlados mediante PWM.
 */

#ifndef SERVOS_H
#define SERVOS_H

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Pin Definitions */
#define PIN_SERVO_X ((uint32_t)(1 << 1)) // P2[1]
#define PIN_SERVO_Y ((uint32_t)(1 << 2)) // P2[2]

/* Macros Definitions */
#define PWM_CHANNEL_SV ((uint8_t)(2)) // Canal PWM Servo Vertical
#define PWM_CHANNEL_SH ((uint8_t)(3)) // Canal PWM Servo Horizontal

/**
 * @brief Initialize the GPIO pins.
 */
void configPinServos(void);

/**
 * @brief Actualiza la configuracion de los canales PWM para los servos horizontal y vertical
 * de acuerdo a las comparaciones hechas de los valores sensados
 */
void actualizarPWM(void);

#endif