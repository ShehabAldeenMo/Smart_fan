/*
 *  File : main.c
 *  DATE: 13/9/2022
 *  Author: Shehab aldeen
 *  Version : V1
 *  Describtion :CURT_PROJECT
 */

#include"DIO_interface.h"
#include"LCD_Interface.h"
#include"DC_MOTOR.h"
#include"INTERRUPT_Interface.h"
#include"ADC_interface.h"
#include"EX_INT_Interface.h"
#include"INTERRUPT_Interface.h"
#include "Smart_fan.h"

u8 CURT_GLOBAL_FLAG ;
u8 temp ;
void INT2_FUNCTION ();

void main (void){
    GIE_VidEnable();                                      //to open global interrupt
    EX_INT_VidINIT();                                     //to initialize EX_INTERRUPT 2
    EX_PIE_VidEnable(2);                                  //to enable interrupt
    EX_INT_VidSetCallBack(2,INT2_FUNCTION);               //pointer to function in int_2
	u8 local_duty ;                                       //define wanted duty

	//define PUSH_BUTTON I/P pin
	DIO_VidSetPinDirection(PUSH_BUTTON_PORT,PUSH_BUTTON,LOW);

	//to intialize DC_MOTOR
	DcMotor_VidInit();

	//to intialize PWM
	PWM_VidInit();

	//to initailize LCD
	LCD_VidInit();

	//initialize ADC
	ADC_VidInit();

	//define wanted leds as outputs :
    DIO_VidSetPinDirection(portD,GREEN_LED,HIGH);
    DIO_VidSetPinDirection(portD,YELLOW_LED,HIGH);
    DIO_VidSetPinDirection(portD,RED_LED,HIGH);

    //define buzzer pin as output
    DIO_VidSetPinDirection(portB,BUZZER_PIN,HIGH);
	DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);

    while (1){
    	temp = ( ADC_VidReadChannel(0) )/10 ;

    	//if LM35 sensor <20 display degree _ on GREEN LED _ off RED and YELLOW _ stop motor
    	if ( temp <= 20 ){
	      	temp = ( ADC_VidReadChannel(0) )/10 ;

            // to rotate with min speed
    		local_duty = 0 ;
    		PWM_VidSetDuty (local_duty) ;

            // to make leds state
    		DIO_VidSetPinValue(portD,GREEN_LED,HIGH);
    		DIO_VidSetPinValue(portD,YELLOW_LED,LOW);
    		DIO_VidSetPinValue(portD,RED_LED,LOW);

            //to display temperature
       	    LCD_VidPosCur(0,0);
         	LCD_VidSendString("TEMPERATURE : ");
    		LCD_VidPosCur(1,0);
    		LCD_VidPrintVar(temp);

    		//to turn_off buzzer
    		DIO_VidSetPinValue(portB,BUZZER_PIN,LOW);
    	}//end if

    	//if LM35 sensor 20:40 display degree _ on YELLOW LED _ off RED and GREEN _ rotate motor
    	else if ( temp>20 &&temp <40  ){
	      	temp = ( ADC_VidReadChannel(0) )/10 ;

    		//to display temperature
    		LCD_VidPosCur(0,0);
    		LCD_VidSendString("TEMPERATURE : ");
    		LCD_VidPosCur(1,0);
    		LCD_VidPrintVar(temp);

            // to rotate with calculated speed
        	local_duty = (temp-20)*13 ;
    		PWM_VidSetDuty (local_duty) ;

    		// to make leds state
    		DIO_VidSetPinValue(portD,GREEN_LED,LOW);
    		DIO_VidSetPinValue(portD,YELLOW_LED,HIGH);
    		DIO_VidSetPinValue(portD,RED_LED,LOW);

    		//to turn_off buzzer
    		DIO_VidSetPinValue(portB,BUZZER_PIN,LOW);
    	}//end else if

    	//if LM35 sensor >40 display degree _ on RED LED _ off YELLOW and GREEN
    	else   {
		    //raise flag
    		CURT_GLOBAL_FLAG = 1 ;

		    // to rotate with max speed
		    local_duty = 255 ;

		      while (CURT_GLOBAL_FLAG){
		      	temp = ( ADC_VidReadChannel(0) )/10 ;
	    		PWM_VidSetDuty (local_duty) ;

	    		// to make leds state
	    		DIO_VidSetPinValue(portD,GREEN_LED,LOW);
	    		DIO_VidSetPinValue(portD,YELLOW_LED,LOW);
	    		DIO_VidSetPinValue(portD,RED_LED,HIGH);

	    		//to display temperature and warning massage
	    		LCD_VidPosCur(0,0);
	    		LCD_VidSendString("WARNING HIGH ");
	    		LCD_VidPosCur(1,0);
	    		LCD_VidSendString("TEMPERATURE: ");
	    		LCD_VidPosCur(1,13);
	    		LCD_VidPrintVar(temp);

	    		//to turn_on buzzer
	    		DIO_VidSetPinValue(portB,BUZZER_PIN,HIGH);
		         }//end while
				LCD_VidClear();               		                            //to clear LCD
				DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);           		//to turn_off buzzer
    	}//end else if
    }//end while
}//end main

void INT2_FUNCTION (){
	if (temp < 40  && CURT_GLOBAL_FLAG == 1 ){
		LCD_VidClear();               		                            //to clear LCD
		DIO_VidSetPinValue(BUZZER_PORT,BUZZER_PIN,LOW);           		//to turn_off buzzer
		CURT_GLOBAL_FLAG = 0 ;                                          //fall flag
	}
}
