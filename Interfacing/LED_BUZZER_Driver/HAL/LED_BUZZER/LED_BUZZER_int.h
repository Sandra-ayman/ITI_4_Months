/*
 * LED_BUZZER_int.h
 *
 *  Created on: Dec 23, 2022
 *      Author: 20109
 */

#ifndef HAL_LED_BUZZER_LED_BUZZER_INT_H_
#define HAL_LED_BUZZER_LED_BUZZER_INT_H_
/*----------New data types----------*/
typedef enum{LED_1,LED_2}led_ID_t;
typedef enum{NEGATIVE,POSITIVE}ledConn_t;

/*
 * Function: led initialization
 * parameters: led id
 * return: error state
 */
errorState_t LEDBUZZER_u8LedInit(led_ID_t led_IdCopy);

/*
 * Function: turn led on
 * parameters: led id
 * return: error state
 */
errorState_t LEDBUZZER_u8TurnLedOn(led_ID_t led_IdCopy);

/*
 * Function: turn led off
 * parameters: led id
 * return: error state
 */
errorState_t LEDBUZZER_u8TurnLedOff(led_ID_t led_IdCopy);

/*
 * Function: toggle the led
 * parameters: led id
 * return: error state
 */
errorState_t LEDBUZZER_u8ToggleLed(led_ID_t led_IdCopy);

#endif /* HAL_LED_BUZZER_LED_BUZZER_INT_H_ */
