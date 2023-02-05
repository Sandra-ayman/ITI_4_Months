/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 1-2-2023
 * Description: MRCC_Program.c -> Function Implementation
 * Module Features:
                  1- MRCC_voidInitClock(void)
                  2- MRCC_voidEnablePeripheralClock()
                  3- MRCC_voidDisablePeripheralClock()
                  4- MRCC_voidEnableSecuritySystem()
                  5- MRCC_voidDisableSecuritySystem()
 */
/*---------- Standard Types LIB----------*/
#include "LSTD_TYPES.h"
#include "LIB_MATH.h"

/*---------- Peripheral files----------*/
#include "MRCC_Private.h"
#include "MRCC_Interface.h"
#include "MRCC_Config.h"

/*---------- Function Implementation----------*/
void MRCC_voidInitClock(void)
{
	/*---------- HSI----------*/
#if MRCC_CLKSRC == HSI
	/* Step1: EN HSI*/
	SET_BIT(MRCC_CR,MRCC_HSION);
	/* Step2: wait until HSI Ready*/
	while(GET_BIT(MRCC_CR,MRCC_HSIRDY)==0);
	/* Step3: Switch to HSI*/
	CLR_BIT(MRCC_CFGR,MRCC_SW0);
	CLR_BIT(MRCC_CFGR,MRCC_SW1);
#elif MRCC_CLKSRC == HSE
	/* Step1: EN HSE*/
	SET_BIT(MRCC_CR,MRCC_HSEON);
	/* Step2: wait until HSE Ready*/
	while(GET_BIT(MRCC_CR,MRCC_HSERDY)==0);
	/*---------- HSE RC Source----------*/
#if MRCC_HSESRC == HSE_RC
	 /* Step3: EN bypass*/
	 SET_BIT(MRCC_CR,MRCC_HSEBYP);
	 /* Step4: Switch to HSE*/
	 SET_BIT(MRCC_CFGR,MRCC_SW0);
	 CLR_BIT(MRCC_CFGR,MRCC_SW1);
	/*---------- HSE CRYSTAL Source----------*/
#elif MRCC_HSESRC == HSE_CRYSTAL
	 /* Step3: Disable bypass*/
	 CLR_BIT(MRCC_CR,MRCC_HSEBYP);
	/* Step4: Switch to HSE*/
	 SET_BIT(MRCC_CFGR,MRCC_SW0);
	 CLR_BIT(MRCC_CFGR,MRCC_SW1);
#else
#warning "Invalid Option......"
#endif

#elif MRCC_CLKSRC == PLL
#if MRCC_PLLSRC == PLL_HSE
	/* Step1: EN HSE*/
	 SET_BIT(MRCC_CR,MRCC_HSEON);
	/* Step2: wait until HSE Ready*/
	 while(GET_BIT(MRCC_CR,MRCC_HSERDY)==0);
	/* Step3: EN PLL*/
	 SET_BIT(MRCC_CR,MRCC_PLLON);
	/* Step4: wait until PLL Ready*/
	 while(GET_BIT(MRCC_CR,MRCC_PLLRDY)==0);
	/* Step5: Switch to PLL*/
	 CLR_BIT(MRCC_CFGR,MRCC_SW0);
	 SET_BIT(MRCC_CFGR,MRCC_SW1);
#elif MRCC_PLLSRC == PLL_HSI
	 /* Step1: EN HSI*/
	 SET_BIT(MRCC_CR,MRCC_HSION);
	/* Step2: wait until HSI Ready*/
	 while(GET_BIT(MRCC_CR,MRCC_HSIRDY)==0);
	/* Step3: EN PLL*/
	 SET_BIT(MRCC_CR,MRCC_PLLON);
	/* Step4: wait until PLL Ready*/
	 while(GET_BIT(MRCC_CR,MRCC_PLLRDY)==0);
	/* Step5: Switch to PLL*/
	 CLR_BIT(MRCC_CFGR,MRCC_SW0);
	 SET_BIT(MRCC_CFGR,MRCC_SW1);
#else
#warning "Invalid Option......"
#endif

#else
#warning "Invalid Option......"
#endif
}
void MRCC_voidEnablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8PeripheralNumber )
{
	switch(Copy_uddtBusName)
	{
	case MRCC_AHB1: SET_BIT(MRCC_AHB1ENR,Copy_u8PeripheralNumber);break;
	case MRCC_AHB2: SET_BIT(MRCC_AHB2ENR,Copy_u8PeripheralNumber);break;
	case MRCC_APB1: SET_BIT(MRCC_APB1ENR,Copy_u8PeripheralNumber);break;
	case MRCC_APB2: SET_BIT(MRCC_APB2ENR,Copy_u8PeripheralNumber);break;
	default:/*Do Nothing*/break;
	}
}
void MRCC_voidDisablePeripheralClock(BusName_t Copy_uddtBusName, u8 Copy_u8PeripheralNumber )
{
	switch(Copy_uddtBusName)
		{
		case MRCC_AHB1: CLR_BIT(MRCC_AHB1ENR,Copy_u8PeripheralNumber);break;
		case MRCC_AHB2: CLR_BIT(MRCC_AHB2ENR,Copy_u8PeripheralNumber);break;
		case MRCC_APB1: CLR_BIT(MRCC_APB1ENR,Copy_u8PeripheralNumber);break;
		case MRCC_APB2: CLR_BIT(MRCC_APB2ENR,Copy_u8PeripheralNumber);break;
		default:/*Do Nothing*/break;
		}
}
void MRCC_voidEnableSecuritySystem(void)
{
	SET_BIT(MRCC_CR,MRCC_CSSON);
}
void MRCC_voidDisableSecuritySystem(void)
{
	CLR_BIT(MRCC_CR,MRCC_CSSON);
}
