/*
 * I2C_Program.c
 *
 *  Created on: Jan 28, 2023
 *      Author: 20109
 */
#include "../../SERVICES/stdtypes.h"
#include "../../SERVICES/bit_math.h"
#include <math.h>
#include "MI2C_Private.h"
#include "MI2C_Types.h"
#include "MI2C_Config.h"
#include "MI2C_Interface.h"
/*----------MI2C_VoidInitMaster Implementation----------*/
void MI2C_VoidInitMaster(void)
{
#if PRESCALAR_ONE == ENABLE
	TWBR = BITRATE(ZERO);
	CLR_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
#elif PRESCALAR_FOUR == ENABLE
	TWBR = BITRATE(ONE);
	SET_BIT(TWSR,TWPS0);
	CLR_BIT(TWSR,TWPS1);
#elif PRESCALAR_SIXTEEN == ENABLE
	TWBR = BITRATE(TWO);
	CLR_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
#elif PRESCALAR_SIXTYFOUR == ENABLE
	TWBR = BITRATE(THREE);
	SET_BIT(TWSR,TWPS0);
	SET_BIT(TWSR,TWPS1);
#endif
	SET_BIT(TWCR,TWEN);
	TWAR =(1<<1)&(MASTER_SLAVE_ADDRESS);
	return;
}
/*----------MI2C_VoidInitSlave Implementation----------*/
void MI2C_VoidInitSlave(void)
{
	SET_BIT(TWCR,TWEN);
	TWAR =(1<<1)&(SLAVE_ADDRESS);
	return;
}
/*----------MI2C_VoidStart Implementation----------*/
void MI2C_VoidStart(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	while(GET_BIT(TWCR,TWINT)==0);
	while((TWSR & TWSR_MSK)!=START_ACK);
	return;
}
/*----------MI2C_VoidRepeatedStart Implementation----------*/
void MI2C_VoidRepeatedStart(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTA);
	while(GET_BIT(TWCR,TWINT)==0);
	while((TWSR & TWSR_MSK)!=REP_START_ACK);
	return;
}
/*----------MI2C_VoidSendSlaveAddressWithWriteRequest Implementation----------*/
void MI2C_VoidSendSlaveAddressWithWriteRequest(void)
{
	TWDR = (SLAVE_ADDRESS << 1);
	CLR_BIT(TWDR,TWD0);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
	while((TWSR & TWSR_MSK)!=SLAVE_ADD_AND_WR_ACK);
#else
	while((TWSR & TWSR_MSK)!=SLAVE_ADD_AND_WR_NACK);
#endif
	return;
}
/*----------MI2C_VoidSendSlaveAddressWithReadRequest Implementation----------*/
void MI2C_VoidSendSlaveAddressWithReadRequest(void)
{
	TWDR = (SLAVE_ADDRESS << 1);
	SET_BIT(TWDR,TWD0);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
	while((TWSR & TWSR_MSK)!=SLAVE_ADD_AND_RD_ACK);
#else
	while((TWSR & TWSR_MSK)!=SLAVE_ADD_AND_RD_NACK);
#endif
	return;
}
/*----------MI2C_VoidWriteByte Implementation----------*/
void MI2C_VoidWriteByte(uint8 Copy_u8Byte)
{
	TWDR = Copy_u8Byte;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
	while((TWSR & TWSR_MSK)!=WR_BYTE_ACK );
#else
	while((TWSR & TWSR_MSK)!=WR_BYTE_NACK);
#endif
	return;
}
/*----------MI2C_U8ReadByte Implementation----------*/
uint8 MI2C_U8ReadByte(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
	while((TWSR & TWSR_MSK)!=RD_BYTE_WITH_ACK );
#else
	while((TWSR & TWSR_MSK)!=RD_BYTE_WITH_NACK);
#endif
	return TWDR;
}
/*----------MI2C_VoidStop Implementation----------*/
void MI2C_VoidStop(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWSTO);
	while(GET_BIT(TWCR,TWINT)==0);
	while((TWSR & TWSR_MSK)!=STOP_ACK);
	return;
}
/*----------MI2C_VoidSlaveCheckSlaveAddressReceivedWithWriteRequest Implementation----------*/
void MI2C_VoidSlaveCheckSlaveAddressReceivedWithWriteRequest(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
	CLR_BIT(TWCR,TWSTO);
	CLR_BIT(TWCR,TWSTA);
	while(GET_BIT(TWCR,TWINT)==0);
#if GENERAL_CALL_ADDRESS == ENABLE
	while(((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_WR_REQ) || ((TWSR & TWSR_MSK)!=GENERAL_CALL) || ((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_WR_AR));
#else
	while(((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_WR_REQ) || ((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_WR_AR));
#endif
	return;
}
/*----------MI2C_VoidSlaveCheckSlaveAddressReceivedWithReadRequest Implementation----------*/
void MI2C_VoidSlaveCheckSlaveAddressReceivedWithReadRequest(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
	CLR_BIT(TWCR,TWSTO);
	CLR_BIT(TWCR,TWSTA);
	while(GET_BIT(TWCR,TWINT)==0);
#if GENERAL_CALL_ADDRESS == ENABLE
	while(((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_RD_REQ) || ((TWSR & TWSR_MSK)!=GENERAL_CALL) || ((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_RD_AR));
#else
	while(((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_RD_REQ) || ((TWSR & TWSR_MSK)!=SLAVE_ADD_RCVD_RD_AR));
#endif
	return;
}
/*----------MI2C_U8SlaveReadByte Implementation----------*/
uint8 MI2C_U8SlaveReadByte(void)
{
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	SET_BIT(TWCR,TWEA);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
#if GENERAL_CALL_ADDRESS ==ENABLE
	while(((TWSR & TWSR_MSK)!=SLAVE_DATA_RECEIVED_ACK) || ((TWSR & TWSR_MSK)!=PREVIOUS_ADD_RD_ACK));
#else
	while(((TWSR & TWSR_MSK)!=SLAVE_DATA_RECEIVED_ACK) || ((TWSR & TWSR_MSK)!=PREVIOUS_ADD_RD_NACK));
#endif
#else
#if GENERAL_CALL_ADDRESS ==ENABLE
	while(((TWSR & TWSR_MSK)!=SLAVE_DATA_RECEIVED_NACK) || ((TWSR & TWSR_MSK)!=PREVIOUS_ADD_RD_ACK));
#else
	while(((TWSR & TWSR_MSK)!=SLAVE_DATA_RECEIVED_NACK) || ((TWSR & TWSR_MSK)!=PREVIOUS_ADD_RD_NACK));
#endif
#endif
	return TWDR;
}
/*----------MI2C_U8SlaveReadByte Implementation----------*/
void MI2C_VoidSlaveWriteByte(uint8 Copy_u8Byte)
{
	TWDR = Copy_u8Byte;
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
	while(GET_BIT(TWCR,TWINT)==0);
#if ACK_STATUS == ENABLE
	while(((TWSR & TWSR_MSK)!=SLAVE_BYTE_TRANSMITTED_ACK) ||((TWSR & TWSR_MSK)!=LAST_SLAVE_BYTE_TRANSMITTED) );
#else
	while((TWSR & TWSR_MSK)!=SLAVE_BYTE_TRANSMITTED_NACK);
#endif
	return;
}
