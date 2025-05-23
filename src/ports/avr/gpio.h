// Copyright (c) 2007 Roboterclub Aachen e.V.
#ifndef GPIO_H
#define GPIO_H

struct bits {
  unsigned b0:1;
  unsigned b1:1;
  unsigned b2:1;
  unsigned b3:1;
  unsigned b4:1;
  unsigned b5:1;
  unsigned b6:1;
  unsigned b7:1;
} __attribute__((__packed__));

#define SBIT_(port,pin) ((*(volatile struct bits*)&port).b##pin)
#define	SBIT(x,y)	SBIT_(x,y)

// use this block of macros in your code
#define   GPIO_RESET(x)       				RESET2(x)
#define   GPIO_SET(x)         				SET2(x)
#define   GPIO_TOGGLE(x)      				TOGGLE2(x)
#define   GPIO_SET_OUTPUT(x)  				SET_OUTPUT2(x)
#define   GPIO_SET_INPUT(x)   				SET_INPUT2(x)
#define   GPIO_SET_PULLUP(x)  				SET2(x)
#define   GPIO_IS_SET(x)      				IS_SET2(x)
#define   GPIO_SET_INPUT_WITH_PULLUP(x)  	SET_INPUT_WITH_PULLUP2(x)

#define   PORT(x)        	_port2(x)
#define   DDR(x)         	_ddr2(x)
#define   PIN(x)         	_pin2(x)
#define   REG(x)         	_reg(x)
#define   PIN_NUM(x)     	_pin_num(x)

#define   _port2(x)   		PORT ## x
#define   _ddr2(x)   		DDR ## x
#define   _pin2(x)   		PIN ## x

#define   _reg(x,y)			x
#define   _pin_num(x,y)		y

#define   RESET2(x,y)      	PORT(x) &= ~(1<<y)
#define   SET2(x,y)      	PORT(x) |= (1<<y)
#define   TOGGLE2(x,y)   	PORT(x) ^= (1<<y)
#define   SET_OUTPUT2(x,y)  DDR(x) |= (1<<y)
#define   SET_INPUT2(x,y)   DDR(x) &= ~(1<<y)
#define   SET_INPUT_WITH_PULLUP2(x,y)   SET_INPUT2(x,y);SET2(x,y)

#define   IS_SET2(x,y)   ((PIN(x) & (1<<y)) != 0) 

#endif /* _gpio_h_ */
