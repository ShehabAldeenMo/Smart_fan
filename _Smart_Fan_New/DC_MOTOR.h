/*
 *  File :DC_MOTOR.h
 *  DATE: 13/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion :CURT_PROJECT _ NEEDED TO COMPELET
 */
#include"../LIB/STD_TYPES.h"
#include"../LIB/BIT_MATH.h"

#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_

void PWM_VidInit(void);
void PWM_VidSetDuty (u8 Copy_U8Duty);
void DcMotor_VidRotate(u8 Copy_U8state);
void DcMotor_VidInit();

#endif /* DC_MOTOR_H_ */
