#ifndef __UART_H__
#define __UART_H__
#include "MyDefine.h"
#include "Variants.h"

#if _UART_ENABLE == 1

//Command: CMD_HEARD,LENGTH,TYPE,CTRL
#define CMD_HEARD						0x7E
#define CMD_LENGTH						0x02
#define CMD_TYPE_1						0x66
#define CMD_TYPE_2						0xC5
#define CMD_CTRL_WAKEUP					0x01//С�����.(��������ģ��)        		//7E 02 66 01
#define CMD_CTRL_ON						0x02//�뿪��.     		//7E 02 66 02
#define CMD_CTRL_OFF					0x03//��ص�.     		//7E 02 66 03
#define CMD_CTRL_INC_LUX				0x04//��������.     	//7E 02 66 04
#define CMD_CTRL_REC_LUX				0x05//��С����.     	//7E 02 66 05
#define CMD_CTRL_YLED					0x06//���׵�.     		//7E 02 66 06
#define CMD_CTRL_WLED					0x07//���Ƶ�.     		//7E 02 66 07
#define CMD_NULL						0x00
//����ĸ����������λ�� position
#define BUF_LENGTH						5			
#define POS_HEARD						0
#define POS_LENGTH						1
#define POS_TYPE						2
#define POS_CTRL						3

//Send Data Length
#define CMD_SEND_LEN					5

extern u8 Decode_DataBuf[BUF_LENGTH];
extern u8 Uart_Cmd;

void UART_SendData(u8 *pdata, u8 len);
void UART_ReceiveData(void);
void Decode_Uart_Data(void);
void Command_Analysis(void);

#endif//_UART_ENABLE == 1

#endif//__UART_H__
