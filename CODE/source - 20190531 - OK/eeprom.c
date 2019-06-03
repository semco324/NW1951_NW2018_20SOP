
#include	"eeprom.h"

#define		_MCU_TYPE		1		//1: HT67F48X alike, 0: Standard MCU
#define DATA_0x55			0x55
#define DATA_0xAA			0xaa
#define EEPROM_ADDR0		0x10	//EEPROM:64X8
#define EEPROM_ADDR1		0x11	//EEPROM:64X8
#define EEPROM_ADDR2		0x12	//EEPROM:64X8
#define EEPROM_ADDR3		0x13	//EEPROM:64X8

////===============================================================
////u8 EEPROM_Read (void)
////===============================================================
u8 EEPROM_Read (unsigned char addr_data)
{
	unsigned char read_data;
	
	_eea = addr_data;
    
#if	_MCU_TYPE == 1    
	_mp1l = 0x40;
	_mp1h = 0x01;
#else    
	_mp1 = 0x40;
	_bp = 0x01;
#endif

	_iar1 |= 0b00000010;//RDEN=1
	_iar1 |= 0b00000001;//RD=1
    
	while (_iar1 & 0b00000001);
	{
		GCC_CLRWDT();
	}
	_iar1 &= 0b11111101;//rden=0x00;
	
#if	_MCU_TYPE == 1
	_mp1h = 0x00;
#else
	_bp = 0x00;
#endif

	read_data = _eed;
	
	return (read_data);
}

////===============================================================
////void EEPROM_Write (void)
////===============================================================
void EEPROM_Write (unsigned char addr_data,unsigned char data)
{
	_eea = addr_data;
 	_eed = data;
 	
#if	_MCU_TYPE == 1    
	_mp1l = 0x40;
	_mp1h = 0x01;
#else    
	_mp1 = 0x40;
	_bp = 0x01;
#endif
	_emi = 0;
    _iar1|=0b00001000; //_wren=1;
    _iar1|=0b00000100; //_wr=1;
    _emi = 1;
	while (_iar1&0b00000100);//while(_wr);
	{
		GCC_CLRWDT();
	}
    _iar1 &= 0b11111011;//_wr=0x00;
    
#if	_MCU_TYPE == 1
	_mp1h = 0x00;
#else
	_bp = 0x00;
#endif
}

//===================================================================
//function: User_config_Read
//input   : NULL
//output  : NULL
//description:存储校正系数.
//===================================================================
void User_config_Read(void)
{
	if((DATA_0x55 == EEPROM_Read(EEPROM_ADDR0)) && (DATA_0xAA == EEPROM_Read(EEPROM_ADDR2))){
		//说明已经写入EEPROM,直接读取数据.
		R_calibration_k = EEPROM_Read(EEPROM_ADDR1);
		R_calibration_pos = EEPROM_Read(EEPROM_ADDR2);
		//检测数据合法性.
		if(R_calibration_k > C_WUCHA){
			R_calibration_k = 0;
			EEPROM_Write(EEPROM_ADDR0,0X00);
			EEPROM_Write(EEPROM_ADDR1,0X00);
			EEPROM_Write(EEPROM_ADDR2,0X00);
			EEPROM_Write(EEPROM_ADDR3,0X00);
		}
	}else{
		R_calibration_k = 0;
	}
}

//===================================================================
//function: User_config_store
//input   : NULL
//output  : NULL
//description:检查数据合法性并存储用户配置值.
//===================================================================
void User_config_store(void)
{
	if(C_WUCHA < R_calibration_k){
		R_calibration_k = 0;
		f_led_calibration = 1;
	}else{
		f_led_calibration = 0;
		EEPROM_Write(EEPROM_ADDR0,DATA_0x55);
		EEPROM_Write(EEPROM_ADDR1,R_calibration_k);
		EEPROM_Write(EEPROM_ADDR2,R_calibration_pos);
		EEPROM_Write(EEPROM_ADDR3,DATA_0xAA);
	}
}






