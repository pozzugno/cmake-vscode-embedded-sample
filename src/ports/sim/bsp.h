#ifndef BSP_H
#define BSP_H

#define LED         0

void bsp_init(void (*)(void));
void bsp_task(void);
void bsp_led_toggle(int led_idx);

#endif