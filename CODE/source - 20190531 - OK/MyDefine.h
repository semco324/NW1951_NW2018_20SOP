#ifndef __MYDEFINE_H__ 
#define __MYDEFINE_H__

#include "nw2018.h"

typedef unsigned char u8;
typedef unsigned int u16;

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
    __sfr_byte byte;
} __flag_type;

//**************************************************************
// 条件预编译定义
//**************************************************************
#define	_IIC_ENABLE			0	//1: enable;	0: disable
#define	_UART_ENABLE		0	//1: enable;	0: disable
#define _PWM_ENABLE			0	//1: enable;	0: disable   BUZZ

//**************************************************************
// 端口定义
//**************************************************************
#define P_RLED_D				_pa0	//LED_D:Red LED		0:off	1:on
#define P_CHARGE_I				_pa1	//AN1 检测充电电流CHARGE_I
#define P_CALIBRATION			_pa2	//0:进行电压电流校正.
#define P_CALIBRATION_C			_pac2	//0:进行电压电流校正.
#define P_CALIBRATION_PU		_papu2	//0:进行电压电流校正.
#define P_BUZZER				_pa3	//
#define P_GLED_C				_pa4	//LED_C:Green LED	0:off	1:on
#define P_BAT_C					_pa5	//控制检测电池电压.			 0:关闭电压检测路径.			1:开启电池电压检测路径.
#define P_BAT_V					_pa6	//AN5:检测电池电压.
#define P_OPEN					_pa7	//控制电池是否供电.	 0:关闭电池供电.  				1:打开电池供电.
#define P_OPEN_C				_pac7	//

#define P_TXD					_pb0	//TXD
#define P_RXD					_pb1	//RXD
#define P_CHRG					_pb2	//0:为电池充电状态.
#define P_FULL					_pb3	//0:电池充满电.

#define P_MOT_I					_pc0	//IS1:检测马达电流.
#define P_KEY					_pc1	//0:有按键按下.
#define P_VINCHK				_pc2	//电源输入检测        0:VIN有输入.		1:无输入.
#define P_NOCHG					_pc3	//0:使能充电.  1:强制关闭充电.
#define P_LOAD					_pc4	//控制输出.	0:关闭输出.		      1:打开输出.
#define P_LOAD_C				_pcc4


/* 常量定义 */
/* TIME */
#define C_200MS_COUNT			100		//2mS*100=200mS
#define C_500MS_COUNT			250		//2mS*250=500mS
#define C_1S_COUNT				5		//200mS*5=1S
#define C_3S_COUNT				15		//200mS*15=3S
#define C_10S_COUNT				50		//200MS*50=10S
#define C_20S_COUNT				100		//200MS*100=20S
#define C_1MIN_COUNT			30000	//2mS*30000=60S

#define C_TIME12H				720		//60S*720=12h
#define C_TIME4H				240		//60S*240=4h
#define C_TIME2H				120		//60S*120=2h

#define C_KEY_DEBOUNC			1500	//2mS*1500=3S
#define C_DELAY2				2
#define C_DELAY200				200

#define C_LOWV_CNT				63
#define C_LOWV2SAf_CNT			94//156-->5s;94*0.032s=3s;
#define C_LOWV2OFF_CNT			1875//1875*0.032S = 60s
#define C_LOWI2OFF_CNT			70
#define C_HIGI2SAF_CNT			70
#define C_CHANGE_CNT			100

#define C_BATLVL_CNT			100

#define C_LED_OFF				0
#define C_LED_ON				1
#define C_LOAD_L				0
#define C_LOAD_H				1

/* 工作模式 */
#define C_POWEROFF_MODE			1
#define C_CHARGE_MODE			2
#define C_DISCHARGE_MODE		3
#define C_SAFETY_MODE			4	//门遇阻反转


/* BATTERY */
//
#define C_BATV_9V5				2373		
#define C_BATV_10V				2499		
#define C_BATV_10V5				2623		
#define C_BATV_11V				2748
#define C_BATV_11V5				2873
#define C_BATV_12V				2998
#define C_BATV_12V4				3098
#define C_BATV_12V5				3123
#define C_BATV_12V9				3223
#define C_BATV_13V				3248
#define C_BATV_13V2				3298
#define C_BATV_13V6				3398
#define C_BATV_15V				3748

/*
0.3:122-159
0.4:163-196
0.6:245-274
*/
/*
*测试说明:
*1.没接负载，蓝色LED亮,Imot功耗15.24mA，电池电压12.64V;
*2.负载仪恒流1A,蓝色LED亮,功耗1.014mA,电池电压12.64V;
*特别注意:
*1.接负载测试输出时不能把负载地直接接到电池地，否则负载电流不会经过R14和R15,
*  此时测到的仅仅是板子的工作电流,负载电流直接流入电池地.
*正确负载接法电流流向: BAT+ --> T2 --> D4 --> 负载 --> R14&R15 --> BAT-;
*错误负载接法电流流向：BAT+ --> T2 --> D4 --> 负载 --> BAT-;
*/
/* 电流检测     */						//0.025ohm 1A-->432
#define C_MOT_I_LOW				389//0.95A
#define C_MOT_I_HIGHT			409//1A=0.025ohm *1A *20倍=0.5v--->AD=0.5v/5v*4095=409.5

#define C_CHARGE_I				1

/*校正标准1A,(1A=0.005ohm *1A *20倍=0.1v)*/
#define C_CALIBRATION_V			82//1A --> 0.1V/VDD*4095=0.1/5*4095=81.9 --> 负载电流
#define C_CALIBRATION_BATV		2998//12V --> 12V/(36k/(82k+36k))/5V*4095 = 2998
#define C_LEN					8	//小数点后八位二进制长度,十进制小数点后三位>=0.004.
#define C_WUCHA					76//76:0.296;  0.245
/* ADC */
#define C_Imot_AN0				0b00110000	//IS1-->MOT_I马达电流，待机电流.
#define C_Vbat_AN5				0b00110101	//Vbattery AN5 结果采用高4低8结构
#define C_ICharge_AN1			0b00110001	//充电电流.

#define C_INTERNAL_OPA			0b10000100//_sadc1 = 0b10000100;
#define C_EXTERNAL_CHN			0b00000100//_sadc1 = 0b00000100;

//**************************************************************
#define	IIC_SLAVE_ADDRESS		0xa0


/***********************************************/
/* UART */
#if 0
//UARTn 功能使能位
#define C_UARTEN_OFF		_uarten0 = 0
#define C_UARTEN_ON			_uarten0 = 1
//发送数据位数选择位
#define C_DATA_8BIT			_bno0 = 0
#define C_DATA_9BIT			_bno0 = 1
//奇偶校验使能位
#define C_PREN_OFF			_pren0 = 0
#define C_PREN_ON			_pren0 = 1
//奇偶校验选择位
#define C_PREN_ODD			_prt0 = 1
#define C_PREN_EVEN			_prt0 = 0
//停止位的长度选择位
#define C_STOP_1BIT			_stops0 = 0
#define C_STOP_2BIT			_stops0 = 1
//波特率
#define C_BR_2400			{_brgh0 = 0;_brg0 = 51;}
#define C_BR_4800			{_brgh0 = 0;_brg0 = 25;}
#define C_BR_9600			{_brgh0 = 0;_brg0 = 12;}
#define C_BR_115200			{_brgh0 = 1;_brg0 = 3;}
//使能/除能 UARTn 发送器
#define C_TX_OFF			_txen0 = 0
#define C_TX_ON				_txen0 = 1
//使能/除能 UARTn 接收器
#define C_RX_OFF			_rxen0 = 0
#define C_RX_ON				_rxen0 = 1
//串口接收中断使能位
#define C_RIE_OFF			_rie0 = 0
#define C_RIE_ON			_rie0 = 1
//串口总中断
#define C_UR0E_ON 			_ur0e = 1

//设置
#define c_UartDataBit		C_DATA_8BIT
#define c_UartPren			C_PREN_OFF
#define c_UartStopBit		C_STOP_1BIT
#define c_UartBuad			C_BR_2400
#define c_UartEn			C_UARTEN_ON//C_UARTEN_OFF
#define c_UartTxEn			C_TX_ON//C_TX_OFF
#define c_UartRxEn			C_RX_ON//C_RX_ON//

#endif
//UnSR 寄存器
#define C_UART_STATUS		_u0sr
//数据寄存器
#define C_RXTX_DATA			_txr_rxr0
#define DATA_LEN			4 //串口一条命令为4字节,所以写4就够了	



#endif	//__MYDEFINE_H__

