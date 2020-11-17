/*
 * file   : main.c contains main application
 * time   : HH-MM
 * date   : DD/MM/YYYY
 * author : Anilkumar.H
 */



#include <stdio.h>
#include "../../inc/types.h"
#include "../../drv/TIMER/inc/timer.h"
#include "../../drv/TIMER/inc/timer_hw.h"

/* +++++++++++++++++++++++++++++++++++++++++++++++
 * user interrupt 509 milli seconds
 * +++++++++++++++++++++++++++++++++++++++++++++++
 */
 #define TIME_INTERVAL_IN_US(509000)
 
/* +++++++++++++++++++++++++++++++++++++++++++++++
 * global variables
 * +++++++++++++++++++++++++++++++++++++++++++++++
 */
 
/* +++++++++++++++++++++++++++++++++++++++++++++++
 * static function declarations
 * +++++++++++++++++++++++++++++++++++++++++++++++
 */
 static void timer_callback(void *callback_param);
 
/* +++++++++++++++++++++++++++++++++++++++++++++++
 * fuction definations
 * +++++++++++++++++++++++++++++++++++++++++++++++
 */

/* +++++++++++++++++++++++++++++++++++++++++++++++
 * callback to be invoked when timer ticks to set value
 * +++++++++++++++++++++++++++++++++++++++++++++++
 */
static void timer_callback(void  *callback_param)
{
    /* print incremented count value */
    printf("timer value =%d\n",timer_get_capture_value());
    
    /* initiate the timer again for periodic event
     * note : assumed that periocic interrupt for timer module is not supported
     */
     timer_start(TIME_INTERVAL_IN_US,(void *)timer_callback);
    
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++
 * application program is written here for demo
 * ++++++++++++++++++++++++++++++++++++++++++++++++
 */
 int main()
 {
     bool_t status;
     /* initialize and start timer */
     status = timer_start(TIME_INTERVAL_IN_US,(void *) timer_callback);
     /*
      * after triggering all the required tasks application goes to low power
      * mode waiting for an event to occur
      */
      while(1)
      {
          
      }
  
     
 }



 
