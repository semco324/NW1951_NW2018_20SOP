
#ifndef 		_EERPOM_H
#define 		_EERPOM_H

#include	"MyDefine.h"
#include	"Variants.h"

//*********全局变量声明*****************************
//--0---- 本部全局变量声明 -------------------------

//--1---- 外部全局变量声明 -------------------------


//*********函数声明*****************************
//--0---- 本部函数声明 -------------------------

//--1---- 外部函数声明 -------------------------
u8 EEPROM_Read (unsigned char addr_data);
void EEPROM_Write (unsigned char addr_data,unsigned char data);
void User_config_Read(void);
void User_config_store(void);
#endif 			//_EERPOM_H
