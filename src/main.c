#include <stdio.h>
#include "module1.h"
#include "debug.h"
#include "bsp.h"


#ifdef CONFIG_FULL
#  define PRODUCT_NAME		"FULL"
#endif
#ifdef CONFIG_STANDARD
#  define PRODUCT_NAME		"STANDARD"
#endif
#ifdef CONFIG_LITE
#  define PRODUCT_NAME		"LITE"
#endif

int
main(int argc, char *argv[])
{
	(void)argc,
	(void)argv;
	debug_printf("\n");
	bsp_init();

	debug_printf("Starting " PRODUCT_NAME "\n");
#ifdef PRINT_INTRO
	debug_printf("Intro\n");
#endif
#ifdef DEBUG
	debug_printf("Debug\n");
#endif
#ifdef RELEASE
	debug_printf("Release\n");
#endif	

	return 0;
}
