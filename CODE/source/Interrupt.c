#include "Interrupt.h"

//==============================================
//**********************************************
// CMP0 INTERRUPT
// ͬ���Ƚ��� 0 �ж�
//==============================================
void Interrupt_CMP0_SYNC_ISR()
{
//	_cp0f = 0;

}


//==============================================
//**********************************************
// CMP1 INTERRUPT
// ��ѹ�Ƚ��� 1 �ж�
//==============================================
void Interrupt_CMP1_OV_ISR()
{
//	_cp1f = 0;
	
}


//==============================================
//**********************************************
// CMP2 INTERRUPT
// ����Ƚ��� 2 �ж�
//==============================================
void Interrupt_CMP2_ZC_ISR()
{
//	_cp2f = 0;
	
}


//==============================================
//**********************************************
// CMP3 INTERRUPT
// ��ӿ�Ƚ��� 3 �ж�---��ѹ��ӿ
//==============================================
void Interrupt_CMP3_VSUG_ISR(void)
{
//	_cp3f = 0;
}


//==============================================
//**********************************************
// CMP4 INTERRUPT
// �����Ƚ��� 4 �ж�---������ӿ ISUG
//==============================================
void Interrupt_CMP4_OC_ISR(void)
{
//	_cp4f = 0;
	
}


//==============================================
//**********************************************
// Auto SYNC INTERRUPT
// �Զ���¼ͬ���źŴ����ж�
//==============================================
void Interrupt_SYNC_ISR(void)
{
//	_syncf=0;
}


#if	_IIC_ENABLE == 1
//==============================================
//**********************************************
// IIC INTERRUPT
// I2C �ж�
//==============================================
void Interrupt_IIC_ISR(void)
{	
	// �ӻ������жϻ�����ʱ���� SCL���˳��жϺ��ͷ�
//	_iicf=0;
	
	if (_iictof)
	{
		// IIC time out, reset IIC
		_iictof = 0;
		_iica = IIC_SLAVE_ADDRESS;	// ���豸��ַ	
		_iictoc = 0b10111111;			// ʹ�ܳ�ʱ���ܣ�timeout = 64mS
		_iicc0 = 0b00000110;			// bit3~2: IIC ȥ��ʱ��: 00:��ȥ��; 01: 2*Fsys ; 1*: 4*Fsys; bit1��IIC ʹ��
		_iicc1 = 0b00000000;
	}
	else
	{
		if (_haas)
		{
			//�ӻ���ַƥ�� OK
			if (_srw)  //�ڰ�λ
			{
				//��ʾ����master ��ȡ���ݣ��ӻ�����һ������
				//���ôӻ����ڷ���ģʽ
				_htx = 1;
				
				//����һ�� byte ���ݸ��������ͷ� SCL �ߣ��˳��ж�
				_iicd = R_IIC_DataBuffer[R_iicPoint];
				R_iicPoint ++;
			}
			else
			{
				//��ʾ����������Ҫ�������ݸ��ӻ�
				_htx = 0;
				_txak = 0;
				
				//�ӻ�ֻ���ȡ���ݣ��ͷ� SCL �ߣ��˳��ж�
				_acc = _iicd;
				
				//��ʼ���ջ��߷������ݣ���ʼ��������ָ��
				R_iicPoint = 0;
				
				//װ��Ҫ���͵����ݵ����ͻ�����
				//... ...
			}
		}
		else
		{
			//��ʾ�������������շ�ģʽ
			if (_htx)
			{
				//�ӻ�����ģʽ
				if(_rxak)  //�ھ�λ
				{
					//������NACK�źŸ��ӻ���Ҫ��ӻ�ֹͣ�������ݡ�RXAK = 1����ʾ�ӻ�û�н��յ�Ӧ���־  NACK��
					_htx = 0;
					_txak = 0;
					
					//�ӻ�ֻ���ȡ���ݣ��ͷ� SCL �ߣ��˳��ж�
					_acc = _iicd;
				}
				else
				{
					//�ӻ�����ģʽ��RXAK = 0����ʾ�ӻ����յ�Ӧ���־ ACK��
					//�ӻ��������ݣ��ͷ� SCL �ߣ��˳��ж�
					_iicd = R_IIC_DataBuffer[R_iicPoint];
					R_iicPoint ++;
				}
			}
			else
			{
				//�ӻ�����ģʽ
				//�ӻ�ֻ���ȡ���ݣ��ͷ� SCL �ߣ��˳��ж�
				R_IIC_DataBuffer[R_iicPoint] = _iicd;
				R_iicPoint ++;
				
				//�������ݴ�����÷�����ѭ�����洦��
				//... ...
			}
		}
	}
}
#endif

//==============================================
//**********************************************
// PTM0 CCRA OR CCRP OR TB0  INTERRUPT
// �๦���ж� 0
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
// TimeBase 1 ʱ���ж�
//==============================================
void Interrupt_TB1_ISR(void)
{
//	_tb1f=0;
}

//==============================================
//**********************************************
// TMR INTERRUPT
// ��ʱ/ ����������ж�
//==============================================
void Interrupt_TMR_ISR(void)
{
//	_tf=0;
}

#if	_UART_ENABLE == 1
//==============================================
//**********************************************
// UART INTERRUPT
// UART �����ж�
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
// �๦���ж� 1
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
		
		//	/* �����趨ʱ10S,����MOT_I>1A�����¸��¼�ʱ,ֱ��10S�ڲ��ٳ���MOT_I>1A */
		/* �����趨ʱ10S��MOT_I<1A */
		if(f_safety_timing){
			R_time10s++;
			if(C_10S_COUNT <= R_time10s){
				f_safety2off = 1;
			}
		}

		/*��ֹ�����а�ť����ʱ�䰴��,����20S�������ģʽ. */
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
				P_NOCHG = 1;//��ʱʱ�䵽,�رճ��.
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
// �๦���ж� 2
//==============================================
void Interrupt_CTM1_CCRA(void)
{
	_ctm1af=0;	
	_ctm1pf=0;
	_def=0;
	
	//125us��ʱ��
}

//==============================================
//**********************************************
//   INT1 PIN OR LVD  INTERRUPT
// �๦���ж� 3
//==============================================
void Interrupt_INT1_LVD(void)
{
	_int1f=0;	
	_lvf=0;	
}

