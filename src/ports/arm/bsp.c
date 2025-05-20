#include <stdbool.h>
#include "bsp.h"
#include "debug.h"

static bool init = false;

void
bsp_init(void)
{
    init = true;
}

void
debug_printf(const char *s)
{
    (void)s;
}