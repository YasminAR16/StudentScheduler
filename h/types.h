#ifndef TYPES
#define TYPES

/****************************************************************************
 *
 * This header file contains utility types definitions.
 *
 *
 *     Created by Yasmin Alvarado-Rayo
 ****************************************************************************/
 #include <stdio.h>

/* global var constants */
#define FLAGS_MAX 10
#define MAJORANDMINOR_MAX 10
#define TIMESLOTS_MAX 13
#define LISTOFCOURSES_MAX 5
#define TOTALCOURSES 15


/* string type declaration */
#define MAX_CHAR 100
typedef char string[MAX_CHAR+1];


int totalCourses;           /* size of all courses that will be dumped in an array when scrapped from registrar */

/**************************************************************************************************************/
/* course descriptor type */
typedef struct course{
    /* course fields */
    string department;      /* contains department information, standard 4 characters                           */
    int courseNumber;       /* contains course number                                                           */
    string flags;           /* constains flags that the course meets, if multiple seperated by comma            */
    string instructor;      /* contains instructor name                                                         */
    int fitnessScore;       /* contains score after going through fitness test of an individual course          */
    int time;               /* stores time slot, can only currently be 1-13 (standard class times)              */
}course;
/**************************************************************************************************************/

/**************************************************************************************************************/
/* schedule descriptor type */
typedef struct schedule{
    /* schedule fields */
    course listOfCourses[LISTOFCOURSES_MAX]; /* array of 5 courses                                 */
    int fitnessScore;                        /* score after going through fitness test of schedule */
}schedule;
/**************************************************************************************************************/

/**************************************************************************************************************/
/* user descriptor type */
typedef struct user_{
    /* user fields */
    string flags[FLAGS_MAX];                    /* contains all the desired flags          */
    string majorAndMinor[MAJORANDMINOR_MAX];    /* contains all majors and minors          */
    int timeSlots[TIMESLOTS_MAX];               /* contains all the time slots they prefer */
}user_;
/**************************************************************************************************************/
#endif
