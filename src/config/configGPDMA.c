// configGPDMA.c
/*
 * @file configGPDMA.c
 * @brief Contiene la configuracion del DMA y sus respectivos canales
 */

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#ifdef __USE_MCUEXPRESSO
#include <cr_section_macros.h> /* The cr_section_macros is specific to the MCUXpresso delivered toolchain */
#endif

#include "config.h"

/* Define macros */
#define DMA_SIZE         1
#define TRUE             1
#define DMA_CHANNEL_ZERO 0

GPDMA_Channel_CFG_Type GPDMACfg;    // DMA configuration structure
GPDMA_LLI_Type DMA_LLI_Struct;      // DMA linked list item for continuous transfer

void configGPDMA(uint32_t* valor)
{
    // Initialize the DMA controller
    GPDMA_Init();

    // Set up the DMA linked list for continuous waveform transfer
    DMA_LLI_Struct.SrcAddr = (uint32_t)valor;              // Source: DAC waveform table
    DMA_LLI_Struct.DstAddr = (uint32_t) & (LPC_DAC->DACR); // Destination: DAC register
    DMA_LLI_Struct.NextLLI = (uint32_t)&DMA_LLI_Struct;    // Point to itself for continuous transfer
    DMA_LLI_Struct.Control = DMA_SIZE | (2 << 18)          // Source width: 32-bit
                             | (2 << 21)                   // Destination width: 32-bit
                             | (1 << 26);                  // Increment source address

    // Configure DMA channel for memory-to-peripheral transfer
    GPDMACfg.ChannelNum = DMA_CHANNEL_ZERO;         // Use channel 0
    GPDMACfg.SrcMemAddr = (uint32_t)valor;          // Source: DAC waveform table
    GPDMACfg.DstMemAddr = 0;                        // No memory destination (peripheral)
    GPDMACfg.TransferSize = DMA_SIZE;               // Transfer size: 60 samples
    GPDMACfg.TransferWidth = 0;                     // Not used
    GPDMACfg.TransferType = GPDMA_TRANSFERTYPE_M2P; // Memory-to-Peripheral transfer
    GPDMACfg.SrcConn = 0;                           // Source is memory
    GPDMACfg.DstConn = GPDMA_CONN_DAC;              // Destination: DAC connection
    GPDMACfg.DMALLI = (uint32_t)&DMA_LLI_Struct;    // Linked list for continuous transfer

    // Apply DMA configuration
    GPDMA_Setup(&GPDMACfg);
}