#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "Variants.h"

/* �������� */
void Delay_100XuS(u8 delay);
void bbu_detetedmode(void);
void bbu_poweroff(void);
void bbu_charge(void);
void bbu_discharge(void);
void bbu_safety(void);
void led_display(void);
void get_calibration_factor(void);
u8 dtob(float data);
u16 get_calibration(u16 para);



/* �ⲿ���� */
extern void GetBattery_Level (void);

extern unsigned int ADC_Read (void);

extern void User_config_store(void);


#endif//__FUNCTION_H__
