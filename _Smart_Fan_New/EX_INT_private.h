/*
 * INT_private.h
 *
 *  Created on: ??�/??�/????
 *      Author: HP
 */


#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#ifndef INT_PRIVATE_H_
#define INT_PRIVATE_H_

#define HIGH 1
#define LOW 0

#define PORTB 1
#define PB2 2

#define PORTD 3
#define PD2 2
#define PD3 3


/*#define SREG *((volatile u8*)(0x5F))
#define I_BIT 7*/

#define GICR *((volatile u8*)(0x5B))

#define MCUCR *((volatile u8*)(0x55))
#define ISC11  3
#define ISC10  2
#define ISC01  1
#define ISC00 0

#define MCUCSR  *((volatile u8*)(0x54))
#define ISC2 6

void __vector_1(void)    __attribute__((signal));
void __vector_2(void)    __attribute__((signal));
void __vector_3(void)    __attribute__((signal));

#endif /* INT_PRIVATE_H_ */
