
#include "MyDefine.h"

//--1---- �ⲿȫ�ֱ������� -------------------------
//volatile unsigned char R_WorkStatus; 		//����״̬

/* Flag*/
__flag_type flagtime;
__flag_type flag0;
__flag_type flag1;
__flag_type flag2;
__flag_type flag3;

/* Timing */
u8 R_time200ms;
u8 R_time500ms;
u8 R_time1s;
u8 R_time3s;
u8 R_time10s;
u8 R_time20s;
u16 R_inttime1min;
u16 R_intchargetime;
u16 R_intsettime;

/* COUNT */
u16 R_intlowv2off_cnt;
u8 R_lowI2off_cnt;
u8 R_change_cnt;
u8 R_batlvl_cnt;
u8 R_batlvl_cnt1;
u8 R_batlvl_cnt2;
u8 R_batlvl_cnt3;
u8 R_batchg_cnt;
u8 R_charging_cnt;
u8 R_full_cnt;

u8 R_calibration_cnt;
/* key */
u16 R_intkeydebounce;

/* work mode */
u8 R_workmode;

/* AD */
/* Battery AD */
u16 R_intADC_Vbat;
u16 R_intADC_Sum;
u8 	R_ADC_Count;
u16 R_intADC_mot_sum;
u16 R_intADC_mot_i;
u16 R_intADC_charge_i;
u8 R_adc_channel;

volatile u8 R_calibration_k;
volatile u8 R_calibration_pos;

/* IIC */
volatile u8 R_MachinCode[2];
volatile u8 R_KeyBuffer[2];
volatile u8 R_IIC_DataBuffer[9];	//1 command + 7 data + 1 sum
volatile u8 R_iicPoint;

/* Uart */
u8 R_UartStatus;
volatile u8 R_UartData;
u8 R_UartData_Buf[2][DATA_LEN];//���ڽ��������ݴ�.
volatile u8 R_Uart_active;//���ƶ�ά������,��ֹ����δʹ�ö���������ܵ����ݸ��ǵ�.
volatile u8 R_UartData_Idx;//���ڽ������ݵ�����λ.


//------end of file---------------------------------------------------------------------
