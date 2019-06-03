
#ifndef 		_MAIN_H
#define 		_MAIN_H

#include	"MyDefine.h"
#include	"Variants.h"

//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------

//--1---- 外部函数声明 -------------------------
//in Initial.c
extern void 	RESET_INITIAL(void);
extern void 	RAM_Init(void);
extern void 	User_Init(void);

//in adc.c
extern void 	ADC_Task(void);

//in Beep.c
extern void 	Beep_Task(void);

//in Timer.c
extern void 	TimeBase_Task(void);

//in Display.c
extern void 	Display_Task(void);

//in Key.c
extern void 	Key_Task(void);

//in I2C.c
extern void 	IIC_Task(void);
extern void IIC_GetKeyValue (unsigned char mode);
extern void IIC_SendLEDdata (void);

//in Function.c
extern void 	Function_Task(void);
extern void		Fan_Task();

//in Protect.c
extern void 	Protect_Task(void);

//in Delay.c


#endif 			//_MAIN_H