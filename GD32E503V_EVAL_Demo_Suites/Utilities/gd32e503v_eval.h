/*!
    \file    gd32e503v_eval.h
    \brief   definitions for GD32E503V_EVAL's leds, keys and COM ports hardware resources

    \version 2023-08-17, V1.3.1, demo for GD32E50x
*/

/*
    Copyright (c) 2023, GigaDevice Semiconductor Inc.

    Redistribution and use in source and binary forms, with or without modification, 
are permitted provided that the following conditions are met:

    1. Redistributions of source code must retain the above copyright notice, this 
       list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright notice, 
       this list of conditions and the following disclaimer in the documentation 
       and/or other materials provided with the distribution.
    3. Neither the name of the copyright holder nor the names of its contributors 
       may be used to endorse or promote products derived from this software without 
       specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED 
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. 
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, 
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT 
NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR 
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) 
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY 
OF SUCH DAMAGE.
*/

#ifndef GD32E503V_EVAL_H
#define GD32E503V_EVAL_H

#ifdef __cplusplus
 extern "C" {
#endif

#include "gd32e50x.h"
     
/* exported types */
typedef enum 
{
    LED1 = 0,
    LED2 = 1,
    LED3 = 2,
    LED4 = 3
} led_typedef_enum;

typedef enum 
{
    KEY_A = 0,
    KEY_B = 1,
    KEY_C = 2,
    KEY_D = 3,
    KEY_CET = 4
} key_typedef_enum;

typedef enum 
{
    KEY_MODE_GPIO = 0,
    KEY_MODE_EXTI = 1
} keymode_typedef_enum;

typedef enum 
{
    RS485 		= 0,		//rs485 master
    RS485_2 	= 1,  	//rs485
		WIFI_BLE 	= 2,		//wifi & ble
		RS485_4 	= 3,  	//rs485
	  METER 		= 4,		//meter
		G4				= 5			//4g			 
} com_typedef_enum;

#define BUFFER_SIZE             				 256
#define COMn                             6U			//中间有一个
extern  uint32_t COM_EVAL[COMn];


#define EVAL_COM0                        USART0
#define EVAL_COM0_CLK                    RCU_USART0
#define EVAL_COM0_TX_PIN                 GPIO_PIN_9
#define EVAL_COM0_RX_PIN                 GPIO_PIN_10
#define EVAL_COM0_GPIO_PORT              GPIOA
#define EVAL_COM0_GPIO_CLK               RCU_GPIOA
#define EVAL_COM0_IRQn               		 USART0_IRQn

#define EVAL_COM1                        USART1
#define EVAL_COM1_CLK                    RCU_USART1
//#define EVAL_COM1_TX_PIN               GPIO_PIN_2
//#define EVAL_COM1_RX_PIN               GPIO_PIN_3
//#define EVAL_COM1_GPIO_PORT            GPIOA
//#define EVAL_COM1_GPIO_CLK             RCU_GPIOA
#define EVAL_COM1_TX_PIN                 GPIO_PIN_5
#define EVAL_COM1_RX_PIN                 GPIO_PIN_6
#define EVAL_COM1_GPIO_PORT              GPIOD
#define EVAL_COM1_GPIO_CLK               RCU_GPIOD
#define EVAL_COM1_IRQn               		 USART1_IRQn

#define EVAL_COM2                        USART2
#define EVAL_COM2_CLK                    RCU_USART2
#define EVAL_COM2_TX_PIN                 GPIO_PIN_10
#define EVAL_COM2_RX_PIN                 GPIO_PIN_11
#define EVAL_COM2_GPIO_PORT              GPIOB
#define EVAL_COM2_GPIO_CLK               RCU_GPIOB
#define EVAL_COM2_IRQn               		 USART2_IRQn

#define EVAL_COM3                        UART3
#define EVAL_COM3_CLK                    RCU_UART3
#define EVAL_COM3_TX_PIN                 GPIO_PIN_10
#define EVAL_COM3_RX_PIN                 GPIO_PIN_11
#define EVAL_COM3_GPIO_PORT              GPIOC
#define EVAL_COM3_GPIO_CLK               RCU_GPIOC
#define EVAL_COM3_IRQn               		 UART3_IRQn

//pc12=tx  pd2=rx
#define EVAL_COM4                        UART4
#define EVAL_COM4_CLK                    RCU_UART4
#define EVAL_COM4_TX_PIN                 GPIO_PIN_12	//PC12
#define EVAL_COM4_RX_PIN                 GPIO_PIN_2		//PD2 RX
#define EVAL_COM4_GPIO_PORT              GPIOC
#define EVAL_COM4_GPIO_CLK               RCU_GPIOC
#define EVAL_COM4_IRQn               		 UART4_IRQn

#define EVAL_COM5                        USART5
#define EVAL_COM5_CLK                    RCU_USART5
#define EVAL_COM5_TX_PIN                 GPIO_PIN_6
#define EVAL_COM5_RX_PIN                 GPIO_PIN_7
#define EVAL_COM5_GPIO_PORT              GPIOC
#define EVAL_COM5_GPIO_CLK               RCU_GPIOC
#define EVAL_COM5_IRQn               		 USART5_IRQn

/* eval board low layer led */
#define LEDn                             4U

#define LED1_PIN                         GPIO_PIN_0
#define LED1_GPIO_PORT                   GPIOC
#define LED1_GPIO_CLK                    RCU_GPIOC
  
#define LED2_PIN                         GPIO_PIN_2
#define LED2_GPIO_PORT                   GPIOC
#define LED2_GPIO_CLK                    RCU_GPIOC
  
#define LED3_PIN                         GPIO_PIN_0
#define LED3_GPIO_PORT                   GPIOE
#define LED3_GPIO_CLK                    RCU_GPIOE
  
#define LED4_PIN                         GPIO_PIN_1
#define LED4_GPIO_PORT                   GPIOE
#define LED4_GPIO_CLK                    RCU_GPIOE


#define KEYn                             5U

/* wakeup push-button */
#define KEY_A_PIN                        GPIO_PIN_0
#define KEY_A_GPIO_PORT                  GPIOA
#define KEY_A_GPIO_CLK                   RCU_GPIOA
#define KEY_A_EXTI_LINE                  EXTI_0
#define KEY_A_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOA
#define KEY_A_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_0
#define KEY_A_EXTI_IRQn                  EXTI0_IRQn

/* tamper push-button */
#define KEY_B_PIN                        GPIO_PIN_13
#define KEY_B_GPIO_PORT                  GPIOC
#define KEY_B_GPIO_CLK                   RCU_GPIOC
#define KEY_B_EXTI_LINE                  EXTI_13
#define KEY_B_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOC
#define KEY_B_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_13
#define KEY_B_EXTI_IRQn                  EXTI10_15_IRQn

/* user push-button */
#define KEY_C_PIN                        GPIO_PIN_14
#define KEY_C_GPIO_PORT                  GPIOB
#define KEY_C_GPIO_CLK                   RCU_GPIOB
#define KEY_C_EXTI_LINE                  EXTI_14
#define KEY_C_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOB
#define KEY_C_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_14
#define KEY_C_EXTI_IRQn                  EXTI10_15_IRQn

/* extension push-button */
#define KEY_D_PIN                        GPIO_PIN_5
#define KEY_D_GPIO_PORT                  GPIOC
#define KEY_D_GPIO_CLK                   RCU_GPIOC
#define KEY_D_EXTI_LINE                  EXTI_5
#define KEY_D_EXTI_PORT_SOURCE           GPIO_PORT_SOURCE_GPIOC
#define KEY_D_EXTI_PIN_SOURCE            GPIO_PIN_SOURCE_5
#define KEY_D_EXTI_IRQn                  EXTI5_9_IRQn

/* extension push-button */
#define KEY_CET_PIN                      GPIO_PIN_4
#define KEY_CET_GPIO_PORT                GPIOC
#define KEY_CET_GPIO_CLK                 RCU_GPIOC
#define KEY_CET_EXTI_LINE                EXTI_4
#define KEY_CET_EXTI_PORT_SOURCE         GPIO_PORT_SOURCE_GPIOC
#define KEY_CET_EXTI_PIN_SOURCE          GPIO_PIN_SOURCE_4
#define KEY_CET_EXTI_IRQn                EXTI4_IRQn

/* function declarations */
/* configure led GPIO */
void gd_eval_led_init(led_typedef_enum lednum);
/* turn on selected led */
void gd_eval_led_on(led_typedef_enum lednum);
/* turn off selected led */
void gd_eval_led_off(led_typedef_enum lednum);
/* toggle the selected led */
void gd_eval_led_toggle(led_typedef_enum lednum);
/* configure key */
void gd_eval_key_init(key_typedef_enum key_num, keymode_typedef_enum key_mode);
/* return the selected key state */
uint8_t gd_eval_key_state_get(key_typedef_enum key);
/* configure COM port */
//void gd_eval_com_init(uint32_t com);
void gd_eval_com_init(com_typedef_enum com_num,uint32_t baudval,uint8_t nvic_irq_pre_priority,uint8_t nvic_irq_sub_priority);
void Com_Send(com_typedef_enum com_num,uint8_t *send_buff,uint32_t length);	
#ifdef __cplusplus
}
#endif

#endif /* GD32E503V_EVAL_H */
