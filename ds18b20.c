#include "ds128b20.h"

#define BIT_SIGNAL_MASK 0x80

void ds18b20_setup(void) {
    bool ok = ow_reset();
    if (!ok) {
        BUZZER_PIN = 1;
        __delay_ms(50);
        BUZZER_PIN = 0;
        __delay_ms(50);
        BUZZER_PIN = 1;
        __delay_ms(50);
        BUZZER_PIN = 0;
        return;
    }
    ow_write(DS18B20_SKIP_ROM);
    ow_write(DS18B20_WRITE);
    ow_write(0x00); // Zera registrador alarme 1
    ow_write(0x00); // Zera registrador alarme 2
    ow_write(DS18B20_RESOLUTION_9_BIT);
}

int16_t ds18b20_read_temperature(void) {
    ow_reset();
    ow_write(DS18B20_SKIP_ROM);
    ow_write(DS18B20_CONVERT);
    __delay_ms(DS18B20_CONVERT_DELAY_MS_9_BIT);

    ow_reset();
    ow_write(DS18B20_SKIP_ROM);
    ow_write(DS18B20_READ);

    // A partir de agora o sensor irá enviar 4 bytes. Vamos precisar
    // só dos dois primeiros (Tl e Th)

    uint8_t lsb = ow_read();
    uint8_t msb = ow_read();
    ow_reset(); // Encerra a comunicação com o sensor
    
    /*
     * Estrutura do pacote de bytes
     *  -------------------------------------
     * | bit  7   6   5   4   3   2   1   0  |
     * |-------------------------------------|
     * | LSB  v   v   v   v   d   d   d   d  |
     * | MSB  s   s   s   s   s   v   v   v  |
     *  -------------------------------------
     * 
     * v -> valor inteiro da temperatura
     * s -> sinal (1 temperatura negativa)
     * d -> valor decimal (iniciando em 2^-4 no bit mais a direita)
     */
    
    int16_t temp = (msb<< 8) | lsb;
    //temp = temp & 0x0FF0; // Mantém somente o bit 4 para indicar o sinal (se 1 a temperatura é negativa)
    temp = (temp >> 4); // Ignora os 4 últimos bits (indicam o valor decimal)
    
    return temp;
}
