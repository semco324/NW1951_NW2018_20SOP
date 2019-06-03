#include "uart.h"
#if _UART_ENABLE == 1

u8 Decode_DataBuf[BUF_LENGTH];
const u8 Uart_SendDataBuf[CMD_SEND_LEN] = {0x7E, 0x03, 0xC5,0x00, 0x01};
u8 Uart_Cmd;

//===============================================================
//function: UART_SendData(u8 *pdata, u8 len).
//input   : u8 *pdata: 要发送的数据指针.
//output  : len：发送的数据长度.
//description: UART 发送数据.
//===============================================================
void UART_SendData(u8 *pdata, u8 len)
{
	volatile u8 i = 0;
	while(i < len){
		GCC_CLRWDT();
		if((_txif0 == 1)&&(_tidle0 == 1)){
			R_UartStatus  = C_UART_STATUS;
			C_RXTX_DATA = *pdata;
			i++;
			pdata++;
		}
	}
}

//===============================================================
//function: UART_ReceiveData(void).
//input   : NULL.
//output  : NULL
//description: UART 接收数据，目前在串口中断接收数据.
//===============================================================
void UART_ReceiveData(void)
{
	if(_rxif0 == 1){
		R_UartStatus  = C_UART_STATUS;
		R_UartData = C_RXTX_DATA;
	}
}


void Decode_Uart_Data(void)
{
	switch(Decode_DataBuf[POS_TYPE])
	{
	   	case CMD_TYPE_1:
			Command_Analysis();
			break;
		default:
			break;
	}
}

//===============================================================
//function: Command_Analysis.
//input   : NULL.
//output  : NULL.
//description: 解析控制指令并执行相应动作.
//===============================================================
void Command_Analysis(void)
{
	//Uart_Cmd = Decode_DataBuf[POS_CTRL];
	if(0 ){
		//关灯模式下,只处理唤醒语或开灯命令.
		if((CMD_CTRL_ON != Uart_Cmd) && (CMD_CTRL_WAKEUP != Uart_Cmd)){
			Uart_Cmd = CMD_NULL;
		}
	}
	switch(Uart_Cmd)
	{
	   	case CMD_CTRL_WAKEUP:

//				UART_SendData((u8 *)(&Uart_SendDataBuf[0]),CMD_SEND_LEN);
			break;	
		
		case CMD_CTRL_REC_LUX:
//				UART_SendData((u8 *)(&Uart_SendDataBuf[0]),CMD_SEND_LEN);
			break;
		default:
			break;
	}
	
	Uart_Cmd = CMD_NULL;
}
#endif
