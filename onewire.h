/* 
 * File:   onewire.h
 * Author: gabriel
 *
 * Created on 14 de Abril de 2022, 14:10
 */

#ifndef ONEWIRE_H
#define	ONEWIRE_H

#include <stdint.h>
#include <stdbool.h>
#include "hardware.h"

// Macros para a comunicação ONEWIRE
#define OW_HIGH TRISGPIO = 0x3B;
#define OW_LOW  TRISGPIO = 0x1B;

#ifdef	__cplusplus
extern "C" {
#endif

    /**
     * Reset one wire bus
     */
    bool ow_reset(void);
    
    /**
     * Write a byte to one wire bus
     * @param data byte to be written
     */
    void ow_write(uint8_t data);
    
    /**
     * Read a byte from one wire bus
     * @return byte data
     */
    uint8_t ow_read(void);


#ifdef	__cplusplus
}
#endif

#endif	/* ONEWIRE_H */

