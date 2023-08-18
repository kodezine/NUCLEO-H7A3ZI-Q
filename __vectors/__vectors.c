#include <stdint.h>
#include "stm32h7xx.h"
#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6100100)
    #include "__vectors_ac6.h"
#elif defined(__GNUC__)
    #if defined(__clang__)
        #include "__vectors_llvm.h"
    #else
        //#include "__vectors_gcc.h"
    #endif
#endif
#include "system_ARMCM7.h"
#include "cmsis_compiler.h"

/******************************************************************************
 * @file     startup_<Device>.c
 * @brief    CMSIS-Core(M) Device Startup File for
 *           Device <Device>
 * @version  V1.0.0
 * @date     20. January 2021
 ******************************************************************************/
/*
 * Copyright (c) 2009-2021 Arm Limited. All rights reserved.
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Licensed under the Apache License, Version 2.0 (the License); you may
 * not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an AS IS BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

/*---------------------------------------------------------------------------
  External References
 *---------------------------------------------------------------------------*/
extern uint32_t __INITIAL_SP;
extern uint32_t __STACK_LIMIT;

#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
extern uint32_t __STACK_SEAL;
#endif

extern __NO_RETURN void __PROGRAM_START(void);

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void);
__NO_RETURN void Default_Handler(void);

/* ToDo: Add Cortex exception handler according the used Cortex-Core */
/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler                      (void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler                (void) __attribute__((weak));
void MemManage_Handler                (void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler                 (void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler               (void) __attribute__((weak, alias("Default_Handler")));
// void SecureFault_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
// void SecureFault_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
// void SecureFault_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
// void SecureFault_Handler                (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler                      (void) __attribute__((weak, alias("Default_Handler")));
void DebugMon_Handler                 (void) __attribute__((weak, alias("Default_Handler")));
// void SecureFault_Handler              (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler                   (void) __attribute__((weak, alias("Default_Handler")));
void SysTick_Handler                  (void) __attribute__((weak, alias("Default_Handler")));

/* Add your device specific interrupt handler */
/*---------------------------------------------------------------------------
  ISR
 *---------------------------------------------------------------------------*/
void WWDG_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void PVD_PVM_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void RTC_TAMP_STAMP_CSS_LSE_IRQHandler (void) __attribute__((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void FLASH_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void RCC_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void EXTI0_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void EXTI1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void EXTI2_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void EXTI3_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void EXTI4_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void ADC_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN1_IT0_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN2_IT0_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN1_IT1_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN2_IT1_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_BRK_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_UP_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_TRG_COM_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void TIM2_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void TIM3_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void TIM4_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SPI1_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SPI2_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void USART1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void USART2_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void USART3_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM2_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_BRK_TIM12_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_UP_TIM13_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_TRG_COM_TIM14_IRQHandler     (void) __attribute__((weak, alias("Default_Handler")));
void TIM8_CC_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void FMC_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void SDMMC1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void TIM5_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SPI3_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void UART4_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void UART5_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void TIM6_DAC_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void TIM7_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void FDCAN_CAL_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT4_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT5_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT6_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT7_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler           (void) __attribute__((weak, alias("Default_Handler")));
void USART6_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_OUT_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_EP1_IN_IRQHandler          (void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_WKUP_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void OTG_HS_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void DCMI_PSSI_IRQHandler              (void) __attribute__((weak, alias("Default_Handler")));
// // void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void RNG_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void FPU_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void UART7_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void UART8_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SPI4_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SPI5_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SPI6_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void SAI1_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void LTDC_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void LTDC_ER_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void DMA2D_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void SAI2_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void OCTOSPI1_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void CEC_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void I2C4_EV_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void I2C4_ER_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void SPDIF_RX_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void DMAMUX1_OVR_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT0_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT1_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT2_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void DFSDM1_FLT3_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void SWPMI1_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void TIM15_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void TIM16_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void TIM17_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void MDIOS_WKUP_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void MDIOS_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void JPEG_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void MDMA_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void SDMMC2_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void HSEM1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void DAC2_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void DMAMUX2_OVR_IRQHandler            (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel0_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel1_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel2_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel3_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel4_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel5_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel6_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void BDMA2_Channel7_IRQHandler         (void) __attribute__((weak, alias("Default_Handler")));
void COMP_IRQHandler                   (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM2_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void LPTIM3_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void UART9_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
void USART10_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
void LPUART1_IRQHandler                (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void CRS_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
void ECC_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void DTS_IRQHandler                    (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void WAKEUP_PIN_IRQHandler             (void) __attribute__((weak, alias("Default_Handler")));
void OCTOSPI2_IRQHandler               (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
// void 0                                 (void) __attribute__((weak, alias("Default_Handler")));
void GFXMMU_IRQHandler                 (void) __attribute__((weak, alias("Default_Handler")));
void BDMA1_IRQHandler                  (void) __attribute__((weak, alias("Default_Handler")));
/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined(__GNUC__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wpedantic"
#endif

/* ToDo: Add Cortex exception vectors according the used Cortex-Core */
extern const VECTOR_TABLE_Type __VECTOR_TABLE[255];
const VECTOR_TABLE_Type __VECTOR_TABLE[255] __VECTOR_TABLE_ATTRIBUTE = {
    (VECTOR_TABLE_Type)(&__INITIAL_SP)                    , /*     Initial Stack Pointer */
    (VECTOR_TABLE_Type)&Reset_Handler                     , /*     Reset Handler */
    (VECTOR_TABLE_Type)&NMI_Handler                       , /* -14 NMI Handler */
    (VECTOR_TABLE_Type)&HardFault_Handler                 , /* -13 Hard Fault Handler */
    (VECTOR_TABLE_Type)&MemManage_Handler                 , /* -12 MPU Fault Handler */
    (VECTOR_TABLE_Type)&BusFault_Handler                  , /* -11 Bus Fault Handler */
    (VECTOR_TABLE_Type)&UsageFault_Handler                , /* -10 Usage Fault Handler */
    (VECTOR_TABLE_Type)0                                  , /*  -9 Secure Fault Handler */
    (VECTOR_TABLE_Type)0                                  , /*     Reserved */
    (VECTOR_TABLE_Type)0                                  , /*     Reserved */
    (VECTOR_TABLE_Type)0                                  , /*     Reserved */
    (VECTOR_TABLE_Type)&SVC_Handler                       , /*  -5 SVCall Handler */
    (VECTOR_TABLE_Type)&DebugMon_Handler                  , /*  -4 Debug Monitor Handler */
    (VECTOR_TABLE_Type)0                                  , /*     Reserved */
    (VECTOR_TABLE_Type)&PendSV_Handler                    , /*  -2 PendSV Handler */
    (VECTOR_TABLE_Type)&SysTick_Handler                   , /*  -1 SysTick Handler */
    (VECTOR_TABLE_Type)&WWDG_IRQHandler                   , /* Window WatchDog              */
    (VECTOR_TABLE_Type)&PVD_PVM_IRQHandler                , /* PVD/PVM through EXTI Line detection */
    (VECTOR_TABLE_Type)&RTC_TAMP_STAMP_CSS_LSE_IRQHandler , /* Tamper and TimeStamps through the EXTI line */
    (VECTOR_TABLE_Type)&RTC_WKUP_IRQHandler               , /* RTC Wakeup through the EXTI line */
    (VECTOR_TABLE_Type)&FLASH_IRQHandler                  , /* FLASH                        */
    (VECTOR_TABLE_Type)&RCC_IRQHandler                    , /* RCC                          */
    (VECTOR_TABLE_Type)&EXTI0_IRQHandler                  , /* EXTI Line0                   */
    (VECTOR_TABLE_Type)&EXTI1_IRQHandler                  , /* EXTI Line1                   */
    (VECTOR_TABLE_Type)&EXTI2_IRQHandler                  , /* EXTI Line2                   */
    (VECTOR_TABLE_Type)&EXTI3_IRQHandler                  , /* EXTI Line3                   */
    (VECTOR_TABLE_Type)&EXTI4_IRQHandler                  , /* EXTI Line4                   */
    (VECTOR_TABLE_Type)&DMA1_Stream0_IRQHandler           , /* DMA1 Stream 0                */
    (VECTOR_TABLE_Type)&DMA1_Stream1_IRQHandler           , /* DMA1 Stream 1                */
    (VECTOR_TABLE_Type)&DMA1_Stream2_IRQHandler           , /* DMA1 Stream 2                */
    (VECTOR_TABLE_Type)&DMA1_Stream3_IRQHandler           , /* DMA1 Stream 3                */
    (VECTOR_TABLE_Type)&DMA1_Stream4_IRQHandler           , /* DMA1 Stream 4                */
    (VECTOR_TABLE_Type)&DMA1_Stream5_IRQHandler           , /* DMA1 Stream 5                */
    (VECTOR_TABLE_Type)&DMA1_Stream6_IRQHandler           , /* DMA1 Stream 6                */
    (VECTOR_TABLE_Type)&ADC_IRQHandler                    , /* ADC1, ADC2 and ADC3s         */
    (VECTOR_TABLE_Type)&FDCAN1_IT0_IRQHandler             , /* FDCAN1 interrupt line 0      */
    (VECTOR_TABLE_Type)&FDCAN2_IT0_IRQHandler             , /* FDCAN2 interrupt line 0      */
    (VECTOR_TABLE_Type)&FDCAN1_IT1_IRQHandler             , /* FDCAN1 interrupt line 1      */
    (VECTOR_TABLE_Type)&FDCAN2_IT1_IRQHandler             , /* FDCAN2 interrupt line 1      */
    (VECTOR_TABLE_Type)&EXTI9_5_IRQHandler                , /* External Line[9:5]s          */
    (VECTOR_TABLE_Type)&TIM1_BRK_IRQHandler               , /* TIM1 Break interrupt         */
    (VECTOR_TABLE_Type)&TIM1_UP_IRQHandler                , /* TIM1 Update interrupt        */
    (VECTOR_TABLE_Type)&TIM1_TRG_COM_IRQHandler           , /* TIM1 Trigger and Commutation interrupt */
    (VECTOR_TABLE_Type)&TIM1_CC_IRQHandler                , /* TIM1 Capture Compare         */
    (VECTOR_TABLE_Type)&TIM2_IRQHandler                   , /* TIM2                         */
    (VECTOR_TABLE_Type)&TIM3_IRQHandler                   , /* TIM3                         */
    (VECTOR_TABLE_Type)&TIM4_IRQHandler                   , /* TIM4                         */
    (VECTOR_TABLE_Type)&I2C1_EV_IRQHandler                , /* I2C1 Event                   */
    (VECTOR_TABLE_Type)&I2C1_ER_IRQHandler                , /* I2C1 Error                   */
    (VECTOR_TABLE_Type)&I2C2_EV_IRQHandler                , /* I2C2 Event                   */
    (VECTOR_TABLE_Type)&I2C2_ER_IRQHandler                , /* I2C2 Error                   */
    (VECTOR_TABLE_Type)&SPI1_IRQHandler                   , /* SPI1                         */
    (VECTOR_TABLE_Type)&SPI2_IRQHandler                   , /* SPI2                         */
    (VECTOR_TABLE_Type)&USART1_IRQHandler                 , /* USART1                       */
    (VECTOR_TABLE_Type)&USART2_IRQHandler                 , /* USART2                       */
    (VECTOR_TABLE_Type)&USART3_IRQHandler                 , /* USART3                       */
    (VECTOR_TABLE_Type)&EXTI15_10_IRQHandler              , /* External Line[15:10]s        */
    (VECTOR_TABLE_Type)&RTC_Alarm_IRQHandler              , /* RTC Alarm (A and B) through EXTI Line */
    (VECTOR_TABLE_Type)&DFSDM2_IRQHandler                 , /* DFSDM2 Interrupt             */
    (VECTOR_TABLE_Type)&TIM8_BRK_TIM12_IRQHandler         , /* TIM8 Break and TIM12         */
    (VECTOR_TABLE_Type)&TIM8_UP_TIM13_IRQHandler          , /* TIM8 Update and TIM13        */
    (VECTOR_TABLE_Type)&TIM8_TRG_COM_TIM14_IRQHandler     , /* TIM8 Trigger and Commutation and TIM14 */
    (VECTOR_TABLE_Type)&TIM8_CC_IRQHandler                , /* TIM8 Capture Compare         */
    (VECTOR_TABLE_Type)&DMA1_Stream7_IRQHandler           , /* DMA1 Stream7                 */
    (VECTOR_TABLE_Type)&FMC_IRQHandler                    , /* FMC                          */
    (VECTOR_TABLE_Type)&SDMMC1_IRQHandler                 , /* SDMMC1                       */
    (VECTOR_TABLE_Type)&TIM5_IRQHandler                   , /* TIM5                         */
    (VECTOR_TABLE_Type)&SPI3_IRQHandler                   , /* SPI3                         */
    (VECTOR_TABLE_Type)&UART4_IRQHandler                  , /* UART4                        */
    (VECTOR_TABLE_Type)&UART5_IRQHandler                  , /* UART5                        */
    (VECTOR_TABLE_Type)&TIM6_DAC_IRQHandler               , /* TIM6 and DAC1&2 underrun errors */
    (VECTOR_TABLE_Type)&TIM7_IRQHandler                   , /* TIM7                         */
    (VECTOR_TABLE_Type)&DMA2_Stream0_IRQHandler           , /* DMA2 Stream 0                */
    (VECTOR_TABLE_Type)&DMA2_Stream1_IRQHandler           , /* DMA2 Stream 1                */
    (VECTOR_TABLE_Type)&DMA2_Stream2_IRQHandler           , /* DMA2 Stream 2                */
    (VECTOR_TABLE_Type)&DMA2_Stream3_IRQHandler           , /* DMA2 Stream 3                */
    (VECTOR_TABLE_Type)&DMA2_Stream4_IRQHandler           , /* DMA2 Stream 4                */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&FDCAN_CAL_IRQHandler              , /* FDCAN calibration unit interrupt*/
    (VECTOR_TABLE_Type)&DFSDM1_FLT4_IRQHandler            , /* DFSDM Filter4 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT5_IRQHandler            , /* DFSDM Filter5 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT6_IRQHandler            , /* DFSDM Filter6 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT7_IRQHandler            , /* DFSDM Filter7 Interrupt      */
    (VECTOR_TABLE_Type)&DMA2_Stream5_IRQHandler           , /* DMA2 Stream 5                */
    (VECTOR_TABLE_Type)&DMA2_Stream6_IRQHandler           , /* DMA2 Stream 6                */
    (VECTOR_TABLE_Type)&DMA2_Stream7_IRQHandler           , /* DMA2 Stream 7                */
    (VECTOR_TABLE_Type)&USART6_IRQHandler                 , /* USART6                       */
    (VECTOR_TABLE_Type)&I2C3_EV_IRQHandler                , /* I2C3 event                   */
    (VECTOR_TABLE_Type)&I2C3_ER_IRQHandler                , /* I2C3 error                   */
    (VECTOR_TABLE_Type)&OTG_HS_EP1_OUT_IRQHandler         , /* USB OTG HS End Point 1 Out   */
    (VECTOR_TABLE_Type)&OTG_HS_EP1_IN_IRQHandler          , /* USB OTG HS End Point 1 In    */
    (VECTOR_TABLE_Type)&OTG_HS_WKUP_IRQHandler            , /* USB OTG HS Wakeup through EXTI */
    (VECTOR_TABLE_Type)&OTG_HS_IRQHandler                 , /* USB OTG HS                   */
    (VECTOR_TABLE_Type)&DCMI_PSSI_IRQHandler              , /* DCMI, PSSI                   */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&RNG_IRQHandler                    , /* RNG                          */
    (VECTOR_TABLE_Type)&FPU_IRQHandler                    , /* FPU                          */
    (VECTOR_TABLE_Type)&UART7_IRQHandler                  , /* UART7                        */
    (VECTOR_TABLE_Type)&UART8_IRQHandler                  , /* UART8                        */
    (VECTOR_TABLE_Type)&SPI4_IRQHandler                   , /* SPI4                         */
    (VECTOR_TABLE_Type)&SPI5_IRQHandler                   , /* SPI5                         */
    (VECTOR_TABLE_Type)&SPI6_IRQHandler                   , /* SPI6                         */
    (VECTOR_TABLE_Type)&SAI1_IRQHandler                   , /* SAI1                         */
    (VECTOR_TABLE_Type)&LTDC_IRQHandler                   , /* LTDC                         */
    (VECTOR_TABLE_Type)&LTDC_ER_IRQHandler                , /* LTDC error                   */
    (VECTOR_TABLE_Type)&DMA2D_IRQHandler                  , /* DMA2D                        */
    (VECTOR_TABLE_Type)&SAI2_IRQHandler                   , /* SAI2                         */
    (VECTOR_TABLE_Type)&OCTOSPI1_IRQHandler               , /* OCTOSPI1                     */
    (VECTOR_TABLE_Type)&LPTIM1_IRQHandler                 , /* LPTIM1                       */
    (VECTOR_TABLE_Type)&CEC_IRQHandler                    , /* HDMI_CEC                     */
    (VECTOR_TABLE_Type)&I2C4_EV_IRQHandler                , /* I2C4 Event                   */
    (VECTOR_TABLE_Type)&I2C4_ER_IRQHandler                , /* I2C4 Error                   */
    (VECTOR_TABLE_Type)&SPDIF_RX_IRQHandler               , /* SPDIF_RX                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&DMAMUX1_OVR_IRQHandler            , /* DMAMUX1 Overrun interrupt    */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&DFSDM1_FLT0_IRQHandler            , /* DFSDM Filter0 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT1_IRQHandler            , /* DFSDM Filter1 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT2_IRQHandler            , /* DFSDM Filter2 Interrupt      */
    (VECTOR_TABLE_Type)&DFSDM1_FLT3_IRQHandler            , /* DFSDM Filter3 Interrupt      */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&SWPMI1_IRQHandler                 , /* Serial Wire Interface 1 global interrupt */
    (VECTOR_TABLE_Type)&TIM15_IRQHandler                  , /* TIM15 global Interrupt      */
    (VECTOR_TABLE_Type)&TIM16_IRQHandler                  , /* TIM16 global Interrupt      */
    (VECTOR_TABLE_Type)&TIM17_IRQHandler                  , /* TIM17 global Interrupt      */
    (VECTOR_TABLE_Type)&MDIOS_WKUP_IRQHandler             , /* MDIOS Wakeup  Interrupt     */
    (VECTOR_TABLE_Type)&MDIOS_IRQHandler                  , /* MDIOS global Interrupt      */
    (VECTOR_TABLE_Type)&JPEG_IRQHandler                   , /* JPEG global Interrupt       */
    (VECTOR_TABLE_Type)&MDMA_IRQHandler                   , /* MDMA global Interrupt       */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                    */
    (VECTOR_TABLE_Type)&SDMMC2_IRQHandler                 , /* SDMMC2 global Interrupt     */
    (VECTOR_TABLE_Type)&HSEM1_IRQHandler                  , /* HSEM1 global Interrupt      */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                    */
    (VECTOR_TABLE_Type)&DAC2_IRQHandler                   , /* DAC2 global Interrupt       */
    (VECTOR_TABLE_Type)&DMAMUX2_OVR_IRQHandler            , /* DMAMUX Overrun interrupt    */
    (VECTOR_TABLE_Type)&BDMA2_Channel0_IRQHandler         , /* BDMA2 Channel 0 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel1_IRQHandler         , /* BDMA2 Channel 1 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel2_IRQHandler         , /* BDMA2 Channel 2 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel3_IRQHandler         , /* BDMA2 Channel 3 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel4_IRQHandler         , /* BDMA2 Channel 4 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel5_IRQHandler         , /* BDMA2 Channel 5 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel6_IRQHandler         , /* BDMA2 Channel 6 global Interrupt */
    (VECTOR_TABLE_Type)&BDMA2_Channel7_IRQHandler         , /* BDMA2 Channel 7 global Interrupt */
    (VECTOR_TABLE_Type)&COMP_IRQHandler                   , /* COMP global Interrupt      */
    (VECTOR_TABLE_Type)&LPTIM2_IRQHandler                 , /* LP TIM2 global interrupt     */
    (VECTOR_TABLE_Type)&LPTIM3_IRQHandler                 , /* LP TIM3 global interrupt     */
    (VECTOR_TABLE_Type)&UART9_IRQHandler                  , /* UART9 global interrupt       */
    (VECTOR_TABLE_Type)&USART10_IRQHandler                , /* USART10 global interrupt     */
    (VECTOR_TABLE_Type)&LPUART1_IRQHandler                , /* LP UART1 interrupt           */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&CRS_IRQHandler                    , /* Clock Recovery Global Interrupt */
    (VECTOR_TABLE_Type)&ECC_IRQHandler                    , /* ECC diagnostic Global Interrupt */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&DTS_IRQHandler                    , /* DTS                          */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&WAKEUP_PIN_IRQHandler             , /* Interrupt for all 6 wake-up pins */
    (VECTOR_TABLE_Type)&OCTOSPI2_IRQHandler               , /* OCTOSPI2                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)0                                  , /* Reserved                     */
    (VECTOR_TABLE_Type)&GFXMMU_IRQHandler                 , /* GFXMMU                       */
    (VECTOR_TABLE_Type)&BDMA1_IRQHandler                  , /* BDMA1                        */
};

#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler(void)
{
    __set_PSP((uint32_t)(&__INITIAL_SP));

/* ToDo: Initialize stack limit register for Armv8-M Main Extension based processors*/
//    __set_MSP((uint32_t)(&__STACK_LIMIT));
//    __set_PSP((uint32_t)(&__STACK_LIMIT));

/* ToDo: Add stack sealing for Armv8-M based processors */
#if defined(__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
    __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

    SystemInit();      /* CMSIS System Initialization */
    __PROGRAM_START(); /* Enter PreMain (C library entry point) */
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#endif

/*---------------------------------------------------------------------------
  Hard Fault Handler
 *---------------------------------------------------------------------------*/
void HardFault_Handler(void)
{
    while (1)
        ;
}

/*---------------------------------------------------------------------------
  Default Handler for Exceptions / Interrupts
 *---------------------------------------------------------------------------*/
void Default_Handler(void)
{
    while (1)
        ;
}

#if defined(__ARMCC_VERSION) && (__ARMCC_VERSION >= 6010050)
#pragma clang diagnostic pop
#endif
