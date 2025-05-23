#include <avr/io.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "bsp.h"
#include "gpio.h"
#include "debug.h"

#define BAUD            9600
#define MYUBRR          (F_CPU / 16 / BAUD - 1)

void usart_init(uint16_t ubrr);
char usart_getchar( void );
void usart_putchar( char data );
void usart_pstr (char *s);
unsigned char usart_kbhit(void);
int usart_putchar_printf(char var, FILE *stream);

static void start_timer(void);
static bool timer_flag(void);

static FILE mystdout = FDEV_SETUP_STREAM(usart_putchar_printf, NULL, _FDEV_SETUP_WRITE);
static void (*tmr_cb)(void);

void
bsp_init(void (*cb)(void))
{
    stdout = &mystdout;
    usart_init (MYUBRR);
    debug_printf("bsp_init()\n");

    GPIO_SET_OUTPUT(PIN_LED);
    start_timer();
    tmr_cb = cb;
}

void
bsp_task(void)
{
    if (timer_flag()) {
        tmr_cb();
    }
}

void
debug_printf(const char *format, ...)
{
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

void
bsp_led_toggle(unsigned char led_idx)
{
    if (led_idx == LED) GPIO_TOGGLE(PIN_LED);
}

// ********************************************************************************
// usart Related
// ********************************************************************************
void 
usart_init( uint16_t ubrr) 
{
    // Set baud rate
    UBRR0H = (uint8_t)(ubrr>>8);
    UBRR0L = (uint8_t)ubrr;
    // Enable receiver and transmitter
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);
    // Set frame format: 8data, 1stop bit
    UCSR0C = (3<<UCSZ00);
}
void 
usart_putchar(char data) 
{
    // Wait for empty transmit buffer
    while ( !(UCSR0A & (_BV(UDRE0))) );
    // Start transmission
    UDR0 = data; 
}
char usart_getchar(void) {
    // Wait for incoming data
    while ( !(UCSR0A & (_BV(RXC0))) );
    // Return the data
    return UDR0;
}
unsigned char usart_kbhit(void) {
    //return nonzero if char waiting polled version
    unsigned char b;
    b=0;
    if(UCSR0A & (1<<RXC0)) b=1;
    return b;
}
void usart_pstr(char *s) {
    // loop through entire string
    while (*s) { 
        usart_putchar(*s);
        s++;
    }
}
    
// this function is called by printf as a stream handler
int usart_putchar_printf(char var, FILE *stream) {
    // translate \n to \r for br@y++ terminal
    (void)stream;
    if (var == '\n') usart_putchar('\r');
    usart_putchar(var);
    return 0;
}

static void
start_timer(void)
{
    const unsigned char TMR1_WGM = 4;       // CTC (TOP=OCR1A)
    const unsigned char TMR1_CS = 5;        // Prescaler 1024
    const unsigned int TMR1_CLK_US = 1000000 * 1024 / F_CPU;
    
    TCNT1 = 0;
    TCCR1A = (TMR1_WGM & 0x3) << WGM00; 
    OCR1A = 1000000 / TMR1_CLK_US;
    TCCR1B = (((TMR1_WGM >> 2) & 0x03) << WGM12) | (TMR1_CS << CS10);
}

static bool
timer_flag(void)
{
    if (TIFR1 & (1 << OCF1A)) {
        TIFR1 = 1 << OCF1A;
        return true;
    }
    return false;
}