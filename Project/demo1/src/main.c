/**
  ******************************************************************************
  * @file    Project/STM32F2xx_StdPeriph_Template/main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    18-April-2011
  * @brief   Main program body
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

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup Template_Project
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
#define MESSAGE1   "     STM32F2xx      " 
#define MESSAGE2   " Device running on " 
#define MESSAGE3   "   STM322xG-EVAL    " 
#define HELLO1_TASK_PRIO    ( tskIDLE_PRIORITY + 1 )
#define HELLO2_TASK_PRIO    ( tskIDLE_PRIORITY + 2 )
#define Hello_TASK_STACK_SIZE			( configMINIMAL_STACK_SIZE + 50 )
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
static __IO uint32_t TimingDelay;

/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
void Hello1(void * pvParameters);
void Hello2(void * pvParameters);
/**
  * @brief  Main program.
  * @param  None
  * @retval None
  */
int main(void)
{
//  RCC_ClocksTypeDef RCC_Clocks;

  /*!< At this stage the microcontroller clock setting is already configured, 
       this is done through SystemInit() function which is called from startup
       file (startup_stm32f2xx.s) before to branch to application main.
       To reconfigure the default setting of SystemInit() function, refer to
       system_stm32f2xx.c file
     */  

  /* SysTick end of count event each 10ms */
//  RCC_GetClocksFreq(&RCC_Clocks);
//  SysTick_Config(RCC_Clocks.HCLK_Frequency / 1000);
#ifdef SERIAL_DEBUG
	DebugComPort_Init();
#endif 

  /* Add your application code here
     */
//	printf(MESSAGE2);
//	printf("FreeRTOS demo1!\n");
  /* Infinite loop */
	
	xTaskCreate( Hello1, ( signed portCHAR * ) "Hello1", Hello_TASK_STACK_SIZE, NULL, HELLO1_TASK_PRIO, NULL );	
	xTaskCreate( Hello2, ( signed portCHAR * ) "Hello2", Hello_TASK_STACK_SIZE, NULL, HELLO2_TASK_PRIO, NULL );	
	#ifdef SERIAL_DEBUG
	printf("task created!\n");
	#endif
	 /* Start scheduler */
  vTaskStartScheduler();
	#ifdef SERIAL_DEBUG
	printf("start OS! \n");
	#endif
  while (1)
  {
    
		
    /* Insert 50 ms delay */
    Delay(5);
//		printf("FreeRTOS demo1!\r\n");
    /* Insert 50 ms delay */
    Delay(5);
  }
}

/**
  * @brief  Inserts a delay time.
  * @param  nTime: specifies the delay time length, in 10 ms.
  * @retval None
  */
void Delay(__IO uint32_t nTime)
{
  TimingDelay = nTime;

  while(TimingDelay != 0);
}

/**
  * @brief  Decrements the TimingDelay variable.
  * @param  None
  * @retval None
  */
void TimingDelay_Decrement(void)
{
  if (TimingDelay != 0x00)
  { 
    TimingDelay--;
  }
}


/**
  * @brief  Toggle Led4 task
  * @param  pvParameters not used
  * @retval None
  */
void Hello1(void * pvParameters)
{
  for( ;; )
  {
    /* Toggle LED4 each 250ms */
    printf("this is Hello1!\r\n");
    vTaskDelay(250);
  }
}

/**
  * @brief  Toggle Led4 task
  * @param  pvParameters not used
  * @retval None
  */
void Hello2(void * pvParameters)
{
  for( ;; )
  {
    /* Toggle LED4 each 250ms */
    printf("This is Hello2!\r\n");
    vTaskDelay(250);
  }
}
#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
