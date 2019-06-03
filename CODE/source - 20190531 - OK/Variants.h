
#ifndef __VARIANTS_H__
#define __VARIANTS_H__

#include	"MyDefine.h"

//--1---- 外部全局变量声明 -------------------------
extern volatile __flag_type flagtime;
#define f_flagtime_byte				flagtime.byte
#define f_2ms						flagtime.bits.b0
#define f_200ms						flagtime.bits.b1
#define f_500ms						flagtime.bits.b2
#define f_3s						flagtime.bits.b3
#define f_20s						flagtime.bits.b4
#define f_1s						flagtime.bits.b5

extern volatile __flag_type flag0;
#define f_flag0_byte				flag0.byte
#define f_charge_init				flag0.bits.b0	//1:充电初始化.
#define f_discharge_init			flag0.bits.b1	//1:放电初始化.
#define f_safetyinit				flag0.bits.b2	//1:门遇阻初始化.
#define f_lowV						flag0.bits.b3	//
#define f_lowI						flag0.bits.b4
#define f_highI						flag0.bits.b5
#define f_safety2off				flag0.bits.b6	//1:门遇阻通过后关机.
#define f_safety_timing				flag0.bits.b7	//1:门遇阻定时开始.

extern volatile __flag_type flag1;
#define f_flag1_byte				flag1.byte
#define f_vinchk					flag1.bits.b0	//1:有交流电.
#define f_trg						flag1.bits.b1	
#define f_cont						flag1.bits.b2
#define f_chrg						flag1.bits.b3
#define f_trg1						flag1.bits.b4
#define f_cont1						flag1.bits.b5
#define f_charging					flag1.bits.b6	//1:正在充电.
#define f_bat_full					flag1.bits.b7	//1:充电已满.

extern volatile __flag_type flag2;
#define f_flag2_byte				flag2.byte
#define f_full						flag2.bits.b0	//1:充电满
#define f_trg2						flag2.bits.b1
#define f_cont2						flag2.bits.b2
#define f_key2off					flag2.bits.b3
#define f_keypress					flag2.bits.b4
#define f_vin_on					flag2.bits.b5	//0:按键方式开机;   		1:AC方式开机,Vbat>12.5V则清0.
#define f_positive					flag2.bits.b6	//1:positive 
//#define  				flag2.bits.b7	

extern volatile __flag_type flag3;
#define f_flag3_byte				flag3.byte
#define f_led_low					flag3.bits.b0	//1:无交流电且Vbat<12V.
#define f_led_load					flag3.bits.b1
#define f_led_flash					flag3.bits.b2
#define f_led_calibration			flag3.bits.b3	//1:校正偏差过大.
#define f_calibration				flag3.bits.b4	//1:校正.
#define f_chargetime				flag3.bits.b5
#define f_timeout 					flag3.bits.b6
#define f_adc_ok					flag3.bits.b7

/* timing */
extern u8  R_time200ms;
extern u8  R_time500ms;
extern u8  R_time1s;
extern u8  R_time3s;
extern u8  R_time10s;
extern u8  R_time20s;
extern u16  R_inttime1min;
extern u16  R_intchargetime;
extern u16 R_intsettime;

/* COUNT */
extern u16 R_intlowv2off_cnt;
extern u8 R_lowI2off_cnt;
extern u8 R_change_cnt;
extern u8 R_batlvl_cnt;
extern u8 R_batlvl_cnt1;
extern u8 R_batlvl_cnt2;
extern u8 R_batlvl_cnt3;
extern u8 R_batchg_cnt;
extern u8 R_calibration_cnt;
extern u8 R_charging_cnt;
extern u8 R_full_cnt;

/* key */
extern u16  R_intkeydebounce;

/* work mode */
extern u8  R_workmode;

/* AD */
extern u16  R_intADC_Vbat;
extern u16  R_intADC_Sum;
extern u8 	R_ADC_Count;
extern u16 R_intADC_mot_sum;
extern u16  R_intADC_mot_i;
extern u16  R_intADC_charge_i;
extern u8 R_adc_channel;

extern volatile u8  R_calibration_k;
extern volatile u8  R_calibration_pos;

/* IIC */
extern volatile u8 R_MachinCode[2];
extern volatile u8 R_KeyBuffer[2];
extern volatile u8 R_IIC_DataBuffer[9];	//1 command + 7 data + 1 sum
extern volatile u8 R_iicPoint;

/* Uart */
extern u8 R_UartStatus;
extern volatile u8 R_UartData;
extern u8 R_UartData_Buf[2][DATA_LEN];//串口接受数据暂存.
extern volatile u8 R_Uart_active;//控制二维数组排,防止数据未使用而被后面接受的数据覆盖掉.
extern volatile u8 R_UartData_Idx;//串口接收数据的数组位.

/* EXTERN FUNCTION */
extern void Delay_100XuS(volatile u8 delay);

#endif //__VARIANTS_H_
