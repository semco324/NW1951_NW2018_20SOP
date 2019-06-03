#include "Interrupt.h"

//==============================================
//**********************************************
// CMP0 INTERRUPT
// 同步比较器 0 中断
//==============================================
void Interrupt_CMP0_SYNC_ISR()
{
//	_cp0f = 0;

}


//==============================================
//**********************************************
// CMP1 INTERRUPT
// 过压比较器 1 中断
//==============================================
void Interrupt_CMP1_OV_ISR()
{
//	_cp1f = 0;
	
}


//==============================================
//**********************************************
// CMP2 INTERRUPT
// 过零比较器 2 中断
//==============================================
void Interrupt_CMP2_ZC_ISR()
{
//	_cp2f = 0;
	
}


//==============================================
//**********************************************
// CMP3 INTERRUPT
// 浪涌比较器 3 中断---电压浪涌
//==============================================
void Interrupt_CMP3_VSUG_ISR(void)
{
//	_cp3f = 0;
}


//==============================================
//**********************************************
// CMP4 INTERRUPT
// 过流比较器 4 中断---电流浪涌 ISUG
//==============================================
void Interrupt_CMP4_OC_ISR(void)
{
//	_cp4f = 0;
	
}


//==============================================
//**********************************************
// Auto SYNC INTERRUPT
// 自动记录同步信号次数中断
//==============================================
void Interrupt_SYNC_ISR(void)
{
//	_syncf=0;
}


#if	_IIC_ENABLE == 1
//==============================================
//**********************************************
// IIC INTERRUPT
// I2C 中断
//==============================================
void Interrupt_IIC_ISR(void)
{	
	// 从机进入中断会拉低时钟线 SCL，退出中断后释放
//	_iicf=0;
	
	if (_iictof)
	{
		// IIC time out, reset IIC
		_iictof = 0;
		_iica = IIC_SLAVE_ADDRESS;	// 从设备地址	
		_iictoc = 0b10111111;			// 使能超时功能，timeout = 64mS
		_iicc0 = 0b00000110;			// bit3~2: IIC 去抖时间: 00:无去抖; 01: 2*Fsys ; 1*: 4*Fsys; bit1：IIC 使能
		_iicc1 = 0b00000000;
	}
	else
	{
		if (_haas)
		{
			//从机地址匹配 OK
			if (_srw)  //第八位
			{
				//表示主机master 读取数据，从机发送一个数据
				//设置从机处于发送模式
				_htx = 1;
				
				//发送一个 byte 数据给主机，释放 SCL 线，退出中断
				_iicd = R_IIC_DataBuffer[R_iicPoint];
				R_iicPoint ++;
			}
			else
			{
				//表示主机接下来要发送数据给从机
				_htx = 0;
				_txak = 0;
				
				//从机只需读取数据，释放 SCL 线，退出中断
				_acc = _iicd;
				
				//开始接收或者发送数据，初始化缓冲区指针
				R_iicPoint = 0;
				
				//装载要发送的数据到发送缓冲区
				//... ...
			}
		}
		else
		{
			//表示进入正常数据收发模式
			if (_htx)
			{
				//从机发送模式
				if(_rxak)  //第九位
				{
					//主机回NACK信号给从机，要求从机停止发送数据【RXAK = 1，表示从机没有接收到应答标志  NACK】
					_htx = 0;
					_txak = 0;
					
					//从机只需读取数据，释放 SCL 线，退出中断
					_acc = _iicd;
				}
				else
				{
					//从机发送模式【RXAK = 0，表示从机接收到应答标志 ACK】
					//从机发送数据，释放 SCL 线，退出中断
					_iicd = R_IIC_DataBuffer[R_iicPoint];
					R_iicPoint ++;
				}
			}
			else
			{
				//从机接收模式
				//从机只需读取数据，释放 SCL 线，退出中断
				R_IIC_DataBuffer[R_iicPoint] = _iicd;
				R_iicPoint ++;
				
				//接收数据处理（最好放在主循环里面处理）
				//... ...
			}
		}
	}
}
#endif

//==============================================
//**********************************************
// PTM0 CCRA OR CCRP OR TB0  INTERRUPT
// 多功能中断 0
//Timeing:2mS
//==============================================
void Interrupt_PTM0_CCRA(void)
{
	_ptm0af=0;
	_ptm0pf=0;
	_tb0f=0;
}

//==============================================
//**********************************************
// TB1 INTERRUPT
// TimeBase 1 时基中断
//==============================================
void Interrupt_TB1_ISR(void)
{
//	_tb1f=0;
}

//==============================================
//**********************************************
// TMR INTERRUPT
// 定时/ 计数器溢出中断
//==============================================
void Interrupt_TMR_ISR(void)
{
//	_tf=0;
}

#if	_UART_ENABLE == 1
//==============================================
//**********************************************
// UART INTERRUPT
// UART 串口中断
//==============================================
void Interrupt_UART_ISR(void)
{
	u8 Rx_Data;
	
	_ur0f=0;
	
	while(_rxif0 ==1)
	{
		Rx_Data =_u0sr;
		Rx_Data =_txr_rxr0;
		R_IIC_DataBuffer[R_iicPoint]=Rx_Data;
		if (++R_iicPoint>=9)
			R_iicPoint = 0;
	}
}
#endif

//==============================================
//**********************************************
// CTM0 CCRA OR CCRP OR AD  INTERRUPT
// 多功能中断 1
//==============================================
void Interrupt_CTM0_CCRA(void)
{	
	_ctm0af=0;
	_ctm0pf=0;
	_adf=0;
	f_2ms = 1;
	R_time200ms++;
	if (C_200MS_COUNT <= R_time200ms){
		R_time200ms = 0;
		f_200ms = 1;
		f_led_flash = 1;

//		R_time1s++;
//		if(C_1S_COUNT <= R_time1s){
//			R_time1s = 0;
//			f_1s = 1;
//		}
		
		R_time3s++;
		if(C_3S_COUNT <= R_time3s){
			R_time3s = 0;
			f_3s = 1;
		}
		
		//	/* 门遇阻定时10S,遇到MOT_I>1A需重新更新计时,直到10S内不再出现MOT_I>1A */
		/* 门遇阻定时10S内MOT_I<1A */
		if(f_safety_timing){
			R_time10s++;
			if(C_10S_COUNT <= R_time10s){
				f_safety2off = 1;
			}
		}

		/*防止运输中按钮被长时间按下,超过20S进入节能模式. */
		if(f_keypress){
			R_time20s++;
			if(C_20S_COUNT <= R_time20s){
				R_time20s = 0;
				f_20s = 1;
				if(C_DISCHARGE_MODE == R_workmode){
					R_workmode = C_SAFETY_MODE;
					f_safetyinit = 1;
					f_key2off = 1;
				}
			}
		}else{
			R_time20s = 0;
			f_20s = 0;
		}
		
	}

	
	if(f_chargetime){
		R_inttime1min++;
		if(C_1MIN_COUNT <= R_inttime1min){
			R_inttime1min = 0;
			
			R_intchargetime++;
			if(R_intsettime <= R_intchargetime){
				R_intchargetime = 0;
				P_NOCHG = 1;//定时时间到,关闭充电.
				f_timeout = 1;
			}
		}
	}else{
		R_inttime1min = 0;
		R_intchargetime = 0;
	}

	if(f_led_calibration){
		R_time500ms++;
		if(C_500MS_COUNT <= R_time500ms){
			R_time500ms = 0;
			f_500ms = 1;
		}
	}
}


//==============================================
//**********************************************
// CTM1 CCRA OR CCRP OR EEPROM  INTERRUPT
// 多功能中断 2
//==============================================
void Interrupt_CTM1_CCRA(void)
{
	_ctm1af=0;	
	_ctm1pf=0;
	_def=0;
	
	//125us定时器
}

//==============================================
//**********************************************
//   INT1 PIN OR LVD  INTERRUPT
// 多功能中断 3
//==============================================
void Interrupt_INT1_LVD(void)
{
	_int1f=0;	
	_lvf=0;	
}

