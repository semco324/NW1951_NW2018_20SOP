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
//description: �е�Դ:���ģʽ.
//===============================================================
void bbu_detetedmode(void)
{
	if(C_POWEROFF_MODE != R_workmode){
		/* ���Լ������ͼ�ⳤ�� */
		f_vinchk = (!P_VINCHK);
		f_trg = f_vinchk & (f_vinchk ^ f_cont);
		f_cont = f_vinchk;
		if((!f_trg) && f_cont){
			/* ��⵽������������ P_VINCHK=0 �Ž������� */
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
	P_OPEN = 0;/* �رյ�Դ���� */
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
//description: �н�����,������ģʽ.
//===============================================================
void bbu_charge(void)
{
	if(f_charge_init){
		f_charge_init = 0;
		P_NOCHG = 0;//�򿪳��	
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
		/* ����Ƿ����ڳ�� */
		f_chrg = !P_CHRG;
		f_trg1 = f_chrg & (f_chrg ^ f_cont1);
		f_cont1 = f_chrg;
		if((!f_trg1) && f_cont1){
			/* ��⵽������������ P_CHRG=0 ��Ч�Ž������� */
			f_charging = 1;
		}else{
			f_charging = 0;
		}

		/* ����Ƿ������ */
		f_full = !P_FULL;
		f_trg2 = f_full & (f_full ^ f_cont2);
		f_cont2 = f_full;
		if((!f_trg2) && f_cont2){
			/* ��⵽������������ P_FULL=0 ��Ч�Ž������� */
			f_bat_full = 1;
		}else{
			f_bat_full = 0;
		}
	#else
		/* ����Ƿ����ڳ�� */
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

		/* ����Ƿ������ */
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
					P_NOCHG = 1;//�رճ��,��ֹ����ѹ���ȶ�ʱ���𻵳��ģ��.
//					f_chargetime = 0;
				}
				
			}else{
				R_lowI2off_cnt = 0;
				if(f_mot_i)P_NOCHG = 0;
				f_mot_i = 0;
#if 0
				/* ���ģʽ,��Vbat>12V5,�����. */
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
						P_NOCHG = 0;//�򿪳��	
						f_chargetime = 1;
					}
				}else
					R_batchg_cnt = 0;
					
#else
				if(P_NOCHG){
					/* ���ģʽ,��Vbat>12V5,�����. */
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
					/* ���ģʽ,��Vbat>12V5,�����. */
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
							P_NOCHG = 0;//�򿪳��	
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
							P_NOCHG = 0;//�򿪳��	
							f_chargetime = 1;
						}
					}else
						R_batchg_cnt = 0;
				}
#endif
			}
			

			/* ���ģʽ,��Vbat>15V,�رճ��. */
			if(C_BATV_15V <= R_intADC_Vbat){
				R_intlowv2off_cnt++;
				if(C_CHANGE_CNT <= R_intlowv2off_cnt){
					R_intlowv2off_cnt = 0;
					P_NOCHG = 1;//�رճ��	
					f_chargetime = 0;
				}
			}else{
				R_intlowv2off_cnt = 0;
			}

//			if(f_charging){
				/* ���ݵ�ص����趨���ʱ��,��ֹ����. */
			
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
			
			/* ��綨ʱʱ�䵽�رճ���,����ص�ѹ�ٴε���12.4V,��ʱ�����´򿪳��*/
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
//description: �ŵ�ģʽ.
//===============================================================
void bbu_discharge(void)
{
	if(f_discharge_init){
		f_discharge_init = 0;
		/* opa */
		_opac0 = 0b10100100;			//--OPA Enable;  x20; SWR2:On;	�ⲿ������·
		_aofm = 0;//����Ŵ���ģʽ.
		_ars = 0;//��������.
		//pc0:IS1
		_pcs01 = 1;
		_pcs00 = 1;
		
		P_NOCHG = 0;//�򿪳��,ʡ��.	
		
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

			/* �ŵ�ģʽ:����ص�ѹ,����11.5V,��ɫLED��˸. */
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

			/* �����ϸߣ�˵����﹤����(>1A)�����ܶϵ�. */
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

			
			/* ����ص�ѹ,f_highI=0Ϊ���û����,f_highI=1�����������. */
			if(f_highI){
				R_intlowv2off_cnt = 0;
				/*f_highI=1,��﹤��>1A,��ѹ<9.5V��׼���ػ� */
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
				//f_highI=0Ϊ���û����
				if(f_vin_on){
					//VIN��ʽ������ͻȻ�Ͽ������硣��Vbat<12.5V,��׼���ػ�.
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
			
			/* ����ֱ�ӹر�BBU */
			if(f_lowV & f_lowI){
				R_workmode = C_POWEROFF_MODE;
			}
			
			/* BBU������ */
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
//description: ��������.
//===============================================================
void bbu_safety(void)
{
	if(f_safetyinit){
		f_safetyinit = 0;
		
		/* opa */
		_opac0 = 0b10100100;			//--OPA Enable;  x20; SWR2:On;	�ⲿ������·
		_aofm = 0;//����Ŵ���ģʽ.
		_ars = 0;//��������.
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
//description: LED��ʾ:H-->����,��˸,L-->��.
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
			/* ����ʱ��ɫLED���� */
			P_RLED_D = C_LED_OFF;
			P_GLED_C = C_LED_ON;
			f_charging = 0;
		}else if(f_charging){
			if(f_led_flash){
				f_led_flash = 0;
				/* ���ڳ��LED��˸ */
				P_RLED_D = C_LED_OFF;
				P_GLED_C ^= 1;
			}
		}else if(f_led_low){
			if(f_led_flash){
				f_led_flash = 0;
				/* ���ڳ��LED��˸ */
				P_RLED_D ^= 1;
				P_GLED_C = C_LED_OFF;
			}
		}else if(f_led_load){
			/* ���ʱ��ɫLED���� */
			P_RLED_D = C_LED_ON;
			P_GLED_C = C_LED_OFF;
		}else{
			P_RLED_D = C_LED_OFF;
			P_GLED_C = C_LED_OFF;
		}
	}

}


/*
����:		��ѹ��������.
˵��:		���У�����Ǹ��ݵ�Դ��ѹ�����ķ�Χ��ȷ�����ο���ѹVref(VDD)��У��ϵ��,
		ͨ����ʵ��ת������Ĳ�����������ת�������Ӱ��.
Ŀ��:		У��ADC�ο���ѹVDD
У���㷨:
	У��ϵ��: k = D'/D
	D'Ϊʵ��ת�����,DΪ����ת�����.
	
�㷨ʵ��:
����ȷ���� Vin=0.1V,(1A=0.005ohm *1A *20��=0.1v).
ADC�ο���ѹΪVDD=5V,VDD���в���.
��ʱ:
	D' = 0.1V/VDD*4095;(Vin����Ŵ�20��)
	D  = 0.1V/5*4095 = 81.9;
У��ϵ��:k = D'/D = (0.1V/VDD*4095)/81.9;

*/
//===============================================================
//function: void get_calibration_factor(void).
//input   : NULL.
//output  : NULL
//description: ��ѹ��������;�ο�:1A,12V;
//			  ������ص�ѹ�õ�У��ϵ����ת���ɶ�����,������EEPROM.
//			����:С������λ�����Ƴ���,ʮ����С�������λ>=0.004.
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
				/* ��ص�ѹУ��ϵ�� */
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
10����С��ת���ɶ�����,����λ�洢��8λ�ı�����,��λ��ǰ����λ�ں�.
����:��data=0.012,����binary_data=00000011=3,
0.012(D) = 0.00000011(B),Ŀǰת�������ƾ���С�����8λ;
��Ҫ��߾��ȣ����԰�C_LEN����Ϊ���󣬴洢�ı���Ҳͬʱ���ø����.
*/
//===============================================================
//function: u8 dtob(float data).
//input   : float ���Ͳ���.
//output  : unsigned char ��8λ����������
//description: ��ʮ����С��ת����8λ����������.
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
FUNCTION:����У��ϵ����������У��.
INPUT	:paraΪ��ҪУ��������.
RETURN	:resultΪУ���������.
OTHER	:R_calibration_kΪУ��ϵ��,f_positive=1:����,f_positive=0:��С.
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


