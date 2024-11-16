// configExternalInterrupt.c
/*
 * @file configExternalInterrupt.c
 * @brief Contiene la configuracion de las interrupciones externas
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

void configExternalInterrupt(void)
{
    EXTI_Init();
    EXTI_InitTypeDef extiCfg;
    extiCfg.EXTI_Line = EXTI_EINT0;
    extiCfg.EXTI_Mode = EXTI_MODE_EDGE_SENSITIVE;
    extiCfg.EXTI_polarity = EXTI_POLARITY_LOW_ACTIVE_OR_FALLING_EDGE;
    EXTI_Config(&extiCfg);
}