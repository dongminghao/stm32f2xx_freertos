/**
  ******************************************************************************
  * @file    serial_debug.h
  * @author  MCD Application Team
  * @version V1.1.0
  * @date    07-October-2011
  * @brief   Header for serial_debug.c file
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __SERIAL_DEBUG_H
#define __SERIAL_DEBUG_H

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
#define COMn                             1
#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCC_APB2Periph_USART1 
#define EVAL_COM1_TX_PIN                 GPIO_Pin_6
#define EVAL_COM1_TX_GPIO_PORT           GPIOB
#define EVAL_COM1_TX_GPIO_CLK            RCC_AHB1Periph_GPIOB
#define EVAL_COM1_TX_SOURCE              GPIO_PinSource6
#define EVAL_COM1_TX_AF                  GPIO_AF_USART1
#define EVAL_COM1_RX_PIN                 GPIO_Pin_7
#define EVAL_COM1_RX_GPIO_PORT           GPIOB
#define EVAL_COM1_RX_GPIO_CLK            RCC_AHB1Periph_GPIOB
#define EVAL_COM1_RX_SOURCE              GPIO_PinSource7
#define EVAL_COM1_RX_AF                  GPIO_AF_USART1
#define EVAL_COM1_IRQn                   USART3_IRQn

typedef enum 
{
  COM1 = 0,
  COM2 = 1
} COM_TypeDef;

#ifdef SERIAL_DEBUG
  void DebugComPort_Init(void);
#endif



#endif /* __SERIAL_DEBUG_H */  


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
