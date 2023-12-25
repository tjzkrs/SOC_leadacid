#include "LiBAT.h"
#include "systick.h"
#include "gd32e50x.h"
#include "gd32e503v_eval.h"
#include "gd25qxx.h"

uint8_t	flash_read_buffer[10];
extern struct LiBAT LiBATPack;

extern uint8_t holdingregister[30], Libat_flag;

extern uint16_t OCVtoSOC(uint16_t ocv);
extern uint16_t SOCtoOCV(uint16_t soc);

uint16_t myabs(uint16_t a, uint16_t b)
{
		if(a > b)
		{
				return a - b;
		}
		else
		{
				return b - a;
		}
}

void LiBAT_Init(void)
{
		uint8_t i;
		uint16_t VfromFLASH, SOCfromFLASH, SOCfromV;
		spi_flash_buffer_read(flash_read_buffer, FLASH_WRITE_ADDRESS, 10);
		for(i = 0; i < 6; i++)
		{
				holdingregister[20 + i] = flash_read_buffer[i];
		}
		LiBATPack.Qfull = (uint16_t)(holdingregister[20] << 8) | holdingregister[21];
		LiBATPack.Vfull = (uint16_t)(holdingregister[22] << 8) | holdingregister[23];
		LiBATPack.Cfull = (uint16_t)(holdingregister[24] << 8) | holdingregister[25];
		if(LiBATPack.Qfull == 0)
		{
				LiBATPack.Qfull = 10000;
		}
		if(LiBATPack.Vfull == 0)
		{
				LiBATPack.Vfull = 2800;
		}
		if(LiBATPack.Cfull == 0)
		{
				LiBATPack.Cfull = 20;
		}
		VfromFLASH = ((uint16_t)(flash_read_buffer[8] << 8) | flash_read_buffer[9]) / 10;
		SOCfromFLASH = (uint16_t)(flash_read_buffer[6] << 8) | flash_read_buffer[7];
		if(myabs(VfromFLASH, LiBATPack.Vvalue) < 5)
		{
				LiBATPack.SOC = SOCfromFLASH;
		}
		else
		{
				SOCfromV = OCVtoSOC((uint16_t)(LiBATPack.Vvalue - LiBATPack.Current * USER_R + 0.5));
				if(myabs(SOCfromFLASH, SOCfromV) < 50)
				{
						LiBATPack.SOC = SOCfromFLASH;
				}
				else
				{
						LiBATPack.SOC = SOCfromV;
				}
		}
		if(Libat_flag == 1)
		{
				LiBATPack.SOC = LiBATPack.SOC_read;
				LiBATPack.Qleft = LiBATPack.Qleft_read;
		}
		else
		{
				LiBATPack.SOC = 600;
		}
		LiBATPack.Qfull = 30000;
		LiBATPack.Qleft = (float)LiBATPack.SOC * LiBATPack.Qfull / 1000;
		LiBATPack.work_mode = WAIT_MODE;
}

void LiBAT_I_Integral(uint32_t time)
{  
		uint16_t Qleft_int;
		uint16_t SOC_calc;
		/*Q¸üÐÂ*/
		if(LiBATPack.SOC == 1000 && LiBATPack.Current > 0 || LiBATPack.SOC == 0 && LiBATPack.Current < 0)
		{
				LiBATPack.Qleft = LiBATPack.Qleft;
		}
		else
		{
				LiBATPack.Qleft += LiBATPack.Current*time/36.0;				//(A s)->(0.01A h)		
				LiBATPack.SOC = (uint16_t)(LiBATPack.Qleft * 1000 / LiBATPack.Qfull + 0.5);
				Qleft_int = (uint16_t)(LiBATPack.Qleft + 0.5);
				holdingregister[12] = (uint8_t)(Qleft_int >> 8);
				holdingregister[13] = (uint8_t)Qleft_int;
				holdingregister[16] = (uint8_t)(LiBATPack.SOC >> 8);
				holdingregister[17] = (uint8_t)LiBATPack.SOC;
		}
}

