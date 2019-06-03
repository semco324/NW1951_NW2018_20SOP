
#ifndef __VARIANTS_H__
#define __VARIANTS_H__

#include	"MyDefine.h"

#define		uchar		unsigned char
#define		uint		unsigned int

typedef	struct
{
    unsigned char b0:1;
    unsigned char b1:1;
    unsigned char b2:1;
    unsigned char b3:1;
    unsigned char b4:1;
    unsigned char b5:1;
    unsigned char b6:1;
    unsigned char b7:1;
} __8_bits;

typedef union
{
    __8_bits bits;
    unsigned char byte;
} __flag_type;

//--1---- �ⲿȫ�ֱ������� -------------------------
extern volatile unsigned char R_WorkStatus; 		//����״̬
extern volatile unsigned char R_ErrorStatus; 		//�����־

extern volatile unsigned char R_StartPPGTA; 		//��ʼ���� PPG ֵ
extern volatile unsigned char R_currPPG_min;		//��ǰ PPG ֵ
extern volatile unsigned char R_tempPPG_min;		//��Ƶʱ��С PPG ֵ
extern volatile unsigned char R_tempPPG_max;	//��Ƶʱ��� PPG ֵ

extern volatile unsigned char R_zeroDelay_Point;	//������ʱ����ֵ
extern volatile unsigned char R_ReferCurrent ;		//�ο�����
extern volatile unsigned char R_CurrCurrent ;		//��ǰ����
extern volatile unsigned int  R_intReferPower;		//�ο�����

extern volatile unsigned char R_FanWorkTime ;	//���ȹ���ʱ��
extern volatile unsigned char R_FuncStep;		//�Զ����ܿ��Ʋ���
extern volatile unsigned char R_minDelayPoff;		//�����ʱ��
extern volatile unsigned char R_maxPowerTime;	//����������ʱ��

//in Interrupt.c
extern volatile unsigned char R_StartPPG_Delay;
extern volatile unsigned char R_100mS_Count;
extern volatile unsigned char R_BeepTime ;			//������ʱ��

//in adc.c
extern volatile unsigned char R_ADC_Count;			//ADC ��������
extern volatile unsigned int  R_ADC_intSumUP[C_ADC_NO];		//ADC �����ۼ�ֵ
extern volatile unsigned char R_ADC_arrayValue[C_ADC_NO];	//ADC ƽ��ֵ
//**************************************************************
// // ADC �궨��
#define R_WorkVoltage		R_ADC_arrayValue[0]	//��ѹ����ֵ
#define R_WorkCurrent		R_ADC_arrayValue[1]	//��������ֵ
#define R_TMAIN_ADCValue	R_ADC_arrayValue[2]	//������¶Ȳ���ֵ
#define R_TIGBT_ADCValue	R_ADC_arrayValue[3]	//IGBT�¶Ȳ���ֵ
#define R_BMAIN_ADCValue	R_ADC_arrayValue[4]	//������¶Ȳ���ֵ

//in I2C.c
extern volatile unsigned char R_MachinCode[2];
extern volatile unsigned char R_KeyBuffer[2];
extern volatile unsigned char R_IIC_DataBuffer[9];	//1 command + 7 data + 1 sum
extern volatile unsigned char R_iicPoint;

//in Display.c
extern volatile unsigned char R_LEDdata[7];
extern volatile unsigned char R_DisplayMode;
extern volatile unsigned char R_DisplayMode1;		//copy

//in timer.c
extern volatile unsigned char R_500mSecCount;		//500mS ʱ��
extern volatile unsigned char R_1SecCount;			//1S ʱ��
extern volatile unsigned char R_2SecCount;			//2S ʱ��
extern volatile unsigned char R_1MinCount;			//60S ʱ��
extern volatile unsigned char R_LEDFlash_5S0;
extern volatile unsigned char R_SetHour1;			//copy
extern volatile unsigned char R_SetMinute1;			//copy
extern volatile   signed char R_SetHour;
extern volatile   signed char R_SetMinute;
extern volatile unsigned char R_RealHour;
extern volatile unsigned char R_RealMinute;

//in Key.c
extern volatile unsigned char R_CookMode;
extern volatile unsigned char R_KeyDebounce;
extern volatile unsigned char R_KeyDelay;
extern volatile unsigned char R_KeyValue;
extern volatile unsigned char R_KeyValue1;		//copy
extern volatile __flag_type	  R_KeyMask;
extern volatile __flag_type	  R_KeyMask1;		//copy


//--1---- �ⲿȫ�ֳ����궨�� -------------------------

//--2---- �ⲿȫ��λ�������� -----------------------
//--2---- �ⲿȫ��λ�������� -----------------------
extern volatile __flag_type		flag0;
//in flag0
#define			f_2mS			flag0.bits.b0
#define			f_100mS			flag0.bits.b1
#define			f_curr_abnormal		flag0.bits.b2
#define			f_pan_detected		flag0.bits.b3
#define			f_above_250V		flag0.bits.b4
#define			f_above_235V		flag0.bits.b5
#define			f_adc_finished		flag0.bits.b6
#define			f_below_200V		flag0.bits.b7

extern volatile __flag_type		flag1;
//in flag1
#define			f_key_pressed		flag1.bits.b0
#define			f_longkey_on		flag1.bits.b1
#define			f_beep_on			flag1.bits.b2
#define			f_IIC_matched		flag1.bits.b3
#define			f_10mS				flag1.bits.b4
#define			f_IIC_update		flag1.bits.b5
#define			f_0S5				flag1.bits.b6
#define			f_flash_0S5			flag1.bits.b7

extern volatile __flag_type		flag2;
//in flag2
#define			f_ppg_halt			flag2.bits.b0
#define			f_PowerOn			flag2.bits.b1
#define			f_key_locked		flag2.bits.b2
#define			f_cook_state		flag2.bits.b3
#define			f_subscribe_mode	flag2.bits.b4
#define			f_timer_mode		flag2.bits.b5
#define			f_heat_idle			flag2.bits.b6
#define			f_maxlevel_mode	flag2.bits.b7

extern volatile __flag_type		flag3;
#define			f_igbt_protect		flag3.bits.b0
#define			f_Jittering_mode		flag3.bits.b1
#define			f_targetPPG_Reached	flag3.bits.b2
#define			f_AdjustPPG_Direction	flag3.bits.b3
//in flag3

#endif //__VARIANTS_H_