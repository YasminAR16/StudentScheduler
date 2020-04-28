
/*********************************SCHEDULE.C*******************************
*
*	This module implements the structure of a schedule.
* A schedule contains an array of courses and the fitness score of the overall schedule.
*
*      Created by Yasmin
*/


#include <stdio.h>
#include <stdlib.h>
#include "h/types.h"
#include "e/course.e"

/* prototypes so it doesn't get mad */
int timeSlotFits(int);
int scheduleFitnessTest(schedule);
int randomNumber(int, int);
void insertDisabledTimeSlots(int);

/* time slots we can't use in a given schedule */
int disabledTimeSlots[5];
schedule randomSchedule; /* random schedule */

/**************************************************************************************************************/
/* Description: Initialize a random schedule containing all the elements of the struct.
*  This method will be only called once during initialization of simulated annealing.
*  Parameters: none
*  Return: a schedule class containing a array of random courses, and its fitnessScore */
schedule createRandomSchedule(){

    /*printf("random schedule is being made \n");*/

    for(int i = 0; i < 5; i++){
        /*printf("grabbing a course \n");*/
        course randomCourse = allCourses[randomNumber(0, totalCourses-1)];

        /* get time slot of the current schedule to compare to schedule */
        int currentTimeSlot = randomCourse.time;

        /* check to see if is a fit, if not continue to find one that fits the schedule */
        while(timeSlotFits(currentTimeSlot) == 0){
            randomCourse = allCourses[randomNumber(0, totalCourses-1)];
            currentTimeSlot = randomCourse.time;
        }

//        printf("Current Time Slot is ");
//        printf("%d" ,currentTimeSlot);
//        printf("\n");

        /* assumes we found one, add the current time of the course to disable list of times */
        insertDisabledTimeSlots(currentTimeSlot);

        /* printf("Added a random course into schedule \n"); */
        randomSchedule.listOfCourses[i] = randomCourse;
    }

    printf("all five courses have been added \n");

    for(int i = 0; i < 5; i++){
        printf("%d", randomSchedule.listOfCourses[i].fitnessScore);
        printf(" + ");

    }

    int finalFitness = scheduleFitnessTest(randomSchedule); /* score after going through fitness test of schedule */

    randomSchedule.fitnessScore = finalFitness;

    printf("Fitness is ");
    printf("%d" ,randomSchedule.fitnessScore);
    printf("\n");

    /* clear the disabled times to be 0 */
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
    for(int i = 0; i < 5; i++){
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
void insertDisabledTimeSlots(int currentTimeSlot){
    for(int i = 0; i < 5; i++){
        if(&disabledTimeSlots[i] == NULL){
            disabledTimeSlots[i] = currentTimeSlot;
        }
    }
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

/* function that generates a random number
*   given lower and upper bound */
int randomNumber(int lower, int upper){
    int number = (rand() % (upper - lower + 1)) + lower;

    return number;
}
/**************************************************************************************************************/
