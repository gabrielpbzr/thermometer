/*
 * File:   main.c
 * Author: gabriel
 *
 * Created on 3 de Abril de 2022, 10:19
 */


// CONFIG
#pragma config OSC = IntRC      // Oscillator Selection bits (internal RC oscillator)
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection off)
#pragma config MCLRE = OFF      // GP3/MCLR Pin Function Select bit (GP3/MCLR pin function is digital input, MCLR internally tied to VDD)

#include <stdbool.h>
#include <stdint.h>
#include "hardware.h"
#include "onewire.h"
#include "ds128b20.h"

//Duracao do buzzer
#define BUZZER_DELAY 500
// Temperatura limite em graus Celsius
#define TEMP_MAX 25

void main(void) {
    OPTION = 0x08;
    GPIO = 0x00;
    TRISGPIO = 0x3B;
    
    ds18b20_setup();
    
    while (true) {
        int16_t temperature = ds18b20_read_temperature();
        while(temperature > TEMP_MAX) {
            BUZZER_PIN = 1;
            __delay_ms(BUZZER_DELAY);
            BUZZER_PIN = 0;
            __delay_ms(BUZZER_DELAY);
            BUZZER_PIN = 1;
            __delay_ms(BUZZER_DELAY);
            BUZZER_PIN = 0;
            __delay_ms(BUZZER_DELAY);
            temperature = ds18b20_read_temperature();
        }
        BUZZER_PIN = 0;
        // wait
        __delay_ms(5000);
    }
}
