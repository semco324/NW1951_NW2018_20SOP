
#ifndef 		_EERPOM_H
#define 		_EERPOM_H

#include	"MyDefine.h"
#include	"Variants.h"

//*********ȫ�ֱ�������*****************************
//--0---- ����ȫ�ֱ������� -------------------------

//--1---- �ⲿȫ�ֱ������� -------------------------


//*********��������*****************************
//--0---- ������������ -------------------------

//--1---- �ⲿ�������� -------------------------
u8 EEPROM_Read (unsigned char addr_data);
void EEPROM_Write (unsigned char addr_data,unsigned char data);
void User_config_Read(void);
void User_config_store(void);
#endif 			//_EERPOM_H
