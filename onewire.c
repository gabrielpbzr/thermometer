#include "hardware.h"
#include "onewire.h"

bool ow_reset(void) {
    DQ_PIN = 0;
    OW_LOW
    __delay_us(480);
    OW_HIGH
    __delay_us(60);
    bool hasResponse = (DQ_PIN == 0);
    __delay_us(240);
    
    return hasResponse;
}

void ow_write(uint8_t value) {
    DQ_PIN = 0;
    for (uint8_t i = 0; i < 8; i++) {
        if (value & (1 << i)) {
            OW_LOW
            __delay_us(5);
            OW_HIGH
            __delay_us(55);
        } else { // write zero
            OW_LOW
            __delay_us(55);
            OW_HIGH
            __delay_us(5);
        }
        __delay_us(1);
    }
}

uint8_t ow_read() {
    uint8_t data = 0;
    for (uint8_t i = 0; i < 8; i++) {
        DQ_PIN = 0;
        OW_LOW
        __delay_us(5);
        OW_HIGH
        __delay_us(15);
        if (DQ_PIN == 1) {
            data |= 0x01;
        }
        data <<= 1;
        __delay_us(1);
    }

    return data;
}
