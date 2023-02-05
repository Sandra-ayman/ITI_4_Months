/*
 * Author: Sandra Ayman
 * Version: V0.0.0
 * Date: 25-1-2023
 * Description: MRCC_Private.h
 */

#ifndef MRCC_PRIVATE_H_
#define MRCC_PRIVATE_H_
/*-Developer can't edit in it*/
/*-Register Definition*/
/*-Design: 1- #define: YES
 *         2- Struct: NO
 *         3- union: NO*/

/*----------BASE ADDRESS----------*/
#define MRCC_BASE_ADDRESS     0x40023800

/*----------Register Addresses----------*/
#define MRCC_CR                   *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x00 )) )
#define MRCC_PLLCFGR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x04 )) )
#define MRCC_CFGR                 *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x08 )) )
#define MRCC_CIR                  *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x0C )) )

#define MRCC_AHB1RSTR             *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x10 )) )
#define MRCC_AHB2RSTR             *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x14 )) )

#define MRCC_APB1RSTR             *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x20 )) )
#define MRCC_APB2RSTR             *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x24 )) )

#define MRCC_AHB1ENR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x30 )) )
#define MRCC_AHB2ENR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x34 )) )

#define MRCC_APB1ENR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x40 )) )
#define MRCC_APB2ENR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x44 )) )

#define MRCC_AHB1LPENR            *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x50 )) )
#define MRCC_AHB2LPENR            *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x54 )) )

#define MRCC_APB1LPENR            *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x60 )) )
#define MRCC_APB2LPENR            *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x64 )) )

#define MRCC_BDCR                 *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x70 )) )
#define MRCC_CSR                  *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x74 )) )

#define MRCC_SSCGR                *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x80 )) )
#define MRCC_PLLI2SCFGR           *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x84 )) )

#define MRCC_DCKCFGR              *( (( volatile u32* )( MRCC_BASE_ADDRESS + 0x8C )) )

/*----------MRCC_CR Pins----------*/
#define MRCC_HSION     0U
#define MRCC_HSIRDY    1U
#define MRCC_HSEON     16U
#define MRCC_HSERDY    17U
#define MRCC_HSEBYP    18U
#define MRCC_CSSON     19U
#define MRCC_PLLON     24U
#define MRCC_PLLRDY    25U
#define MRCC_PLLI2SON  26U
#define MRCC_PLLI2SRDY 27U

/*----------MRCC_CFGR Pins----------*/
#define MRCC_SW0 0U
#define MRCC_SW1 1U
#endif /* MRCC_PRIVATE_H_ */
