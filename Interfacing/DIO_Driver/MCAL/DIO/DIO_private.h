/*
 * DIO_private.h
 *
 *  Created on: Dec 22, 2022
 *      Author: 20109
 */

#ifndef MCAL_DIO_PRIVATE_H_
#define MCAL_DIO_PRIVATE_H_
/*----------Macros----------*/
#define PORT_A_Dir_REG  ((volatile uint8*)0x3A)
#define PORT_B_Dir_REG  ((volatile uint8*)0x37)
#define PORT_C_Dir_REG  ((volatile uint8*)0x34)
#define PORT_D_Dir_REG  ((volatile uint8*)0x31)
#define PORT_A_Out_REG  ((volatile uint8*)0x3B)
#define PORT_B_Out_REG  ((volatile uint8*)0x38)
#define PORT_C_Out_REG  ((volatile uint8*)0x35)
#define PORT_D_Out_REG  ((volatile uint8*)0x32)
#define PORT_A_In_REG   ((volatile uint8*)0x39)
#define PORT_B_In_REG   ((volatile uint8*)0x36)
#define PORT_C_In_REG   ((volatile uint8*)0x33)
#define PORT_D_In_REG   ((volatile uint8*)0x30)


#endif /* MCAL_DIO_PRIVATE_H_ */
