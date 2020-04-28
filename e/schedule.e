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
extern int disabledTimeSlots[5];

/* global functions */
extern schedule createRandomSchedule(void);
extern int randomNumber(int lower, int upper);

/***************************************************************/

#endif
