
/*********************************COURSE.C*******************************
*
*	This module implements the structure of a course.
*
*
*      Created by Yasmin Alvarado-Rayo
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include "h/types.h"
#include "e/user.e"

/* global variables */
course allCourses[TOTALCOURSES]; /* array containing all courses filtered by web scraping */

/* prototypes so it doesn't get mad */
int courseFitnessTest(course);
void initCourse(int, string, int, int, string, string);

/**************************************************************************************************************/
/* Description: Initialize the the course list to contain all the elements of the struct.
* This method will be only called once during initialization of object and added to arrayList allCourses.
* Parameters: courseDept, courseNum, courseTime, courseFlags, courseInstr, courseFitScore
* Return: none */
void initCourse(int index, string courseDept, int courseNum, int courseTime, string courseFlags, string courseInstr){
    course var_course;
    strcpy(var_course.department, courseDept);
    var_course.courseNumber = courseNum;
    var_course.time = courseTime;
    strcpy(var_course.flags, courseFlags); /* contains reg flags, minor, and major flags */
    strcpy(var_course.instructor, courseInstr);

    /* before we add to list, do fitnesScore of each course */
    /* evaluate course */
    var_course.fitnessScore = courseFitnessTest(var_course);

    /* add created course to the list of courses(all course) */
    /* after evaluated fitness score, add to global list of courses */
    allCourses[index-1] = var_course;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* function that checks the fitness of an individual course by checking flags, time, and given preferences
 Returns: total fitness of the course */
int courseFitnessTest(course courseName){

    int totalFitness = 0;

    /* 1- checks major and minor brownie points */
    for(int i = 0; i < sizeof(mainUser.majorAndMinor); i++){
        char *result = strstr(mainUser.majorAndMinor[i], courseName.flags);

        if (result != NULL){ /* desired flag of major or minor is found */
            totalFitness = totalFitness + 10;
        }
    }

    /* 2- check desired reg flag brownie points */
    for(int i = 0; i < sizeof(mainUser.flags);i++){
        char *result = strstr(mainUser.flags[i], courseName.flags);

        if (result != NULL){ /* desired reg flag is found */
            totalFitness = totalFitness + 7;
        }
    }

    /* 3- check desired timeSlots brownie points */
    for(int i = 0; i < sizeof(mainUser.timeSlots);i++){

        /* if desired time slot is found */
        if (mainUser.timeSlots[i] == courseName.time){
            totalFitness = totalFitness + 5;
        }
    }

    return totalFitness;
}
/**************************************************************************************************************/
