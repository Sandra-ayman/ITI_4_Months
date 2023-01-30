/*
 * I2C_Config.h
 *
 *  Created on: Jan 28, 2023
 *      Author: 20109
 */

#ifndef MCAL_I2C_MI2C_CONFIG_H_
#define MCAL_I2C_MI2C_CONFIG_H_

#define F_CPU 8000000UL
#define SCL_CLK 400000UL

#define MASTER_SLAVE_ADDRESS       0X06
#define SLAVE_ADDRESS              0X05
#define ACK_STATUS                 ENABLE
#define PRESCALAR_ONE              ENABLE
#define PRESCALAR_FOUR             DISABLE
#define PRESCALAR_SIXTEEN          DISABLE
#define PRESCALAR_SIXTYFOUR        DISABLE
#define GENERAL_CALL_ADDRESS       DISABLE


#endif /* MCAL_I2C_MI2C_CONFIG_H_ */
