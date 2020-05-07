
/*********************************SCHEDULE.C*******************************
*
*	This module implements the structure of a schedule.
* A schedule contains an array of courses and the fitness score of the overall schedule.
*
*      Created by Yasmin Alvarado-Rayo
*/


#include <stdio.h>
#include <stdlib.h>
#include "h/types.h"
#include "e/course.e"

/* prototypes so it doesn't get mad */
int timeSlotFits(int);
int scheduleFitnessTest(schedule);
int randomNumber(int, int);
int insertDisabledTimeSlots(int);

/* global variables */
int disabledTimeSlots[5]; /* time slots we can't use in a given schedule */
schedule randomSchedule; /* random schedule */

/**************************************************************************************************************/
/* Description: Initialize a random schedule containing all the elements of the struct.
*  This method will be called to create a random schedule in simulated annealing.
*  Parameters: none
*  Return: a schedule class containing a array of random courses, and its fitnessScore */
schedule createRandomSchedule(){

    /* will loop and gather 5 course for the schedule */
    for(int i = 0; i < 5; i++){

        /* grab random course from our array(allCourses) full of courses */
        course randomCourse = allCourses[randomNumber(0, totalCourses-1)];

        /* get time slot of the current schedule to compare to schedule */
        int currentTimeSlot = randomCourse.time;

        /* check to see if is a fit, if not continue to find one that fits the schedule */
        /* this while loop ensures no repeated courses and no repeated time slots in schedule */
        while(timeSlotFits(currentTimeSlot) == 0){
            randomCourse = allCourses[randomNumber(0, totalCourses-1)];
            currentTimeSlot = randomCourse.time;
        }

        /* assumes we found one, add the current time of the course to disable list of times */
        insertDisabledTimeSlots(currentTimeSlot);

        /* add the random course into our schedule */
        randomSchedule.listOfCourses[i] = randomCourse;
    }

    /* score after going through fitness test of schedule */
    int finalFitness = scheduleFitnessTest(randomSchedule);

    /* set the fitness score of the entire schedule */
    randomSchedule.fitnessScore = finalFitness;

    /* clear the disabled times to be 0 so the array can be used again for another schedule */
    for(int i = 0; i < 5; i++){
        disabledTimeSlots[i] = 0;
    }

    return randomSchedule;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* Description: Checks if the given time slot will work with the other courses in schedule.
*  Parameters: desiredTime (int)
*  Return: 1 if it fits in schedule, 0 if not */
int timeSlotFits(int desiredTime){
    int result = 1;

    /* loop through the 5 times until there is a match or no more to look through */
    for(int i = 0; i < 5; i++){
        /* if it matches, it doesn't fit */
        if(disabledTimeSlots[i] == desiredTime){
            result = 0;
            return result;
        }
    }

    return result;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* Description: inserts given time slot into the diabled list
*  Parameters: currentTimeSlot (int)
*  Return: none */
int insertDisabledTimeSlots(int currentTimeSlot){
    /* loop until there is a 0, meaning it hasn't been set */
    for(int i = 0; i < 5; i++){
        if(disabledTimeSlots[i] == 0){
            disabledTimeSlots[i] = currentTimeSlot;
            return 1;
        }
    }
    return 0;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* function that checks the fitness of a schedule
*   by adding individual course fitness
*   and given user preferences */
int scheduleFitnessTest(schedule scheduleName){
    int result = 0;

    /* adds all fitnessScore of individual courses */
    for(int i = 0; i < 5; i++){
        result = result + (scheduleName.listOfCourses[i]).fitnessScore;
    }

    return result;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* function that generates a random number
*   given lower and upper bound */
int randomNumber(int lower, int upper){
    int number = (rand() % (upper - lower + 1)) + lower;

    return number;
}
/**************************************************************************************************************/
