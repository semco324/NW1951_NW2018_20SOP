#include "adc.h"
////===============================================================
////void ADC_Read (void)    get ad 
////in  
////out		AD_FINAL_H/AD_FINAL_L
////===============================================================
unsigned int ADC_Read (void)
{
	unsigned char 	i = 8;
	unsigned int 	R_intADC_Temp = 0;
	
	_start = 0;
	_start = 1;
	_start = 0;
	while (_adbz)
	{
		GCC_CLRWDT ();
	}
	
	while(i)
	{
		i --;
		_start = 0;
		_start = 1;
		_start = 0;
		while (_adbz)
		{
			GCC_CLRWDT ();
		}
		
		R_intADC_Temp += _sadol;
//		R_intADC_Temp += _adrh*0x100;
		R_intADC_Temp += ((_sadoh & 0x0F)<<8);
	}
	R_intADC_Temp >>= 3;
	
	return	R_intADC_Temp;
}

////===============================================================
////void GetBattery_Level (void)
////===============================================================
void GetBattery_Level (void)
{
	if(f_calibration){
		f_calibration = 0;
		
		P_BAT_C = 1;
		R_ADC_Count = 0;
		R_intADC_Sum = 0;
		R_intADC_mot_sum = 0;
		R_adc_channel = C_Vbat_AN5;
		_sadc0 = C_Vbat_AN5;
		_sadc1 = C_EXTERNAL_CHN;
		Delay_100XuS (C_DELAY2);
		R_intADC_Vbat = ADC_Read();
		
	}else{

		switch(R_adc_channel)
		{
			case C_Vbat_AN5:
				//Get Battery Voltage	
				P_BAT_C = 1;
				R_intADC_Sum += ADC_Read ();
			
				R_adc_channel = C_Imot_AN0;
				_sadc0 = C_Imot_AN0;
				_sadc1 = C_INTERNAL_OPA;
				
				R_ADC_Count++;
				if(R_ADC_Count >= 8){//C_CHANGE_CNT
					R_ADC_Count = 0;
					f_adc_ok = 1;
				
					R_intADC_Vbat = R_intADC_Sum >> 3;
					R_intADC_Vbat = get_calibration(R_intADC_Vbat);
					R_intADC_Sum = 0;

					R_intADC_mot_i = R_intADC_mot_sum >> 3;
					R_intADC_mot_sum = 0;
				}
				break;

			case C_Imot_AN0:
				/* 检测电流,OPA内部通道 */
				//Get Current	
				R_intADC_mot_sum += ADC_Read ();
				R_adc_channel = C_Vbat_AN5;
				_sadc0 = C_Vbat_AN5;
				_sadc1 = C_EXTERNAL_CHN;
				break;
				
			default:
				R_ADC_Count = 0;
				R_intADC_Sum = 0;
				R_intADC_mot_sum = 0;
				R_adc_channel = C_Vbat_AN5;
				_sadc0 = C_Vbat_AN5;
				_sadc1 = C_EXTERNAL_CHN;
				break;
		}
	}
}

