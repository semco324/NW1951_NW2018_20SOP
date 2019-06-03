#ifndef __MYDEFINE_H 
#define __MYDEFINE_H

#include	"nw2018.h"


//**************************************************************
// 条件预编译定义
//**************************************************************
#define	_IIC_ENABLE			0	//1: enable;	0: disable
#define	_UART_ENABLE		1	//1: enable;	0: disable

//**************************************************************
// 端口定义
//**************************************************************
#define	P_FAN	_pa5	// 风扇脚位
#define	P_BUZZ	_pa7	// 蜂鸣器脚位


//**************************************************************
#define	IIC_SLAVE_ADDRESS		0xa0

//**************************************************************
// 常量定义
//**************************************************************
// IO口输入配置

//配置定时器0  

//配置定时器1 
#define C_TMR1_VALUE			(256-80)		//10us = 80*1/8Mhz (PPG 不可重复触发时间)
#define C_TMR1C_VALUE			0b00000000	//00：模式0（PPG 不可重复触发功能）,Fsys/1
//1分频 使能 PPG非重新触发


// //*********************************************************************
//配置AD端口
#define C_ADC_NO				(5)

// //*********************************************************************
//配置PPG脉冲宽度限制
#define C_PWLT_VALUE			(256-(30*8)/2)	//PPG OUT LIMIT: 30uS =(256-PWLT)/(fSYS/2)

// //*********************************************************************
//配置比较器

// //*********************************************************************
//系统控制寄存器

// //*********************************************************************
/// PPG 参数定义
#define C_MAX_PPGTA			0x15		// PPG 最大脉宽设置
#define C_MIN_PPGTA			0xe0		// PPG 最小脉宽设置
#define C_DEFAULT_STARTPPG	0xbb		// 常规检锅 PPG
#define C_LVOLT_STARTPPG		0xb9		// 低压检锅 PPG
#define C_HVOLT_STARTPPG		0xbf		// 高压检锅 PPG
#define C_DET_PAN_TIMEOUT		0x82		// 检锅脉冲计数时间
#define C_NOPAN_PULSE_COUNT  	0x09		// 检锅脉冲个数
#define C_MOVE_PAN_CURRENT  	0x20		// 移锅电流

// //*********************************************************************
/// NTC 参数定义
#define C_TMAIN_15C			0x08		// 面板15C
#define C_TMAIN_50C			0x20		// 面板50C
#define C_TMAIN_OFFSET			0x02		// 面板差值

#define C_TIGBT_OVER_TEMP		0x58		// IGBT 超温
#define C_TTMAIN_OVER_TEMP	0xd4		// 上面板超温
#define C_BTMAIN_OVER_TEMP	0xd4		// 下面板超温
#define C_NTC_OPEN			0xfd		// NTC 开路
#define C_NTC_SHORT			0x03		// NTC 短路

// //*********************************************************************
/// 电压参数定义
#define C_220V_VOLTAGE		(294l*255l/500l)				// 电压220V, Vin = 2.94V @220V
#define C_200V_VOLTAGE		(200l*C_220V_VOLTAGE/220l)	// 电压200V
#define C_235V_VOLTAGE		(235l*C_220V_VOLTAGE/220l)	// 电压235V
#define C_230V_VOLTAGE		(230l*C_220V_VOLTAGE/220l)	// 电压230V
#define C_250V_VOLTAGE		(250l*C_220V_VOLTAGE/220l)	// 电压250V
#define C_245V_VOLTAGE		(245l*C_220V_VOLTAGE/220l)	// 电压245V
#define C_10V_VOLTAGE			( 10l*C_220V_VOLTAGE/220l)	// 电压10V

#define C_UPPER_OVER_VOLT		(265l*C_220V_VOLTAGE/220l)	// 过压
#define C_LOWER_OVER_VOLT	(255l*C_220V_VOLTAGE/220l)	// 过压恢复
#define C_UPPER_UNDER_VOLT	(155l*C_220V_VOLTAGE/220l)	// 欠压恢复
#define C_LOWER_UNDER_VOLT	(145l*C_220V_VOLTAGE/220l)	// 欠压

// //*********************************************************************
// // 电流参考值定义
#define C_MIN_REFER_CURRENT		0x22	// 最小电流值，再小就认为无锅
#define C_MAX_REFER_CURRENT		0xaa	// 最大电流值，再大就保护
#define C_1200W_REFER_CURRENT		0x44	// 1200W 电流值
#define C_7A5_REFER_CURRENT		0x99	// 7.5A 恒流


// //*********************************************************************
// // 错误类型定义
#define C_SYSTEM_ERROR			0xe0	// 系统故障 无线盘等
#define C_NOPAN_ERROR			0xe1	// 无锅
#define C_HIGH_VOLT_ERROR			0xe2	// 高压
#define C_LOW_VOLT_ERROR			0xe3	// 低压
#define C_IGBT_OVER_ERROR			0xe4	// IGBT 超温
#define C_IGBT_OPNSHT_ERROR		0xe5	// IGBT 开短路
#define C_TMAIN_OVER_ERROR		0xe6	// 上面板传感器超温
#define C_TMAIN_OPNSHT_ERROR		0xe7	// 上面板传感器开短路
#define C_BMAIN_OVER_ERROR		0xe8	// 下面板传感器超温
#define C_BMAIN_OPNSHT_ERROR		0xe9	// 下面板传感器开短路
#define C_TMAIN_INVALID_ERROR		0xea	// 上面板传感器失效
#define C_BMAIN_INVALID_ERROR		0xeb	// 下面板传感器失效
#define C_IIC_ERROR				0xee	// IIC 通讯错误
#define C_TMAIN_GANSHAO_ERROR	0xef	// 干烧错误

// //*********************************************************************
// // 其他参数定义
#define C_HEAT_TOTAL_TIME		125		// 8,000mS = 15*64mS 
#define C_TOTAL_LEVEL			9

////----------------IGBT MAIN TEMPERATURE----------------------
//热平衡在60度~70度 （0B6H~0B0H）,Heated Time > 30mins
//@210V-8A, @1610~1650W
//
//热平衡在66.6度（0C4H~0C7H）,Heated Time > 30mins
//@220V-8.2A, @1800~1850W @2016/3/17
//@220V-4.1A, @920W @2017/3/28，Tigbt = 0x75
#define		C_IGBT_T50			0xC8	////50C  DEGREE
#define		C_IGBT_T55			0xBF	////55C  DEGREE	//CHECK POINT
#define		C_IGBT_T60			0xB6	////60C  DEGREE	(0B5H@67C)
#define		C_IGBT_T70			0x91//0xA1	////70C  DEGREE	//IDLE HEAT POINT
#define		C_IGBT_T80			0x75//0x91	////80C  DEGREE
#define		C_IGBT_T90			0x66//0x77	////90C  DEGREE	//STOP HEAT POINT
#define		C_IGBT_T100			0x58//0x64	////100C DEGREE
#define		C_IGBT_T120			0x43	////120C DEGREE

////----------------PAN MAIN TEMPERATURE----------------------
//烧水开，热平衡049H~04CH）,Heated Time > 30mins
//@220V-8.2A, @1800~1850W @2016/3/17
//电压：电流		=5E：36 @1816W
//TMAIN：TIGBT	=4C：C5
//PWM ：电流		=40：37
#define		C_TMAIN_T40			0x10	//010H	////40C  DEGREE
#define		C_TMAIN_T50			0x15	//013H	////50C  DEGREE
#define		C_TMAIN_T60			0x1D	//01BH	////60C  DEGREE
#define		C_TMAIN_T70			0x25	//026H	////70C  DEGREE
#define		C_TMAIN_T80			0x30	//032H	////80C  DEGREE
#define		C_TMAIN_T90			0x33	//047H	////95C  DEGREE
#define		C_TMAIN_T95			0x35	//047H	////95C  DEGREE
#define		C_TMAIN_T105		0x45	//054H	////100C DEGREE	0x3d@101C
#define		C_TMAIN_T120		0x56	//075H	////120C DEGREE
#define		C_TMAIN_T140		0x69	//097H	////140C DEGREE
#define		C_TMAIN_T160		0x80	//0B3H	////160C DEGREE
#define		C_TMAIN_T180		0x91	//0C9H	////180C DEGREE
#define		C_TMAIN_T200		0xA5	//0D8H	////200C DEGREE
#define		C_TMAIN_T220		0xBA	//0E3H	////220C DEGREE
#define		C_TMAIN_T240		0xBB	//0E8H	////240C DEGREE

//************ Power constant define **************
#define		P120				0
#define		P300				1
#define		P600				2
#define		P900				3
#define		P1200			4
#define		P1400			5
#define		P1600			6
#define		P1800			7
#define		P2100			8

//************* Temperature define ***************
#define		T60				0
#define		T90				1
#define		T120				2
#define		T140				3
#define		T160				4
#define		T180				5
#define		T200				6
#define		T220				7
#define		T240				8

//*************** FUNCTION MODE *********************
#define		FUNC_NONE			0
#define		FUNC_RESEVERED		1
#define		FUNC_JIANZHA		2
#define		FUNC_BAOTANG		3
#define		FUNC_ZHENGZHU		4
#define		FUNC_ZHUZHOU		5
#define		FUNC_WENHUO		6
#define		FUNC_HUOGUO		7
#define		FUNC_LIUCHAO		8
#define		FUNC_BIANCHAO		9
#define		FUNC_BAOCHAO		10

// // 显示模式定义
#define		C_DISPLAY_NONE		0
#define		C_DISPLAY_STAT		1
#define		C_DISPLAY_POWER	2
#define		C_DISPLAY_TEMP		3
#define		C_DISPLAY_TIME1		4
#define		C_DISPLAY_TIME2		5
#define		C_DISPLAY_ERROR		6
#define		C_DISPLAY_TEST		7

#endif	//__MYDEFINE_H

