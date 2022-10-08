/*
 * DC_MOTOR_private.h
 *  DATE: 13/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion :CURT_PROJECT _ NEEDED TO COMPELET
 */

#ifndef DC_MOTOR_PRIVATE_H_
#define DC_MOTOR_PRIVATE_H_

//define logic voltages
#define HIGH 1
#define LOW 0

//define wanted states
#define STOP 0
#define CLK_WISE 1
#define ANTI_CLK_WISE 2

//define PORT
#define PORTA 0
#define PORTB 1
#define PORTC 2
#define PORTD 3

//define PWM registers
#define TCCR0 *((volatile u8*)(0x53))
#define WGM00 6
#define WGM01 3
#define COM01 5
#define CS00 0
#define OCR0 *((volatile u8*)(0x5C))

#endif /* DC_MOTOR_PRIVATE_H_ */
