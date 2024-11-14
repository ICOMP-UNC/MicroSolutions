// configPins.c
/*
 * @file configPins.c
 * @brief Contiene la configuracion de todos los puertos y pines utilizados en el proyecto
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/**
 * @brief Initialize ports and pins
 */
void configPins(void)
{}