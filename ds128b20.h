/* 
 * File:   ds128b20.h
 * Author: gabriel
 *
 * Created on 14 de Abril de 2022, 14:28
 */

#ifndef DS128B20_H
#define	DS128B20_H
#include "onewire.h"
    
// Comandos para comunicação com o DS18B20
#define DS18B20_SKIP_ROM 0xCC
#define DS18B20_CONVERT 0x44
#define DS18B20_READ 0xBE
#define DS18B20_WRITE 0x4E

#define DS18B20_RESOLUTION_9_BIT 0x1F // 93.75ms
#define DS18B20_RESOLUTION_10_BIT 0x3F // 187.5ms
#define DS18B20_RESOLUTION_11_BIT 0x5F // 375ms
#define DS18B20_RESOLUTION_12_BIT 0x7F // 750ms
    
#define DS18B20_CONVERT_DELAY_MS_9_BIT 95 //ms
#define DS18B20_CONVERT_DELAY_MS_10_BIT 186 //ms
#define DS18B20_CONVERT_DELAY_MS_11_BIT 375 //ms
#define DS18B20_CONVERT_DELAY_MS_12_BIT 750 //ms

#ifdef	__cplusplus
extern "C" {
#endif    
    /**
     * Setup the temperature sensor
     */
    void ds18b20_setup(void);
    /**
     * Get sensor readings
     * @return temperature
     */
    short ds18b20_read_temperature(void);
    
#ifdef	__cplusplus
}
#endif

#endif	/* DS128B20_H */

