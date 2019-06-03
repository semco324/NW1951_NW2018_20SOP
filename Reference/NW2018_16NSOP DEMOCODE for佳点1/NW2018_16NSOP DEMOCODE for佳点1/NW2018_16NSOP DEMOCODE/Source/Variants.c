
#include	"Variants.h"

//--1---- 外部全局变量声明 -------------------------
volatile unsigned char R_WorkStatus; 		//功率状态
volatile unsigned char R_ErrorStatus; 		//报错标志

volatile unsigned char R_StartPPGTA; 		//初始启动 PPG 值
volatile unsigned char R_currPPG_min;		//当前 PPG 值
volatile unsigned char R_tempPPG_min;		//抖频时最小 PPG 值
volatile unsigned char R_tempPPG_max;		//抖频时最大 PPG 值

volatile unsigned char R_zeroDelay_Point;	//过零延时计数值
volatile unsigned char R_ReferCurrent ;		//参考电流
volatile unsigned char R_CurrCurrent ;		//当前电流
volatile unsigned int  R_intReferPower;		//参考功率

volatile unsigned char R_FanWorkTime ;		//风扇工作时间
volatile unsigned char R_FuncStep;			//自动功能控制步骤
volatile unsigned char R_minDelayPoff;		//最长工作时间
volatile unsigned char R_maxPowerTime;	//最大功能最长加热时间

//in Interrupt.c
volatile unsigned char R_StartPPG_Delay;
volatile unsigned char R_100mS_Count;
volatile unsigned char R_BeepTime ;			//蜂鸣器时间

//in adc.c
volatile unsigned char R_ADC_Count;			//ADC 采样次数
volatile unsigned int   R_ADC_intSumUP[C_ADC_NO];	//ADC 采样累加值
volatile unsigned char R_ADC_arrayValue[C_ADC_NO];	//ADC 平均值

//in I2C.c
volatile unsigned char R_MachinCode[2];
volatile unsigned char R_KeyBuffer[2];
volatile unsigned char R_IIC_DataBuffer[9];	//1 command + 7 data + 1 sum
volatile unsigned char R_iicPoint;

//in Display.c
volatile unsigned char R_LEDdata[7];
volatile unsigned char R_DisplayMode;
volatile unsigned char R_DisplayMode1;		//copy

//in timer.c
volatile unsigned char R_500mSecCount;		//500mS 时间
volatile unsigned char R_1SecCount;			//1S 时间
volatile unsigned char R_2SecCount;			//2S 时间
volatile unsigned char R_1MinCount;			//60S 时间
volatile unsigned char R_LEDFlash_5S0;
volatile unsigned char R_SetHour1;			//copy
volatile unsigned char R_SetMinute1;		//copy
volatile   signed char R_SetHour;
volatile   signed char R_SetMinute;
volatile unsigned char R_RealHour;
volatile unsigned char R_RealMinute;

//in Key.c
volatile unsigned char R_CookMode;
volatile unsigned char R_KeyDebounce;
volatile unsigned char R_KeyDelay;
volatile unsigned char R_KeyValue;
volatile unsigned char R_KeyValue1;		//copy
volatile __flag_type	R_KeyMask;
volatile __flag_type	R_KeyMask1;		//copy


//--2---- 外部全局位变量声明 -----------------------

volatile __flag_type		flag0;
#define			f_2mS			flag0.bits.b0
#define			f_100mS			flag0.bits.b1
#define			f_curr_abnormal		flag0.bits.b2
#define			f_pan_detected		flag0.bits.b3
#define			f_above_250V		flag0.bits.b4
#define			f_above_235V		flag0.bits.b5
#define			f_adc_finished		flag0.bits.b6
#define			f_below_200V		flag0.bits.b7

volatile __flag_type		flag1;
//in flag1
#define			f_key_pressed		flag1.bits.b0
#define			f_longkey_on		flag1.bits.b1
#define			f_beep_on			flag1.bits.b2
#define			f_IIC_matched		flag1.bits.b3
#define			f_10mS			flag1.bits.b4
#define			f_IIC_update		flag1.bits.b5
#define			f_0S5				flag1.bits.b6
#define			f_flash_0S5			flag1.bits.b7

volatile __flag_type		flag2;
//in flag2
#define			f_ppg_halt			flag2.bits.b0
#define			f_PowerOn			flag2.bits.b1
#define			f_key_locked		flag2.bits.b2
#define			f_cook_state		flag2.bits.b3
#define			f_subscribe_mode	flag2.bits.b4
#define			f_timer_mode		flag2.bits.b5
#define			f_heat_idle			flag2.bits.b6
#define			f_maxlevel_mode	flag2.bits.b7

volatile __flag_type		flag3;
//in flag3
#define			f_igbt_protect		flag3.bits.b0
#define			f_Jittering_mode		flag3.bits.b1
#define			f_targetPPG_Reached	flag3.bits.b2
#define			f_AdjustPPG_Direction	flag3.bits.b3

//------end of file---------------------------------------------------------------------
