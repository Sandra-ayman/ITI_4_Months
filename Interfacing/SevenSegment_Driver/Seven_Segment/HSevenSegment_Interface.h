/*
 * HSevenSegment_Interface.h
 *
 *  Created on: Jan 26, 2023
 *      Author: 20109
 */

#ifndef HAL_SEVEN_SEGMENT_HSEVENSEGMENT_INTERFACE_H_
#define HAL_SEVEN_SEGMENT_HSEVENSEGMENT_INTERFACE_H_

/*----------New Data types----------*/
typedef enum sevenSegmentID{SEVENSEGMENT1,SEVENSEGMENT2}sevenSegmentID_t;

/*
 * Description: initialization of seven segment
 * Parameters: Seven_Segment_ID
 * Return: error status
 */
errorState_t HSevenSegment_u8Init(sevenSegmentID_t Copy_u8SevenSegmentID);
/*
 * Description: Write a specific number
 * Parameters: Seven_Segment_ID, number
 * Return: error status
 */
errorState_t HSevenSegment_u8WriteNumber(sevenSegmentID_t Copy_u8SevenSegmentID, uint8 Copy_u8Number);
/*
 * Description: Write blank
 * Parameters: Seven_Segment_ID
 * Return: error status
 */
errorState_t HSevenSegment_u8WriteBlank(sevenSegmentID_t Copy_u8SevenSegmentID);

#endif /* HAL_SEVEN_SEGMENT_HSEVENSEGMENT_INTERFACE_H_ */
