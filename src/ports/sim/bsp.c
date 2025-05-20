#include <stdio.h>
#include "bsp.h"
#include "debug.h"

void
bsp_init(void)
{
    printf("bsp_init()\n");
}

void
debug_printf(const char *s)
{
    printf(s);
}