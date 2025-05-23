#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include "bsp.h"
#include "debug.h"

#define HB_INTERVAL_MS          1000

static uint64_t ticks_hb;
static void (*tmr_cb)(void);

static uint64_t get_us(void);

void
bsp_init(void (*cb)(void))
{
    debug_printf("bsp_init()\n");
    ticks_hb = get_us();
    ticks_hb += HB_INTERVAL_MS * 1000;
    tmr_cb = cb;
}

void
bsp_task(void)
{
    uint64_t ticks_now = get_us();

    if (ticks_now > ticks_hb) {
        ticks_hb += HB_INTERVAL_MS * 1000;
        tmr_cb();
    }
}

void 
debug_printf(const char *format, ...) 
{
    char buffer[128];
    va_list args;
    va_start(args, format);
    vsnprintf(buffer, sizeof(buffer), format, args);
    va_end(args);

    for (size_t i = 0; i < strlen(buffer); i++) {
        putchar(buffer[i]);
    }
}

void
bsp_led_toggle(int led_idx)
{
    debug_printf("bsp_led_toggle(%d)\n", led_idx);
}


static uint64_t
get_us(void)
{
    static LARGE_INTEGER pf = { .QuadPart = 0};
    if (pf.QuadPart == 0) {
        QueryPerformanceFrequency(&pf);     // ticks per second
    }

    LARGE_INTEGER counter;
    QueryPerformanceCounter(&counter);      // high-precision ticks

    /* Convert ticks in usec */
    uint64_t ret = counter.QuadPart * 1000000;
    ret /= pf.QuadPart;
    return ret;
}