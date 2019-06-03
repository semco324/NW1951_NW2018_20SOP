#ifndef		_INITIAL_H_
#define		_INITIAL_H_

#include	"MyDefine.h"
#include	"Variants.h"

//��������

//*********ȫ�ֱ�������*****************************
//--0---- ����ȫ�ֱ������� -------------------------

//--1---- �ⲿȫ�ֱ������� -------------------------


//*********��������*****************************
//--0---- ������������ -------------------------
void 	RAM_Init(void);
void 	Sys_Init(void);
void	User_Init(void);

void Sub_CMPx_Calibration (volatile unsigned char *pCMPCx, unsigned char mode);
void Sub_CMPx_Initialation (void);
void OPA_CMPx_INITIAL ();

void RESET_INITIAL();
void RAM_INITIAL();
void INTERRUPT_INITIAL();
void IO_INITIAL();
void SYS_INITIAL();
void ADC_INITIAL();
void PPG_INITIAL();
void PCK_INITIAL();
void TMR_INITIAL();
void CTM0_INITIAL();
void CTM1_INITIAL();
void PTM0_INITIAL();
void UART_INITIAL();

//--1---- �ⲿ�������� -------------------------


#endif
