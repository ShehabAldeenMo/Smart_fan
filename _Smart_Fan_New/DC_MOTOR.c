/*
 *  File : DC_MOTOR.c
 *  DATE: 13/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion :CURT_PROJECT _ NEEDED TO COMPELET
 */

#include "avr/io.h"
#include <util/delay.h>
#include "DC_MOTOR.h"
#include "DIO_interface.h"
#include "DCMOTOR_cfg.h"
#include "DC_MOTOR_private.h"



void PWM_VidInit()
{
	/*set fast PWM mode with non-inverted output*/
	TCCR0 = (1<<WGM00) | (1<<WGM01) | (1<<COM01) | (1<<CS00);
    DIO_VidSetPinDirection(PWM_PORT,PWM_PIN,HIGH);
}

void PWM_VidSetDuty (u8 Copy_U8Duty){
	OCR0 = Copy_U8Duty ;
	if (Copy_U8Duty == 0)
		 DcMotor_VidRotate(STOP);
	else
		DcMotor_VidRotate(CLK_WISE);
}

void DcMotor_VidInit(void){
	/*set the direction of the two input pins of the dc motor to be output pins */
	DIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
	DIO_VidSetPinDirection(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);

	/*initialize the dc motor to be stop at the beginning*/
	DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
	DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
}

void DcMotor_VidRotate(u8 Copy_U8state){
	switch(Copy_U8state){
	case STOP:
		/*make the dc motor stop*/
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
		break;
	case CLK_WISE:
		/*make the dc motor start in CLOCK_WISE direction*/
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , LOW);
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , HIGH);
		break;
	case ANTI_CLK_WISE:
		/*make the dc motor start in ANTI_CLOCK_WISE  direction*/
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN1 , HIGH);
		DIO_VidSetPinValue(DC_MOTOR_PORT , DC_MOTOR_PIN2 , LOW);
		break;
	}
}

