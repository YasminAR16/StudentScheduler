/*********************************USER.C*******************************
*
*	This module implements the structure of a user and their preference.
*
*
*      Created by Yasmin Alvarado-Rayo
*/

#include <stdio.h>
#include <string.h>
#include "h/types.h"

/* prototypes so it doesn't get mad */
void initUser(string[], string[], int[]);



/* global user variable */
user_ mainUser;

/**************************************************************************************************************/
/* function that sets the mainUser's preferences given their preferences
 Parameters: givenFlags (user preferred flags), givenMajorAndMinor (user's major and minor), givenTimeSlots (user's preferred time slots)
 Return: none */
void initUser(string givenFlags[10], string givenMajorAndMinor[10], int givenTimeSlots[13]){
    /* assigns flags, major, and minor */
    for(int i = 0; i < FLAGS_MAX; i++){
        strcpy(mainUser.flags[i], givenFlags[i]);
        strcpy(mainUser.majorAndMinor[i], givenMajorAndMinor[i]);
    }

    /* assigns time slots */
    for(int j = 0; j < TIMESLOTS_MAX; j++){
        mainUser.timeSlots[j] = givenTimeSlots[j];
    }
}
/**************************************************************************************************************/
