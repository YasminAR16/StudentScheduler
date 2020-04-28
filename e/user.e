#ifndef USER
#define USER

/************************* user.e *****************************
*
*  The externals declaration file for the user
*    Module.
*
*  Written by Yasmin Alvarado-Rayo
*/

#include "../h/types.h"

/* global variables */
extern user_ mainUser;

/* global functions */
extern void initUser(string givenFlags[], string givenMajorAndMinor[], int givenTimeSlots[]);

/***************************************************************/

#endif
