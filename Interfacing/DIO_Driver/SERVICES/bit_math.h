
#ifndef   _BIT_MATH_H_
#define	  _BIT_MATH_H_


#define SET_BIT(Reg, BIT_NO) Reg |= (1<<BIT_NO)
#define CLR_BIT(Reg, BIT_NO) Reg &= ~(1<<BIT_NO)
#define TOGGLE_BIT(Reg, BIT_NO) Reg ^= (1<<BIT_NO)
#define GET_BIT(Reg, BIT_NO) ((Reg >>BIT_NO) & 1)


#endif
