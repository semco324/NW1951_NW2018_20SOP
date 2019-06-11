//*******************************************************************************************
//																							*
//                    ProductName:	NW2018_20SOP 上海佳点 BBU 控制器-V00          	   				*
//                    MCU Body:		HT45F0002-16NSOP			               	       		*
//                    HT-IDE3000: 	V7.98	                                           		*				*
//                    Date:         2019/05/08                                    	   		*				*
//                    Author:       ghg                                      				*
//                    Company:		New Wave Eelectronics (ShenZhen) LTD.					*
//																							*
//*******************************************************************************************
//																							*
//              	 	Files Required: Omitted												*
//																							*
//*******************************************************************************************
//   Configuration Option Setting:                                                     		*					*
//*******************************************************************************************
//																							*
//   		 		Notes: 	1.Fsys = 16MHz @5.0V											*
//						   	2.WDT ENABLE (8S)												*
//																							*
//																							*
//*******************************************************************************************
//
//	Revision History:
//			1.Initial on 2019.05.08
//TEST:
//1.充满电池电压:13.3v
//2.有适配器充电打开满电电池电压:13.51
//3.有适配器充电关闭满电电池电压:13.51
//
//
#include "main.h"



int main(void)
{
	if (!_to)
	{
		RESET_INITIAL();
		
		user_initial();
	}else{
		if(C_POWEROFF_MODE == R_workmode){
			_fhiden = 0;
			_fsiden = 0;
			GCC_CLRWDT();
			GCC_HALT();
		}
	}
	
	while (1)
	{
	
		GCC_CLRWDT();
		
#if DEBUG_EN//test
				//UART调试用
				if(f_200ms){ 
					f_200ms = 0;
					Uart_DataBuf[0] = (R_intADC_Vbat/1000);
					Uart_DataBuf[1] = (R_intADC_Vbat/100%10);
					Uart_DataBuf[2] = (R_intADC_Vbat%100/10);
					Uart_DataBuf[3] = (R_intADC_Vbat%10);
					Uart_DataBuf[4] = (R_intADC_mot_i/1000);
					Uart_DataBuf[5] = (R_intADC_mot_i/100%10);
					Uart_DataBuf[6] = (R_intADC_mot_i%100/10);
					Uart_DataBuf[7] = (R_intADC_mot_i%10);
					Uart_DataBuf[8] = R_calibration_k;
					UART_SendData((u8 *)(&Uart_DataBuf[0]),LEN_TEST);
				}
#endif
		if (f_2ms){
			f_2ms = 0;
			
			get_calibration_factor();
			bbu_detetedmode();
			key_scan();
			led_display();
			
			switch(R_workmode)
			{
				case C_POWEROFF_MODE:
					bbu_poweroff();
					break;
					
				case C_CHARGE_MODE:
					bbu_charge();
					break;

				case C_DISCHARGE_MODE:
					bbu_discharge();
					break;

				case C_SAFETY_MODE:
					bbu_safety();
					break;
					
				default:
					R_workmode = C_DISCHARGE_MODE;
					f_discharge_init = 1;
					break;
			}
		}
	}

	return 0;
}
