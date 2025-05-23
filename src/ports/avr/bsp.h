#ifndef BSP_H
#define BSP_H

#define PIN_LED     D, 7
#define LED         1

void bsp_init(void (*)(void));
void bsp_task(void);
void bsp_led_toggle(unsigned char led_idx);

#endif