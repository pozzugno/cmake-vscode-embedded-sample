#include <stdio.h>
#include <stdint.h>
#include "bsp.h"
#include "debug.h"

void
bsp_init(void)
{
    debug_printf("bsp_init()\n");
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
