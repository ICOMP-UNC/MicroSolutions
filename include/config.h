// config.h
/*
 * @file config.h
 * @brief Contiene la inclusion de los drivers necesarios para el proyecto,
 * la definicion de las funciones de configuracion y los handlers necesarios
 * para los modulos que se usan en el proyecto
 */

#ifndef CONFIG_H
#define CONFIG_H

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include <stddef.h>

#include "lpc17xx_adc.h"
#include "lpc17xx_dac.h"
#include "lpc17xx_exti.h"
#include "lpc17xx_gpdma.h"
#include "lpc17xx_gpio.h"
#include "lpc17xx_pinsel.h"
#include "lpc17xx_pwm.h"
#include "lpc17xx_systick.h"
#include "lpc17xx_timer.h"

/* Macros Definitions */
/**
 * @def INPUT
 * @def OUTPUT
 * @brief GPIO Direction Definitions.
 */
#define INPUT  0
#define OUTPUT 1

/* Global variables Definitions */
/**
 * @def angulo_SV
 * @def angulo_SH
 * @brief Guardan los valores de los angulos de posición de los servos horizontal y vertical.
 * Inician en posición de 90°
 */
uint8_t angulo_SV = 90;
uint8_t angulo_SH = 90;
/**
 * @brief Nivel de tensión de salida del DAC para regular intensidad de iluminación del led.
 * El valor debe estar en el RANGO_TENSION_DAC.
 */
uint32_t dac_output = 1023;
/**
 * @brief Initialize systick configuration
 */
void configSystick(void);

/**
 * @brief Initialize the external interrupt
 */
void configExternalInterrupt(void);

/**
 * @brief Configure Timer0 to trigger an interrupt every 60 seconds.
 */
void configTimer0AndMatch(void);

/**
 * @brief Initialize ADC configuration
 */
void configADC(void);

/**
 * @brief Initialize DAC configuration
 */
void configDAC(void);

/**
 * @brief Initialize DMA configuration
 */
void configGPDMA(uint32_t*);

/**
 * @brief Initialize PWM configuration
 */
void configPWM(void);

/**
 * @brief Initialize NVIC configuration
 * Setea las prioridades para las interrupciones utilizadas
 */
void configNVIC(void);

#endif