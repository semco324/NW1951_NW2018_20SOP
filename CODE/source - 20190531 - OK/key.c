#include "key.h"

//===============================================================
//function: void led_display(void).
//input   : NULL.
//output  : NULL
//description: 关机按键检测,长按3S有效.
//===============================================================
void key_scan(void)
{
	if (!P_KEY){
		R_intkeydebounce++;
		if(C_KEY_DEBOUNC <= R_intkeydebounce){
			R_intkeydebounce = 0;
			if(!f_keypress){
				f_keypress = 1;
				if(C_DISCHARGE_MODE == R_workmode){
					R_workmode = C_SAFETY_MODE;
					f_safetyinit = 1;
					f_key2off = 1;
				}
			}
		}
	}else{
		R_intkeydebounce = 0;
		f_key2off = 0;
		f_keypress = 0;
	}
}

