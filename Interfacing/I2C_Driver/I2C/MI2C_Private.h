/*
 * I2C_Private.h
 *
 *  Created on: Jan 28, 2023
 *      Author: 20109
 */

#ifndef MCAL_I2C_MI2C_PRIVATE_H_
#define MCAL_I2C_MI2C_PRIVATE_H_

#define ENABLE  1
#define DISABLE 0
/*----------I2C Registers----------*/
#define TWDR *((volatile uint8*)0x23)
#define TWAR *((volatile uint8*)0x22)
#define TWSR *((volatile uint8*)0x21)
#define TWBR *((volatile uint8*)0x20)
#define TWCR *((volatile uint8*)0x56)

/*----------TWCR Pins----------*/
#define TWIE  0
#define TWEN  2
#define TWSTO 4
#define TWSTA 5
#define TWEA  6
#define TWINT 7

/*----------TWSR Pins----------*/
#define TWPS0  0
#define TWPS1  1

/*----------TWAR Pins----------*/
#define TWGCE 0
/*----------TWDR Pins----------*/
#define TWD0  0

#endif /* MCAL_I2C_MI2C_PRIVATE_H_ */
