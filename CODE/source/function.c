#include "function.h"

/*
*f=16Mhz
*T=0.25us
*daley:100us
*/
void Delay_100XuS(volatile u8 delay)
{
	volatile unsigned char i;
	for (i = 0; i < delay; i ++)
	{
		GCC_CLRWDT ();
		GCC_DELAY(391);
	}
}

//===============================================================
//function: void bbu_detetedmode(void).
//input   : NULL.
//output  : NULL
//description: 有电源:充电模式.
//===============================================================
void bbu_detetedmode(void)
{
	if(C_POWEROFF_MODE != R_workmode){
		/* 可以简单消抖和检测长按 */
		f_vinchk = (!P_VINCHK);
		f_trg = f_vinchk & (f_vinchk ^ f_cont);
		f_cont = f_vinchk;
		if((!f_trg) && f_cont){
			/* 检测到至少连续两次 P_VINCHK=0 才进入这里 */
			if(C_CHARGE_MODE != R_workmode){
				R_workmode = C_CHARGE_MODE;
				f_charge_init = 1;
			}
		}else{
			if(C_CHARGE_MODE == R_workmode){
				R_workmode = C_DISCHARGE_MODE;
				f_discharge_init = 1;
			}
		}
	}
}


void bbu_poweroff(void)
{
	P_RLED_D = C_LED_OFF;
	P_GLED_C = C_LED_OFF;
	P_LOAD = 0;
	P_OPEN = 0;/* 关闭电源供电 */
	P_BAT_C = 0;

	if(f_20s){
		_adcen = 0;
		_lvdc = 0x00;
		_opac0 = 0x00;
		_ct0on = 0;
		_pas0 = 0x00;
		_pas1 = 0x00;
		_pbs0 = 0x00;
		_pcs0 = 0x00;
		_pcs1 = 0x00;
		_pac  = 0b00000000; 				
		_pa   = 0b00000000;
		_pbc  = 0b00000000; 				
		_pb   = 0b00000000;
		_pcc  = 0b00000000; 				
		_pc   = 0b00000000;
		_emi = 0;
		_fhiden = 0;
		_fsiden = 0;
		GCC_CLRWDT();
		GCC_HALT();
	}
}


//===============================================================
//function: void bbu_charge(void).
//input   : NULL.
//output  : NULL
//description: 有交流电,进入充电模式.
//===============================================================
void bbu_charge(void)
{
	if(f_charge_init){
		f_charge_init = 0;
		P_NOCHG = 0;//打开充电	
		f_cont1 = 0;
		f_cont2 = 0;
		f_mot_i = 0;
		/*LED*/
		f_charging = 0;
		f_bat_full = 0;
		f_led_low = 0;
		f_led_load = 0;
		R_lowI2off_cnt = 0;
		R_intlowv2off_cnt = 0;
		R_change_cnt = 0;		
		R_intsettime = C_TIME9H;
		R_inttime1min = 0;
		f_chargetime = 1;
		f_timeout = 0;
		R_batlvl_cnt1 = 0;
		R_batlvl_cnt2 = 0;
		R_batlvl_cnt3 = 0;
		R_batchg_cnt = 0;
	}else{

	#if 0
		/* 检测是否正在充电 */
		f_chrg = !P_CHRG;
		f_trg1 = f_chrg & (f_chrg ^ f_cont1);
		f_cont1 = f_chrg;
		if((!f_trg1) && f_cont1){
			/* 检测到至少连续两次 P_CHRG=0 有效才进入这里 */
			f_charging = 1;
		}else{
			f_charging = 0;
		}

		/* 检测是否充满电 */
		f_full = !P_FULL;
		f_trg2 = f_full & (f_full ^ f_cont2);
		f_cont2 = f_full;
		if((!f_trg2) && f_cont2){
			/* 检测到至少连续两次 P_FULL=0 有效才进入这里 */
			f_bat_full = 1;
		}else{
			f_bat_full = 0;
		}
	#else
		/* 检测是否正在充电 */
		if(!P_CHRG){
			R_charging_cnt++;
			if(10 <= R_charging_cnt){
				R_charging_cnt = 0;
				f_charging = 1;
			}
		}else{
			R_charging_cnt = 0;
			f_charging = 0;
		}

		/* 检测是否充满电 */
		if(!P_FULL){
			R_full_cnt++;
			if(10 <= R_full_cnt){
				R_full_cnt = 0;
				f_bat_full = 1;
			}
		}else{
			R_full_cnt = 0;
			f_bat_full = 0;
		}
	#endif

		GetBattery_Level();
		if(f_adc_ok){
			f_adc_ok = 0;
			
			if(R_intADC_mot_i >= C_MOT_I_200){
				
				R_change_cnt = 0;
				R_batchg_cnt = 0;
			
				R_lowI2off_cnt++;
				if(R_lowI2off_cnt > 10){
					R_lowI2off_cnt = 0;
					if(!P_NOCHG)f_mot_i = 1;
					P_NOCHG = 1;//关闭充电,防止马达电压不稳定时会损坏充电模块.
//					f_chargetime = 0;
				}
				
			}else{
				R_lowI2off_cnt = 0;
				if(f_mot_i)P_NOCHG = 0;
				f_mot_i = 0;
#if 0
				/* 充电模式,当Vbat>12V5,打开输出. */
				if(C_BATV_12V6 <= R_intADC_Vbat){
					R_change_cnt++;
					if(250 <= R_change_cnt){
						f_vin_on = 0;
						R_change_cnt = 0;
						P_LOAD = 1;
						P_OPEN = 1;
					}
				}else{
					R_change_cnt = 0;
				}
				
				if(C_BATV_12V3 > R_intADC_Vbat){
					R_batchg_cnt++;
					if(250 <= R_batchg_cnt){
						R_batchg_cnt = 0;
						P_LOAD = 0;
						P_OPEN = 0;
						P_NOCHG = 0;//打开充电	
						f_chargetime = 1;
					}
				}else
					R_batchg_cnt = 0;
					
#else
				if(P_NOCHG){
					/* 充电模式,当Vbat>12V5,打开输出. */
					if(C_BATV_12V5 <= R_intADC_Vbat){
						R_change_cnt++;
						if(C_CHANGE_CNT <= R_change_cnt){
							f_vin_on = 0;
							R_change_cnt = 0;
							P_LOAD = 1;
							P_OPEN = 1;
						}
					}else{
						R_change_cnt = 0;
					}
				}else{
					/* 充电模式,当Vbat>12V5,打开输出. */
					if(C_BATV_12V9 <= R_intADC_Vbat){
						R_change_cnt++;
						if(C_CHANGE_CNT <= R_change_cnt){
							f_vin_on = 0;
							R_change_cnt = 0;
							P_LOAD = 1;
							P_OPEN = 1;
						}
					}else{
						R_change_cnt = 0;
					}
				}

				if(P_LOAD){
					if(C_BATV_12V >= R_intADC_Vbat){
						R_batchg_cnt++;
						if(C_CHANGE_CNT <= R_batchg_cnt){
							R_batchg_cnt = 0;
							P_LOAD = 0;
							P_OPEN = 0;
							P_NOCHG = 0;//打开充电	
							f_chargetime = 1;
						}
					}else
						R_batchg_cnt = 0;
				}else{
					if(C_BATV_12V4 > R_intADC_Vbat){
						R_batchg_cnt++;
						if(C_CHANGE_CNT <= R_batchg_cnt){
							R_batchg_cnt = 0;
							P_LOAD = 0;
							P_OPEN = 0;
							P_NOCHG = 0;//打开充电	
							f_chargetime = 1;
						}
					}else
						R_batchg_cnt = 0;
				}
#endif
			}
			

			/* 充电模式,当Vbat>15V,关闭充电. */
			if(C_BATV_15V <= R_intADC_Vbat){
				R_intlowv2off_cnt++;
				if(C_CHANGE_CNT <= R_intlowv2off_cnt){
					R_intlowv2off_cnt = 0;
					P_NOCHG = 1;//关闭充电	
					f_chargetime = 0;
				}
			}else{
				R_intlowv2off_cnt = 0;
			}

//			if(f_charging){
				/* 根据电池电量设定充电时间,防止过充. */
			
				R_batlvl_cnt++;
				if(C_BATV_13V5 <= R_intADC_Vbat){
					R_batlvl_cnt1++;
				}/*else if(C_BATV_13V <= R_intADC_Vbat){
					R_batlvl_cnt2++;
				}*/else if(C_BATV_11V5 > R_intADC_Vbat){
					R_batlvl_cnt3++;
				}
				if(C_BATLVL_CNT <= R_batlvl_cnt){
					R_batlvl_cnt = 0;
					if(R_batlvl_cnt1 <= R_batlvl_cnt3){
						R_intsettime = C_TIME9H;
					}
//					if(R_batlvl_cnt3 <= R_batlvl_cnt2){
//						R_intsettime = C_TIME4H;
//						R_batlvl_cnt3 = R_batlvl_cnt2;
//					}
					if(R_batlvl_cnt3 < R_batlvl_cnt1){
						if(C_TIME2H != R_intsettime){
							R_intchargetime = 0;
						}
						R_intsettime = C_TIME2H;
					}
					R_batlvl_cnt1 = 0;
					R_batlvl_cnt2 = 0;
					R_batlvl_cnt3 = 0;
				}
//			}
			
			/* 充电定时时间到关闭充电后,当电池电压再次低于12.4V,此时再重新打开充电*/
			if(f_timeout){
				if(C_BATV_12V4 >= R_intADC_Vbat){
					f_timeout = 0;
					f_charge_init = 1;
				}
			}
		}
	}
}

//===============================================================
//function: void bbu_discharge(void).
//input   : NULL.
//output  : NULL
//description: 放电模式.
//===============================================================
void bbu_discharge(void)
{
	if(f_discharge_init){
		f_discharge_init = 0;
		/* opa */
		_opac0 = 0b10100100;			//--OPA Enable;  x20; SWR2:On;	外部反馈电路
		_aofm = 0;//运算放大器模式.
		_ars = 0;//反向输入.
		//pc0:IS1
		_pcs01 = 1;
		_pcs00 = 1;
		
		P_NOCHG = 0;//打开充电,省电.	
		
		f_lowV = 0;
		f_lowI = 0;
		f_highI = 0;
		R_intlowv2off_cnt = 0;
		R_lowI2off_cnt = 0;
		R_change_cnt = 0;
		R_batlvl_cnt = 0;
		R_batlvl_cnt1 = 0;
		/*LED*/
		f_charging = 0;
		f_bat_full = 0;
		f_led_low = 0;
		f_led_load = 1;
		f_chargetime = 0;
	}else{
		GetBattery_Level();
		if(f_adc_ok){
			f_adc_ok = 0;

			/* 放电模式:检测电池电压,低于11.5V,红色LED闪烁. */
			if(C_BATV_11V5 >= R_intADC_Vbat){
				R_change_cnt++;
				if(C_LOWV_CNT <= R_change_cnt){
					R_change_cnt = 0;
					f_led_low = 1;
					f_led_load = 0;
				}
			}else{
				R_change_cnt = 0;
				f_led_low = 0;
				f_led_load = 1;
			}

			/* 电流较高，说明马达工作中(>1A)，不能断电. */
			if(C_MOT_I_HIGHT > R_intADC_mot_i){
				R_batlvl_cnt1++;
				if(C_HIGI2SAF_CNT < R_batlvl_cnt1){
					R_batlvl_cnt1 = 0;
					f_highI = 0;
				}
			}else{
				R_batlvl_cnt1 = 0;
				f_highI = 1;
			}
			
			if(C_MOT_I_LOW > R_intADC_mot_i){
				R_lowI2off_cnt++;
				if(C_LOWI2OFF_CNT < R_lowI2off_cnt){
					R_lowI2off_cnt = 0;
					f_lowI = 1;
				}
			}else{
				R_lowI2off_cnt = 0;
				f_lowI = 0;
			}

			
			/* 检测电池电压,f_highI=0为马达没工作,f_highI=1马达启动或工作. */
			if(f_highI){
				R_intlowv2off_cnt = 0;
				/*f_highI=1,马达工作>1A,电压<9.5V才准备关机 */
				if(C_BATV_9V5 > R_intADC_Vbat){
					R_batlvl_cnt++;
					if(C_LOWV2SAf_CNT <= R_batlvl_cnt){
						R_batlvl_cnt = 0;
						f_lowV = 1;
					}
				}else{				
					f_lowV = 0;
					R_batlvl_cnt = 0;
				}
			}else{
				R_batlvl_cnt = 0;
				//f_highI=0为马达没工作
				if(f_vin_on){
					//VIN方式开机后，突然断开交流电。若Vbat<12.5V,则准备关机.
					#if 1
					if(C_BATV_12V5 > R_intADC_Vbat){
						R_intlowv2off_cnt++;
						if(C_LOWV2OFF_CNT <= R_intlowv2off_cnt){
							R_intlowv2off_cnt = 0;
							f_lowV = 1;
						}
					}else{
						R_intlowv2off_cnt = 0;
						f_lowV = 0;
					}
					#else
					f_lowV = 1; 
					#endif
				}else{
					if(C_BATV_11V > R_intADC_Vbat){
						R_intlowv2off_cnt++;
						if(C_LOWV2OFF_CNT <= R_intlowv2off_cnt){
							R_intlowv2off_cnt = 0;
							f_lowV = 1;
						}
					}else{
						R_intlowv2off_cnt = 0;
						f_lowV = 0;
					}
				}
			}
			
			/* 正常直接关闭BBU */
			if(f_lowV & f_lowI){
				R_workmode = C_POWEROFF_MODE;
			}
			
			/* BBU门遇阻 */
			if(f_lowV & f_highI){
				R_workmode = C_SAFETY_MODE;
				f_safetyinit = 0;
			}
		}
	}
}


//===============================================================
//function: void bbu_safety(void).
//input   : NULL.
//output  : NULL
//description: 门遇阻检测.
//===============================================================
void bbu_safety(void)
{
	if(f_safetyinit){
		f_safetyinit = 0;
		
		/* opa */
		_opac0 = 0b10100100;			//--OPA Enable;  x20; SWR2:On;	外部反馈电路
		_aofm = 0;//运算放大器模式.
		_ars = 0;//反向输入.
		//pc0:IS1
		_pcs01 = 1;
		_pcs00 = 1;
		
		f_lowV = 0;
		f_safety_timing = 0;
		f_safety2off = 0;
		R_intlowv2off_cnt = 0;
		/*LED*/
		f_charging = 0;
		f_bat_full = 0;
		
		if(f_key2off)
			R_time10s = C_10S_COUNT-2;
		else
			R_time10s = 0;
		
		f_chargetime = 0;
	}else{
		
		GetBattery_Level();
		if(f_adc_ok){
			f_adc_ok = 0;
//			if(C_BATV_9V5 > R_intADC_Vbat){
//				R_intlowv2off_cnt++;
//				if(C_LOWV_CNT <= R_intlowv2off_cnt){
//					R_intlowv2off_cnt = 0;
//					f_lowV = 1;
//				}
//			}else{
//				R_intlowv2off_cnt = 0;
//				f_lowV = 0;
//			}
			
			if(C_MOT_I_HIGHT < R_intADC_mot_i){
				f_safety_timing = 0;
				f_safety2off = 0;
				R_time10s = 0;
			}else{
				f_safety_timing = 1;
			}

			if(f_safety2off){
				R_workmode = C_POWEROFF_MODE;
			}
		}
	}
}

//===============================================================
//function: void led_display(void).
//input   : NULL.
//output  : NULL
//description: LED显示:H-->常亮,闪烁,L-->灭.
//===============================================================
void led_display(void)
{
	if(C_POWEROFF_MODE == R_workmode){
		P_RLED_D = C_LED_OFF;
		P_GLED_C = C_LED_OFF;
	}else{
		if(f_led_calibration){
			if(f_500ms){
				f_500ms = 0;
				P_RLED_D ^= 1;
				P_GLED_C = P_RLED_D;
			}
		}else if(f_bat_full){
			/* Green LED */
			/* 满电时绿色LED恒亮 */
			P_RLED_D = C_LED_OFF;
			P_GLED_C = C_LED_ON;
			f_charging = 0;
		}else if(f_charging){
			if(f_led_flash){
				f_led_flash = 0;
				/* 正在充电LED闪烁 */
				P_RLED_D = C_LED_OFF;
				P_GLED_C ^= 1;
			}
		}else if(f_led_low){
			if(f_led_flash){
				f_led_flash = 0;
				/* 正在充电LED闪烁 */
				P_RLED_D ^= 1;
				P_GLED_C = C_LED_OFF;
			}
		}else if(f_led_load){
			/* 输出时红色LED恒亮 */
			P_RLED_D = C_LED_ON;
			P_GLED_C = C_LED_OFF;
		}else{
			P_RLED_D = C_LED_OFF;
			P_GLED_C = C_LED_OFF;
		}
	}

}


/*
作用:		电压电流整定.
说明:		软件校正就是根据电源电压波动的范围，确定出参考电压Vref(VDD)的校正系数,
		通过对实际转换结果的补偿消除误差对转换结果的影响.
目的:		校正ADC参考电压VDD
校正算法:
	校正系数: k = D'/D
	D'为实际转换结果,D为理想转换结果.
	
算法实现:
若精确输入 Vin=0.1V,(1A=0.005ohm *1A *20倍=0.1v).
ADC参考电压为VDD=5V,VDD会有波动.
此时:
	D' = 0.1V/VDD*4095;(Vin软件放大20倍)
	D  = 0.1V/5*4095 = 81.9;
校正系数:k = D'/D = (0.1V/VDD*4095)/81.9;

*/
//===============================================================
//function: void get_calibration_factor(void).
//input   : NULL.
//output  : NULL
//description: 电压电流整定;参考:1A,12V;
//			  给定电池电压得到校正系数并转换成二进制,储存在EEPROM.
//			精度:小数点后八位二进制长度,十进制小数点后三位>=0.004.
//===============================================================
void get_calibration_factor(void)
{
	volatile float temp = 0.0;
	if(C_POWEROFF_MODE != R_workmode){
		if(!P_CALIBRATION){
			R_calibration_cnt++;
			if(125 < R_calibration_cnt){
				R_calibration_cnt = 0;
				f_calibration = 1;
				/* 电池电压校正系数 */
				GetBattery_Level();
				if(C_CALIBRATION_BATV < R_intADC_Vbat){
					temp = (float)((float)(R_intADC_Vbat - C_CALIBRATION_BATV)/C_CALIBRATION_BATV);
					R_calibration_pos = 0;
				}else if(C_CALIBRATION_BATV > R_intADC_Vbat){
					temp = (float)((float)(C_CALIBRATION_BATV - R_intADC_Vbat)/C_CALIBRATION_BATV);
					R_calibration_pos = 1;
				}else{					
					temp = 0.0;
				}			
				R_calibration_k = dtob(temp);
				User_config_store();
			}
		}else{
			R_calibration_cnt = 0;
			f_calibration = 0;
		}
	}

}

/*
10进制小数转换成二进制,并按位存储在8位的变量中,高位在前，低位在后.
例如:当data=0.012,则结果binary_data=00000011=3,
0.012(D) = 0.00000011(B),目前转换二进制精度小数点后8位;
若要提高精度，可以把C_LEN设置为更大，存储的变量也同时设置更大点.
*/
//===============================================================
//function: u8 dtob(float data).
//input   : float 类型参数.
//output  : unsigned char ，8位二进制数，
//description: 把十进制小数转换成8位二进制整型.
//eg:   0.012(D) = 00000011(B)
//===============================================================
u8 dtob(float data)
{
	volatile u8 i=0;
	volatile u8 binary_data=0;
	while(1.0 <= data) data -= 1.0;
	while(i<C_LEN){
		i++;
		data = data*2;
		if(data >= 1.0){
			data -= 1.0;
			binary_data |= (1<<(C_LEN-i));
		}
	}
	return binary_data;
}

/*
FUNCTION:根据校正系数进行数据校正.
INPUT	:para为需要校正的数据.
RETURN	:result为校正后的数据.
OTHER	:R_calibration_k为校正系数,f_positive=1:调大,f_positive=0:调小.
*/
u16 get_calibration(u16 para)
{
	volatile u16 result = para;
	u8 j = 0;
	if(R_calibration_k){
		for(j=0;j<C_LEN;j++){
			if(R_calibration_k & (1<<j)){
				
				if(R_calibration_pos){
					result += (para >> (C_LEN-j));
				}else{
					result -= (para >> (C_LEN-j));
				}
			}
		}
	}
	return result;
}


