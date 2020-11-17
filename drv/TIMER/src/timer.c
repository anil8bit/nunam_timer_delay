/*
 * file   : timer.c contains timer module API definitions
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Anilkumar.H
 */



/* ++++++++++++++++++++++++++++++++++++++++++++++
 * macro definition
 * ++++++++++++++++++++++++++++++++++++++++++++++
 */
 

 #include "../inc/timer.h"
 #include "../../../inc/types.h"
 #include "../inc/timer_hw.h"
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++
  * global variables
  * ++++++++++++++++++++++++++++++++++++++++++++++
  */
  
 /* ++++++++++++++++++++++++++++++++++++++++++++++
  * setup frequency and initialize as timer 
  * ++++++++++++++++++++++++++++++++++++++++++++++
  */
 
 static void timer_initialize()
 {
     static bool_t init = FALSE;
     
     if (init == FALSE)
     {
            /*set prescalar value  fTIMER = 16 MHZ / (2^PRESCALAR) = 16/2^4 = 1MHZ , 1 tick is equal to 1 micro second */
            WRITE_REG32(TIMER_0, PRESCALAR , 0X4);
     
            /* select timer or counter mode
            only timer mode is used in this application*/
            WRITE_REG32(TIMER_0, MODE, TIMER_MODE_TIMER);
     
            /* initialize valid bit width for capture/compare registers*/
            WRITE_REG32(TIMER_0, BITMODE, TIMER_32_BIT_WIDTH);
            
            /* making the init variable value TRUE so that initialization doesn't happen every time the timer_start is invoked */
            init = TRUE;
     
     
     }
     
     
 }
 
 
 /* +++++++++++++++++++++++++++++++++++++++++++++++++++
  * initialize and start the timer
  * +++++++++++++++++++++++++++++++++++++++++++++++++++
  */
 uint32_t timer_start(uint32_t time_in_us, void *callback)
 {
     uint32_t new_compare_val = 0;
     uint32_t current_capture_val = 0;
     
     /* initialize timer hardware */
     timer_initialize();

     /* assuming that the timer interrupt will be enabled and call back is placed in the interrupt vector table by "INTR_enable" */
     // INTR_enable(TIMER_INTERRUPT, TIMER_INTR_PRIORITY, callback);
     WRITE_REG32(TIMER_0, INTENSET, TIMER_INTENSET_CC0);
     
     /* capture timer counter value */
      current_capture_val = timer_get_capture_value();
     
     /* check for overflow condition */
     if((TIMER_MAX - current_capture_val)< time_in_us)
     {
            new_compare_val = (time_in_us - (TIMER_MAX - current_capture_val));
         
     }
     else
     {
            new_compare_val = (current_capture_val + time_in_us);
     }
     
     /* set compare value */
     WRITE_REG32(TIMER_0, CC_0, new_compare_val);
     
     /* set compare event for EVENTS_COMPARE[0] */
     WRITE_REG32(TIMER_0, EVENTS_COMPARE_0, TRUE);
     
     /* start timer */
     WRITE_REG32(TIMER_0, TASKS_START, TRUE);
     
     return set_new_compare_val;
 }
 
 /* ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  * reading present value of timer counter
  * ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  */
  uint32_t timer_get_capture_value()
  {
      WRITE_REG32(TIMER_0, TASKS_CAPTURE_0, TRUE);
      READ_REG32(TIMER_0, CC_0);
  }
  
/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 * stop the timer and reset counter 
 * +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 */
 
 
 void timer_stop()
 {
     /* select timer counter registers to be stopped,
	 * Note: as we are considering only CC[0] and ignoring other all registers are selected
	 */
	WRITE_REG32(TIMER_0, SHORTS, TIMER_TASK_STOP);

	/* Stop timer */
	WRITE_REG32(TIMER_0, TASKS_STOP, TRUE);

	/* select timer counter registers to be cleared */
	WRITE_REG32(TIMER_0, SHORTS, TIMER_TASK_CLEAR);

	/* clear timer counter */
	WRITE_REG32(TIMER_0, TASKS_CLEAR, TRUE);

	/* clear all the interrupts */
	WRITE_REG32(TIMER_0, INTENCLR, TIMER_DISABLE_INTP);



 }