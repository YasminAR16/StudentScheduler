#ifndef SCHEDULE
#define SCHEDULE

/************************* schedule.e *****************************
*
*  The externals declaration file for the schedule
*    Module.
*
*  Written by Yasmin Alvarado-Rayo
*/

#include "../h/types.h"

/* global variables */
extern int disabledTimeSlots[5];                /* time slots that have been occupied in a schedule     */

/* global functions */
extern schedule createRandomSchedule(void);     /* randomly selects 5 courses and creates a schedule    */
extern int randomNumber(int lower, int upper);  /* generates random number given min and max            */

/***************************************************************/

#endif
