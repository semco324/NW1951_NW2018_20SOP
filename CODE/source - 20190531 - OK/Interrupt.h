#ifndef _isr_h_
#define _isr_h_

#include	"MyDefine.h"
#include	"Variants.h"

//常量定义

//变量定义

//本地函数定义
void __attribute((interrupt(0x08)))	Interrupt_CMP0_SYNC_ISR(void);
void __attribute((interrupt(0x0c)))	Interrupt_CMP1_OV_ISR(void);
void __attribute((interrupt(0x10)))	Interrupt_CMP2_ZC_ISR(void);
void __attribute((interrupt(0x14)))	Interrupt_CMP3_VSUG_ISR(void);
void __attribute((interrupt(0x18)))	Interrupt_CMP4_OC_ISR(void);
void __attribute((interrupt(0x1c)))	Interrupt_SYNC_ISR(void);
void __attribute((interrupt(0x20)))	Interrupt_IIC_ISR(void);
void __attribute((interrupt(0x24)))	Interrupt_PTM0_CCRA(void);
void __attribute((interrupt(0x28)))	Interrupt_TB1_ISR(void);
void __attribute((interrupt(0x2C)))	Interrupt_TMR_ISR(void);
void __attribute((interrupt(0x30)))	Interrupt_UART_ISR(void);
void __attribute((interrupt(0x34)))	Interrupt_CTM0_CCRA(void);
void __attribute((interrupt(0x38)))	Interrupt_CTM1_CCRA(void); //125us定时器
void __attribute((interrupt(0x3c)))	Interrupt_INT1_LVD(void);

//外部函数定义

#endif
