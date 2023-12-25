#ifndef _LIBAT_H
#define _LIBAT_H

#include "gd32e50x.h"


/*锂电池单体数量*/
#define BAT_NUMBER 8

/*工作模式*/
#define WAIT_MODE  0x00  //闲置状态
#define CHARGE_MODE 0x01  //充电状态
#define DISCHARGE_MODE 0x02	//放电状态
#define	FLASH_WRITE_ADDRESS	0x000000
#define USER_R 2.4

struct LiBAT
{
		//电流、电压、电量比例系数都是0.01，温度是0.1，SOC是千分之一
		float Current;
		uint16_t Current_read;
		uint16_t Vmax;
		uint16_t Qleft_read;
		float Qleft;
		uint16_t QBAT;
		uint16_t SOC;
		uint16_t SOC_read;
		uint16_t Qmax;
		uint16_t Cycletimes;
		uint16_t SOH;
		uint16_t Vport;
		uint16_t Voltage[BAT_NUMBER];
		uint16_t R;
		uint16_t Temp;
		float Quse;
		uint8_t	Vmea[4];
		uint8_t Ccharge[4];
		uint8_t Cdischarge[4];
		int16_t Cchargevalue;
		int16_t Cdischargevalue;
		int16_t Cvalue;
		int16_t Vvalue;
		uint16_t Qfull;
		int16_t Vfull;
		int16_t Cfull;
		uint8_t	work_mode;
};

typedef struct
{
	uint16_t Temp;
	uint16_t SOC;
	uint32_t R;
}USE_R_Struct;

extern void LiBAT_Init(void);
extern void LiBAT_I_Integral(uint32_t time);
extern void LiBAT_Low_V(void); 
extern void LiBAT_Update(void);
extern void LiBAT_ShowQ(void);
extern void LiBAT_Send(void);
extern uint16_t LiBAT_OCV2SOC(uint16_t ocv);
extern uint16_t LiBAT_SOC2OCV(uint16_t soc);
extern void LiBAT_GetSensor(void);

extern void LiBAT_Mode(void);
extern uint8_t LiBAT_EndWork(void);
void LiBAT_UpdateRi(void);
float LiBAT_GetQuse(void);

extern void LiBAT_InitRiSheet(void);

extern void LiBAT_PrintR(void);

extern void LiBAT_PrintOCVSOC(void);


#endif
