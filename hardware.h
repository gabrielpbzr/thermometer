/* 
 * File:   hardware.h
 * Author: gabriel
 *
 * Created on 14 de Abril de 2022, 14:17
 * 
 * 
 * HARDWARE MAPPING
 *      _________
 *     |         |
 * VCC_|         |_GND
 * GP5_|   uC    |_GP0
 * GP4_|         |_GP1
 * GP3_|         |_GP2
 *     |_________|
 */

#ifndef HARDWARE_H
#define	HARDWARE_H

#include <xc.h>
#define _XTAL_FREQ 4000000L // 4 MHz

#ifdef	__cplusplus
extern "C" {
#endif

#define DQ_PIN GP5
#define BUZZER_PIN GP2


#ifdef	__cplusplus
}
#endif

#endif	/* HARDWARE_H */

