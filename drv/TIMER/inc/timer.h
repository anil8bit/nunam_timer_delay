/*
 * file   : timer.h  contains timer module API declarations
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Anilkumar.H
 */

/* ++++++++++++++++++++++++++++++++++++++++++
 * macro definitions
 * ++++++++++++++++++++++++++++++++++++++++++
 */

#include "../../../inc/types.h"

#ifndef TIMER_INC_TIMER_H
#define TIMER_INC_TIMER_H

#define TIMER_TASK_CLEAR	(0X0000003F)
#define TIMER_TASK_STOP		(0X00003F00)
#define TIMER_DISABLE_INTP	(0X003F0000)

#define TIMER_INTENSET_CC0	(0X00010000)
#define TIMER_INTENSET_CC1	(0X00020000)
#define TIMER_INTENSET_CC2	(0X00040000)
#define TIMER_INTENSET_CC3	(0X00080000)
#define TIMER_INTENSET_CC4	(0X00100000)
#define TIMER_INTENSET_CC5 	(0X00200000)

#define TIMER_MAX		(0XFFFFFFFF)

/* +++++++++++++++++++++++++++++++++++++++++++
 * enum definitions
 * +++++++++++++++++++++++++++++++++++++++++++
 */

typedef enum timer_mode
{
	TIMER_MODE_TIMER = 0, TIMER_MODE_COUNTER = 1, TIMER_MODE_LOW_POWER_COUNTER = 2

}timer_mode_t;


typedef enum timer_bitmode
{

	TIMER_16_BIT_WIDTH = 0, TIMER_8_BIT_WIDTH = 1, TIMER_24_BIT_WIDTH =2, TIMER_32_BIT_WIDTH =3
}timer_bitmode_t;

/* ++++++++++++++++++++++++++++++++++++++++++++++
 * API declarations
 * ++++++++++++++++++++++++++++++++++++++++++++++
 */


/* ++++++++++++++++++++++++++++++++++++++++++++++
 * @param : takes micro second and callback function address as input
 * @func  : starts timer and enables compare event to generate interrupt
 * @ret   : returns present counter value
 * ++++++++++++++++++++++++++++++++++++++++++++++
 */
uint32_t timer_start(uint32_t time_in_us, void *callback);

/* ++++++++++++++++++++++++++++++++++++++++++++++
 * @param : void
 * @func  : stops and clears timer counter
 * @ret   : void
 * ++++++++++++++++++++++++++++++++++++++++++++++
 */
void timer_stop();

/* ++++++++++++++++++++++++++++++++++++++++++++++
 * @param : void
 * @func  : returns current compare/capture value
 * @ret   : returns current compare/captuer value
 * ++++++++++++++++++++++++++++++++++++++++++++++
 */
uint32_t timer_get_capture_value();

#endif  /* TIMER_INC_TIMER_H */

























