/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 1-2-2023
 * Description: MRCC_Interface.h -> Function prototypes
 * Module Features:
                  1- MRCC_voidInitClock(void)
                  2- MRCC_voidEnablePeripheralClock()
                  3- MRCC_voidDisablePeripheralClock()
                  4- MRCC_voidEnableSecuritySystem()
                  5- MRCC_voidDisableSecuritySystem()
 */
/* What i sell to customer
 *        - The Architect give the API
 *        - The name of Function
 *        - What is the input
 *        - What is the output
 *        - Macros
 */
#ifndef MRCC_INTERFACE_H_
#define MRCC_INTERFACE_H_

/*---------- AHB1 Prescaler----------*/
typedef enum
{
	MRCC_AHP_PRE1 = 7,
	MRCC_AHP_PRE2,
	MRCC_AHP_PRE4,
	MRCC_AHP_PRE8,
	MRCC_AHP_PRE16,
	MRCC_AHP_PRE32,
	MRCC_AHP_PRE64,
	MRCC_AHP_PRE128,
	MRCC_AHP_PRE256,
	MRCC_AHP_PRE512
}AHB1_Prescaler_t;

/*---------- APB1 Prescaler----------*/
typedef enum
{
	MRCC_APB1_PRE1 = 3,
	MRCC_APB1_PRE2,
	MRCC_APB1_PRE4,
	MRCC_APB1_PRE8,
	MRCC_APB1_PRE16
}APB1_Prescaler_t;
/*---------- APB2 Prescaler----------*/
typedef enum
{
	MRCC_APB2_PRE1 = 3,
	MRCC_APB2_PRE2,
	MRCC_APB2_PRE4,
	MRCC_APB2_PRE8,
	MRCC_APB2_PRE16
}APB2_Prescaler_t;
/*---------- Bus name----------*/
typedef enum
{
	MRCC_AHB1,
	MRCC_AHB2,
	MRCC_APB1,
	MRCC_APB2
}BusName_t;

/*---------- CLKSRC Name----------*/
#define HSI 0U
#define HSE 1U
#define PLL 2U

/*---------- HSESRC Name----------*/
#define HSE_RC      0U
#define HSE_CRYSTAL 1U

/*---------- HSESRC Name----------*/
#define PLL_HSE 0U
#define PLL_HSI 1U

/*---------- Macros: RCC AHB1 Peripheral clock Enable Register----------*/
#define MRCC_GPIOA_EN 0U
#define MRCC_GPIOB_EN 1U
#define MRCC_GPIOC_EN 2U
#define MRCC_GPIOD_EN 3U
#define MRCC_GPIOE_EN 4U
#define MRCC_GPIOH_EN 7U
#define MRCC_CRC_EN   12U
#define MRCC_DMA1_EN  21U
#define MRCC_DMA2_EN  22U

/*---------- Macros: RCC AHB2 Peripheral clock Enable Register----------*/
#define MRCC_OTGFS_EN 7U

/*---------- Macros: RCC APB1 Peripheral clock Enable Register----------*/
#define MRCC_TIM2_EN   0U
#define MRCC_TIM3_EN   1U
#define MRCC_TIM4_EN   2U
#define MRCC_TIM5_EN   3U
#define MRCC_WWDG_EN   11U
#define MRCC_SPI2_EN   14U
#define MRCC_SPI3_EN   15U
#define MRCC_USART2_EN 17U
#define MRCC_I2C1_EN   21U
#define MRCC_I2C2_EN   22U
#define MRCC_I2C3_EN   23U
#define MRCC_PWR_EN    28U

/*---------- Macros: RCC APB2 Peripheral clock Enable Register----------*/
#define MRCC_TIM1_EN   0U
#define MRCC_USART1_EN 4U
#define MRCC_USART6_EN 5U
#define MRCC_ADC1_EN   8U
#define MRCC_SDIO_EN   11U
#define MRCC_SPI1_EN   12U
#define MRCC_SPI4_EN   13U
#define MRCC_SYSCFG_EN 14U
#define MRCC_TIM9_EN   16U
#define MRCC_TIM10_EN  17U
#define MRCC_TIM11_EN  18U


/*---------- Functions Prototypes----------*/
/*---------- 1- MRCC_voidInitClock()----------*/
/* @func: Clock Initialization
 * @in: Void
 * @out: void
 */
void MRCC_voidInitClock(void);
/*---------- 2- MRCC_voidEnablePeripheralClock----------*/
/* @func: Enable Peripheral Clock
 * @in[1]: Copy_uddtBusName
 *                         - MRCC_AHB1
 *                         - MRCC_AHB2
 *                         - MRCC_APB1
 *                         - MRCC_APB2
 * @in[2]: Copy_u8PeripheralNumber: The order of peripheral on selected Reg
 * @out: void
 */
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8PeripheralNumber );
/*---------- 3- MRCC_voidDisablePeripheralClock----------*/
/* @func: Disable Peripheral Clock
 * @in[1]: Copy_uddtBusName
 *                         - MRCC_AHB1
 *                         - MRCC_AHB2
 *                         - MRCC_APB1
 *                         - MRCC_APB2
 * @in[2]: Copy_u8PeripheralNumber: The order of peripheral on selected Reg
 * @out: void
 */
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8PeripheralNumber );
/*---------- 4- MRCC_voidInitClock()----------*/
/* @func: Enable Security System
 * @in: Void
 * @out: void
 */
void MRCC_voidEnableSecuritySystem(void);
/*---------- 5- MRCC_voidInitClock()----------*/
/* @func: Disable Security System
 * @in: Void
 * @out: void
 */
void MRCC_voidDisableSecuritySystem(void);
#endif /* MRCC_INTERFACE_H_ */
