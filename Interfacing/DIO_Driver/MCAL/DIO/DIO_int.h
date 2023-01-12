/*
 * DIO_int.h
 *
 *  Created on: Dec 22, 2022
 *      Author: 20109
 */

#ifndef MCAL_DIO_INT_H_
#define MCAL_DIO_INT_H_
/*-----------New data types----------*/
typedef enum{PORT_A,PORT_B,PORT_C,PORT_D}portID_t;
typedef enum{PIN_0, PIN_1, PIN_2, PIN_3, PIN_4, PIN_5, PIN_6, PIN_7}pinID_t;
typedef enum{INPUT,OUTPUT}pinDir_t;
typedef enum{LOW,HIGH,TOGGLE}pinValue_t;
typedef enum{E_OK,E_NOK}errorState_t;

/*
 * Function: set port direction
 * Parameters: port id, i/p combination
 * Return: Error state
 */
errorState_t DIO_u8SetPortDir(portID_t u8PortIdCopy, uint8 u8PortDirCopy);

/*
 * Function: set output value of port
 * Parameters: port id, o/p combination
 * Return: Error state
 */
errorState_t DIO_u8SetPortVal(portID_t u8PortIdCopy, uint8 u8PortValCopy);

/*
 * Function: get value of port
 * Parameters: port id, address of variable to store port value
 * Return: Error state
 */
errorState_t DIO_u8GetPortVal(portID_t u8PortIdCopy, uint8 *u8pPortValCopy);

/*
 * Function: set pin direction
 * Parameters: port id, pin id, state(input, output)
 * Return: Error state
 */
errorState_t DIO_u8SetPinDir(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, pinDir_t u8PinDirCopy);

/*
 * Function: set output value of pin
 * Parameters: port id, pin id, state(high, low, toggle)
 * Return: Error state
 */
errorState_t DIO_u8SetPinVal(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, pinValue_t u8PinValCopy);

/*
 * Function: get value of pin
 * Parameters: port id, pin id, address of variable to store pin value
 * Return: Error state
 */
errorState_t DIO_u8GetPinVal(portID_t u8PortIdCopy, pinID_t u8PinIdCopy, uint8 *u8pPinValCopy);

#endif /* MCAL_DIO_INT_H_ */
