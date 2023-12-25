/*******************************************************************************
* �ļ���	: ParamAccess.h
* ����		: Yang
* �汾		: V1.0.0
* ����ʱ��	: 10/16/2014
* ����		: ϵͳ�����Ĵ洢 �� ��ȡ
*******************************************************************************/

#ifndef _PARAM_ACCESS_
#define _PARAM_ACCESS_

/* Includes ------------------------------------------------------------------*/


/* Exported types ------------------------------------------------------------*/

/* Exported macro ------------------------------------------------------------*/
#define LOW_LINE_OCV 2800

#define START_ADDR (0x8000000 | 0x30000)

/*�洢״̬*/
#define STATE_ADDR	 (START_ADDR | (0x0F<<11))	

/*����洢*/
#define TEMP_RI_STATE_ADDR  (START_ADDR | (0<<11)) 	//TEMP�洢״̬
#define TEMP10_RI_STATE_ADDR  (START_ADDR | (0<<11))+2 //TEMP10�洢״̬
#define TEMP0_RI_STATE_ADDR  (START_ADDR | (0<<11))+4  //TEMP0�洢״̬

#define TEMP_RI_ADDR 		(START_ADDR | (1<<11))  //��������洢
#define TEMP10_RI_ADDR 		(START_ADDR | (2<<11))//10��ʱ������
#define TEMP0_RI_ADDR		(START_ADDR | (3<<11))//0��ʱ������

/*OCV_SOC���ݱ�*/
#define OCV_SOC_ADDR	(START_ADDR | (0x0B<<11))		 //OCV SOC	2.80V ��Ӧ (0x8000000 | 0x3B000),2.81V (0x8000000 | 0x3B004)


#define Qmax_ADDR	(START_ADDR | (0x0C<<11)|(0x00<<10))
#define AEG_ADDR	(START_ADDR | (0x0D<<11)) //ʹ�ô���

#define RI_SHEET_ADDR	(START_ADDR | 0x01<<12)




/* Exported functions ------------------------------------------------------- */
/*������ʼ��*/

/*�洢״̬*/
/* Age Qmax OCV_SOC Ri*/
extern U16 Read_Store_State(void);
extern void Store_State(U16 data);	

/*�����*/
extern void Store_Ri(U16* pdata,U16 length);
extern void Store_Init_Ri(U16 temp,U16 r);
extern U16 Read_Ri(U16 temp,U16 soc);

/*OCV��SOC��*/
extern void Store_OCV_SOC(U16 ocv,U16 soc);	
extern U16 Read_OCV_SOC(U16 ocv);

extern U16 OCVtoSOC(U16 ocv);
extern U16 SOCtoOCV(U16 soc);

/*Qmax*/
extern void Store_Qmax(U16 qmax);			 
extern U16 Read_Qmax(void);

/*age,ʹ�ô���*/
extern void Store_Age(U16 age);					
extern U16 Read_Age(void);

#endif

/*****************************END OF FILE**************************************/
