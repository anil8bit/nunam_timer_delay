/*
 * file   : timer_hw_h contains timer module hardware register details
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Anilkumar.H
 */



#ifndef TIMER_INC_HW_H
#define TIMER_INC_HW_H


#define TIMER_0  (0X40008000)
#define TIMER_1  (0X40009000)
#define TIMER_2  (0X4000A000)



#define TASKS_START  		(0X000) 		/* start timer */
#define TASKS_STOP		(0X004)			/* stop timer */
#define TASKS_COUNT		(0X008)			/* increment timer(counter)*/
#define TASKS_CLEAR 		(0X00C)			/* clear timer */
#define TASKS_SHUTDOWN		(0X010)			/* shut down timer */
#define TASKS_CAPTURE_0		(0X040)			/* capture timer value to cc[0] register*/
#define TASKS_CAPTURE_1		(0X044) 		/* capture timer value to cc[1] register*/
#define TASKS_CAPTURE_2		(0X048)			/* capture timer value to cc[2] register*/
#define TASKS_CAPTURE_3		(0X04C)			/* capture timer value to cc[3] register*/
#define TASKS_CAPTURE_4		(0X050)			/* capture timer value to cc[4] register*/
#define TASKS_CAPTURE_5		(0X054)			/* capture timer value to cc[5] register*/
#define EVENTS_COMPARE_0	(0X140)			/* compare event on cc[0] match */
#define EVENTS_COMPARE_1	(0X144)			/* compare event on cc[1] match */
#define EVENTS_COMPARE_2	(0X148)			/* compare event on cc[2] match */
#define EVENTS_COMPARE_3	(0X14C)			/* compare event on cc[3] match */
#define EVENTS_COMPARE_4	(0X150)			/* compare event on cc[4] match */
#define EVENTS_COMPARE_5	(0X154)			/* compare event on cc[5] match */
#define SHORTS			(0X200)			/* short cut register */
#define INTENSET		(0X304)  		/* enable interrupt */
#define INTENCLR		(0X308)			/* disable interrupt */
#define MODE			(0X504)			/* timer mode selection */
#define BITMODE 		(0X508)			/* configure the number of bits used by the TIMER*/
#define PRESCALAR		(0X510)			/* Timer prescalar register*/
#define CC_0			(0X540)			/* Capture/compare register 0 */
#define CC_1 			(0X544)			/* Capture/compare register 1 */
#define CC_0			(0X548)			/* Capture/compare register 2 */
#define CC_0			(0X54C)			/* Capture/compare register 3 */
#define CC_0			(0X550)			/* Capture/compare register 4 */
#define CC_0			(0X554)			/* Capture/compare register 5 */



#define WRITE_REG32(BASE_ADDR,OFFSET,VAL)\
		( *((volatile unsigned int *)(BASE_ADDR + OFFSET) )==VAL)

#define READ_REG32(BASE_ADDR,OFFSET)\
		(uint32_t)(*( (volatile unsigned int *)(BASE_ADDR + OFFSET) ) )

#endif /* TIMER_INC_HW_H */