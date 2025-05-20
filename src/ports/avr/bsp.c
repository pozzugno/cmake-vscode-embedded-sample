#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include "bsp.h"
#include "debug.h"

static void start_timer(void);

void
bsp_init(void)
{
    debug_printf("bsp_init()\n");
    start_timer();
}

void
bsp_task(void)
{
}

void
debug_printf(const char *s)
{
    printf(s);
}

static void
start_timer(void)
{
    const unsigned char TMR1_WGM = 4;       // CTC (TOP=OCR1A)
    const unsigned char TMR1_CS = 5;        // Prescaler 1024
    //const unsigned int TMR1_CLK_US = 1000000 * 1024 / F_CPU;
    
    TCNT1 = 0;
    TCCR1A = (TMR1_WGM & 0x3) << WGM00; 
    OCR1A = 100;
    TCCR1B = (((TMR1_WGM >> 2) & 0x03) << WGM12) | (TMR1_CS << CS10);
}