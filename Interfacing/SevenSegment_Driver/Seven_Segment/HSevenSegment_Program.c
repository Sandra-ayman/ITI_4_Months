/*
 * HSevenSegment_Program.c
 *
 *  Created on: Jan 26, 2023
 *      Author: 20109
 */
#include "../../SERVICES/stdtypes.h"
#include "HSevenSegment_Private.h"
#include "HSevenSegement_Config.h"
#include "HSevenSegment_Interface.h"
#include "../../MCAL/DIO/DIO_int.h"

/*----------HSevenSegment_u8Init Implementation----------*/
errorState_t HSevenSegment_u8Init(sevenSegmentID_t Copy_u8SevenSegmentID)
{
	errorState_t ErrorState=E_OK;
	uint8 u8aSevenSegmentDirection[2]={SEVENSEGMENT1_PORT,SEVENSEGMENT2_PORT};
	if(Copy_u8SevenSegmentID >= 0 && Copy_u8SevenSegmentID <= 2)
	{
		DIO_u8SetPortDir(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],0xFF);
	}
	else
	{
		ErrorState = E_NOK;
	}
	return ErrorState;
}

/*----------HSevenSegment_u8WriteNumber Implementation----------*/
errorState_t HSevenSegment_u8WriteNumber(sevenSegmentID_t Copy_u8SevenSegmentID, uint8 Copy_u8Number)
{
	errorState_t ErrorState=E_OK;
	uint8 u8aSevenSegmentDirection[2]={SEVENSEGMENT1_PORT,SEVENSEGMENT2_PORT};
	uint8 u8aSevenSegmentConnection[2]={SEVENSEGMENT1_CONNECTION,SEVENSEGMENT2_CONNECTION};
	if(Copy_u8SevenSegmentID >= 0 && Copy_u8SevenSegmentID <= 2)
	{
		if(COMMON_CATHODE ==u8aSevenSegmentConnection[Copy_u8SevenSegmentID])
		{
			switch(Copy_u8Number)
			{
			case 0:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_ZERO_NUMBER);
				break;
			case 1:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_ONE_NUMBER);
				break;
			case 2:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_TWO_NUMBER);
				break;
			case 3:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_THREE_NUMBER);
				break;
			case 4:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_FOUR_NUMBER);
				break;
			case 5:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_FIVE_NUMBER);
				break;
			case 6:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_SIX_NUMBER);
				break;
			case 7:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_SEVEN_NUMBER);
				break;
			case 8:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_EIGHT_NUMBER);
				break;
			case 9:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_NINE_NUMBER);
				break;
			}

		}
		else if(COMMON_ANODE ==u8aSevenSegmentConnection[Copy_u8SevenSegmentID])
		{
			switch(Copy_u8Number)
			{
			case 0:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_ZERO_NUMBER);
				break;
			case 1:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_ONE_NUMBER);
				break;
			case 2:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_TWO_NUMBER);
				break;
			case 3:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_THREE_NUMBER);
				break;
			case 4:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_FOUR_NUMBER);
				break;
			case 5:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_FIVE_NUMBER);
				break;
			case 6:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_SIX_NUMBER);
				break;
			case 7:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_SEVEN_NUMBER);
				break;
			case 8:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_EIGHT_NUMBER);
				break;
			case 9:
				DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_NINE_NUMBER);
				break;
			}
		}
	}
	else
	{
		ErrorState = E_NOK;
	}
	return ErrorState;
}

/*----------HSevenSegment_u8WriteNumber Implementation----------*/
errorState_t HSevenSegment_u8WriteBlank(sevenSegmentID_t Copy_u8SevenSegmentID)
{
	errorState_t ErrorState=E_OK;
	uint8 u8aSevenSegmentDirection[2]={SEVENSEGMENT1_PORT,SEVENSEGMENT2_PORT};
	uint8 u8aSevenSegmentConnection[2]={SEVENSEGMENT1_CONNECTION,SEVENSEGMENT2_CONNECTION};
	if(Copy_u8SevenSegmentID >= 0 && Copy_u8SevenSegmentID <= 2)
	{
		if(COMMON_CATHODE ==u8aSevenSegmentConnection[Copy_u8SevenSegmentID])
		{
			DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],CATHODE_BLANK_NUMBER);
		}
		else if(COMMON_ANODE ==u8aSevenSegmentConnection[Copy_u8SevenSegmentID])
		{
			DIO_u8SetPortVal(u8aSevenSegmentDirection[Copy_u8SevenSegmentID],ANODE_BLANK_NUMBER);
		}
	}
	else
	{
		ErrorState = E_NOK;
	}
	return ErrorState;
}
