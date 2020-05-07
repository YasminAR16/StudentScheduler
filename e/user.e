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
extern user_ mainUser; /* user that will contain a users preferences */

/* global functions */
/* initiates the user with given preferences */
extern void initUser(string givenFlags[], string givenMajorAndMinor[], int givenTimeSlots[]);

/***************************************************************/

#endif
