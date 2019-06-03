
#ifndef 		_MAIN_H
#define 		_MAIN_H

#include	"MyDefine.h"
#include	"Variants.h"

//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------

//--1---- 外部函数声明 -------------------------
//in Initial.c
extern void RESET_INITIAL(void);
extern void RAM_Init(void);
extern void user_initial(void);

/* in adc.c */
extern void GetBattery_Level(void);
/* in function.c */
extern void Delay_100XuS(u8 delay);
extern void bbu_detetedmode(void);
extern void bbu_poweroff(void);
extern void bbu_charge(void);
extern void bbu_discharge(void);
extern void bbu_safety(void);
extern void led_display(void);
extern u8 dtob(float data);
extern u16 get_calibration(u16 para);
extern void get_calibration_factor(void);

/*in key.c*/
extern void key_scan(void);

/*in uart.c*/
extern void UART_SendData(u8 *pdata, u8 len);
extern void User_config_Read(void);

#endif 			//_MAIN_H
