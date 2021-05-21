#ifndef __DEV_SYSTICK_H__
#define __DEV_SYSTICK_H__

#include "main.h"

void systick_init(void);
void swm_inctick(void);
uint32_t swm_gettick(void);
void swm_delay(unsigned int delay);

#endif //__DEV_SYSTICK_H__
