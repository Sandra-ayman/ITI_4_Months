/*
 * DIO_src.c
 *
 *  Created on: Dec 22, 2022
 *      Author: 20109
 */
#include "../../SERVICES/stdtypes.h"
#include "../../SERVICES/bit_math.h"
#include "DIO_private.h"
#include "DIO_int.h"
/*----------DIO_u8SetPortDir implementation----------*/
errorState_t DIO_u8SetPortDir(portID_t u8PortIdCopy, uint8 u8PortDirCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortDirRegAdd[4]={PORT_A_Dir_REG, PORT_B_Dir_REG, PORT_C_Dir_REG, PORT_D_Dir_REG};
	if (u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		*u8pPortDirRegAdd[u8PortIdCopy]=u8PortDirCopy;
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
/*----------DIO_u8SetPortVal implementation----------*/
errorState_t DIO_u8SetPortVal(portID_t u8PortIdCopy, uint8 u8PortValCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortOutRegAdd[4]={PORT_A_Out_REG, PORT_B_Out_REG, PORT_C_Out_REG, PORT_D_Out_REG};
	if(u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		*u8pPortOutRegAdd[u8PortIdCopy]=u8PortValCopy;
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
/*----------DIO_u8GetPortVal implementation----------*/
errorState_t DIO_u8GetPortVal(portID_t u8PortIdCopy, uint8 *u8pPortValCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortInRegAdd[4]={ PORT_A_In_REG, PORT_B_In_REG, PORT_C_In_REG, PORT_D_In_REG};
	if(u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		*u8pPortValCopy = *u8pPortInRegAdd[u8PortIdCopy];
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
/*----------DIO_u8SetPinDir implementation----------*/
errorState_t DIO_u8SetPinDir(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, pinDir_t u8PinDirCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortDirRegAdd[4]={PORT_A_Dir_REG, PORT_B_Dir_REG, PORT_C_Dir_REG, PORT_D_Dir_REG};
	if(u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		if(u8PinIdCopy>=0 && u8PinIdCopy<=7)
		{
			if(INPUT == u8PinDirCopy)
			{
				CLR_BIT(*u8pPortDirRegAdd[u8PortIdCopy],u8PinIdCopy);
			}
			else if(OUTPUT == u8PinDirCopy)
			{
				SET_BIT(*u8pPortDirRegAdd[u8PortIdCopy],u8PinIdCopy);
			}
			else
			{
				errorstate=E_NOK;
			}
		}
		else
		{
			errorstate=E_NOK;
		}
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
/*----------DIO_u8SetPinVal implementation----------*/
errorState_t DIO_u8SetPinVal(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, pinValue_t u8PinValCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortOutRegAdd[4]={PORT_A_Out_REG, PORT_B_Out_REG, PORT_C_Out_REG, PORT_D_Out_REG};
	if(u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		if(u8PinIdCopy>=0 && u8PinIdCopy<=7)
		{
			if(HIGH == u8PinValCopy)
			{
				SET_BIT(*u8pPortOutRegAdd[u8PortIdCopy],u8PinIdCopy);
			}
			else if(LOW ==u8PinValCopy)
			{
				CLR_BIT(*u8pPortOutRegAdd[u8PortIdCopy],u8PinIdCopy);
			}
			else if(TOGGLE == u8PinValCopy)
			{
				TOGGLE_BIT(*u8pPortOutRegAdd[u8PortIdCopy],u8PinIdCopy);
			}
			else
			{
				errorstate=E_NOK;
			}
		}
		else
		{
			errorstate=E_NOK;
		}
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
/*----------DIO_u8GetPinVal implementation----------*/
errorState_t DIO_u8GetPinVal(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, uint8 *u8pPinValCopy)
{
	errorState_t errorstate=E_OK;
	uint8 *u8pPortInRegAdd[4]={ PORT_A_In_REG, PORT_B_In_REG, PORT_C_In_REG, PORT_D_In_REG};
	if(u8PortIdCopy>=0 && u8PortIdCopy<=3)
	{
		if(u8PinIdCopy>=0 && u8PinIdCopy<=7)
		{
			*u8pPinValCopy = GET_BIT(*u8pPortInRegAdd[u8PortIdCopy],u8PinIdCopy);
		}
		else
		{
			errorstate=E_NOK;
		}
	}
	else
	{
		errorstate=E_NOK;
	}
	return errorstate;
}
