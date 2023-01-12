/*
 * LED_BUZZER_src.c
 *
 *  Created on: Dec 23, 2022
 *      Author: 20109
 */
#include "../../SERVICES/stdtypes.h"
#include "../../MCAL/DIO/DIO_int.h"
#include "LED_BUZZER_int.h"
#include "LED_BUZZER_config.h"

/*----------LEDBUZZER_u8LedInit implementation----------*/
errorState_t LEDBUZZER_u8LedInit(led_ID_t led_IdCopy)
{
	errorState_t errorstate = E_OK;
	uint8 u8aLedPortId[8]={LED1_PORT, LED2_PORT, LED3_PORT, LED4_PORT, LED5_PORT, LED6_PORT, LED7_PORT, LED8_PORT};
	uint8 u8aLedPinId[8]={LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
	if(led_IdCopy>=0 && led_IdCopy<LED_NUMBERS)
	{
		DIO_u8SetPinDir(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],OUTPUT);
	}
	else
	{
		errorstate = E_NOK;
	}
	return errorstate;
}
/*----------LEDBUZZER_u8TurnLedOn implementation----------*/
errorState_t LEDBUZZER_u8TurnLedOn(led_ID_t led_IdCopy)
{
	errorState_t errorstate = E_OK;
	uint8 u8aLedPortId[8]={LED1_PORT, LED2_PORT, LED3_PORT, LED4_PORT, LED5_PORT, LED6_PORT, LED7_PORT, LED8_PORT};
	uint8 u8aLedPinId[8]={LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
	uint8 u8aLedConn[8]={LED1_CONN, LED2_CONN, LED3_CONN, LED4_CONN, LED5_CONN, LED6_CONN, LED7_CONN, LED8_CONN};
	if(led_IdCopy>=0 && led_IdCopy<LED_NUMBERS)
	{
		if(NEGATIVE == u8aLedConn[led_IdCopy])
		{
			DIO_u8SetPinVal(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],LOW);
		}
		else if(POSITIVE == u8aLedConn[led_IdCopy])
		{
			DIO_u8SetPinVal(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],HIGH);
		}
	}
	else
	{
		errorstate = E_NOK;
	}
	return errorstate;
}

/*----------LEDBUZZER_u8TurnLedOff implementation----------*/
errorState_t LEDBUZZER_u8TurnLedOff(led_ID_t led_IdCopy)
{
	errorState_t errorstate = E_OK;
		uint8 u8aLedPortId[8]={LED1_PORT, LED2_PORT, LED3_PORT, LED4_PORT, LED5_PORT, LED6_PORT, LED7_PORT, LED8_PORT};
		uint8 u8aLedPinId[8]={LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
		uint8 u8aLedConn[8]={LED1_CONN, LED2_CONN, LED3_CONN, LED4_CONN, LED5_CONN, LED6_CONN, LED7_CONN, LED8_CONN};
		if(led_IdCopy>=0 && led_IdCopy<LED_NUMBERS)
		{
			if(NEGATIVE == u8aLedConn[led_IdCopy])
			{
				DIO_u8SetPinVal(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],HIGH);
			}
			else if(POSITIVE == u8aLedConn[led_IdCopy])
			{
				DIO_u8SetPinVal(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],LOW);
			}
		}
		else
		{
			errorstate = E_NOK;
		}
		return errorstate;
}

/*----------LEDBUZZER_u8ToggleLed implementation----------*/
errorState_t LEDBUZZER_u8ToggleLed(led_ID_t led_IdCopy)
{
	errorState_t errorstate = E_OK;
	uint8 u8aLedPortId[8]={LED1_PORT, LED2_PORT, LED3_PORT, LED4_PORT, LED5_PORT, LED6_PORT, LED7_PORT, LED8_PORT};
	uint8 u8aLedPinId[8]={LED1_PIN, LED2_PIN, LED3_PIN, LED4_PIN, LED5_PIN, LED6_PIN, LED7_PIN, LED8_PIN};
	if(led_IdCopy>=0 && led_IdCopy<LED_NUMBERS)
	{
		DIO_u8SetPinVal(u8aLedPortId[led_IdCopy],u8aLedPinId[led_IdCopy],TOGGLE);
	}
	else
	{
		errorstate = E_NOK;
	}
	return errorstate;
}
