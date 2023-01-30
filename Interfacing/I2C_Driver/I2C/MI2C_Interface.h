/*
 * I2C_Interface.h
 *
 *  Created on: Jan 28, 2023
 *      Author: 20109
 */

#ifndef MCAL_I2C_MI2C_INTERFACE_H_
#define MCAL_I2C_MI2C_INTERFACE_H_

#define BITRATE(TWPS)	((F_CPU/SCL_CLK)-16)/(2*pow(4,TWPS))
/*
 * Function: Initialization of Master
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidInitMaster(void);
/*
 * Function: Initialization of Slave
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidInitSlave(void);
/*
 * Function: Start condition
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidStart(void);
/*
 * Function: Repeated Start condition
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidRepeatedStart(void);
/*
 * Function: Send slave address with write request
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidSendSlaveAddressWithWriteRequest(void);
/*
 * Function: Send slave address with read request
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidSendSlaveAddressWithReadRequest(void);
/*
 * Function: Master write a byte
 * Parameter: byte that needs to be written
 * Return: Nothing
 */
void MI2C_VoidWriteByte(uint8 Copy_u8Byte);
/*
 * Function: Master read a byte
 * Parameter: Nothing
 * Return: Received the date byte
 */
uint8 MI2C_U8ReadByte(void);
/*
 * Function: Stop condition
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidStop(void);
/*
 * Function: Slave check the slave address with write request
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidSlaveCheckSlaveAddressReceivedWithWriteRequest(void);
/*
 * Function: Slave check the slave address with read request
 * Parameter: Nothing
 * Return: Nothing
 */
void MI2C_VoidSlaveCheckSlaveAddressReceivedWithReadRequest(void);
/*
 * Function: Slave read a byte
 * Parameter: Nothing
 * Return: Received the date byte
 */
uint8 MI2C_U8SlaveReadByte(void);
/*
 * Function: Slave write a byte
 * Parameter: byte that needs to be written
 * Return: Nothing
 */
void MI2C_VoidSlaveWriteByte(uint8 Copy_u8Byte);

#endif /* MCAL_I2C_MI2C_INTERFACE_H_ */
