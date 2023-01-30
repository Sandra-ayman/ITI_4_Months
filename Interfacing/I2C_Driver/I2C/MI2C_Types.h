/*
 * MI2C_Types.h
 *
 *  Created on: Jan 29, 2023
 *      Author: 20109
 */

#ifndef MCAL_I2C_MI2C_TYPES_H_
#define MCAL_I2C_MI2C_TYPES_H_

enum Prescaller_Value{ZERO,ONE,TWO,THREE};
/*----------Status Code for Master and Slave----------*/
#define START_ACK                    0x08 /* start has been sent*/
#define REP_START_ACK                0x10 /* repeated start*/
#define SLAVE_ADD_AND_WR_ACK         0x18 /* Master transmit ( slave address + Write request ) ACK*/
#define SLAVE_ADD_AND_WR_NACK        0x20 /* Master transmit ( slave address + Write request ) NACK*/
#define SLAVE_ADD_AND_RD_ACK         0x40 /* Master transmit ( slave address + Read request ) ACK*/
#define SLAVE_ADD_AND_RD_NACK        0x48 /* Master transmit ( slave address + Read request ) NACK*/
#define WR_BYTE_ACK                  0x28 /* Master transmit data ACK*/
#define WR_BYTE_NACK                 0x30 /* Master transmit data NACK*/
#define SLAVE_ADD_AND_AR             0x38 /*Arbitration lost */
#define RD_BYTE_WITH_ACK             0x50 /* Master received data with ACK*/
#define RD_BYTE_WITH_NACK            0x58 /* Master received data with NACK*/
#define SLAVE_ADD_RCVD_RD_REQ        0xA8 /* means that slave address is received with write req*/
#define SLAVE_ADD_RCVD_RD_AR         0xB0 /*Arbitration lost in (slave address + R/W) and SLA+R has received*/
#define SLAVE_ADD_RCVD_WR_REQ        0x60 /* means that slave address is received with read req*/
#define SLAVE_ADD_RCVD_WR_AR         0X68 /*Arbitration lost in (slave address + R/W) and SLA+W has received*/
#define SLAVE_DATA_RECEIVED_ACK      0x80 /* means that read byte req is received with ACK*/
#define SLAVE_DATA_RECEIVED_NACK     0x88 /* means that read byte req is received with NACK*/
#define SLAVE_BYTE_TRANSMITTED_ACK   0xB8 /* means that write byte req is received with ACK*/
#define SLAVE_BYTE_TRANSMITTED_NACK  0xC0 /* means that write byte req is received with NACK*/
#define LAST_SLAVE_BYTE_TRANSMITTED  0xC8 /*Last slave data byte has been transmitter*/
#define GENERAL_CALL                 0X70 /*General Call address received*/
#define GENERAL_CALL_AR              0x78 /*Arbitration lost in (slave address + R/W) and General Call has been received*/
#define PREVIOUS_ADD_RD_ACK          0X90 /*Previous Address Read request with ACK*/
#define PREVIOUS_ADD_RD_NACK         0X98 /*Previous Address Read request with NACK*/
#define STOP_ACK                     0xA0 /* Stop has been sent*/

/*----------Mask TWSR----------*/
#define TWSR_MSK 0xF8

#endif /* MCAL_I2C_MI2C_TYPES_H_ */
