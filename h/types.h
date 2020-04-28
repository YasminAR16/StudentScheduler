#ifndef TYPES
#define TYPES

/****************************************************************************
 *
 * This header file contains utility types definitions.
 *
 *#define RAND_MAX TOTALCOURSES
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


int totalCourses; /* size of all courses that will be dumped in an array when scrapped from registrar */

/**************************************************************************************************************/
/* course descriptor type */
typedef struct course{
    /* course fields */
    string department; /* 4 chars? */
    int courseNumber;
    string flags; /* could have multiple flags, maybe make list? */
    string instructor; /* could have multiple instructors? should make a list? */
    int fitnessScore; /* score after going through fitness test of individual course */

    int time; /* might use bitmap for a time slot */
    /* broken into the 13 day standard scheduling blocked represented by #s 1-13 */
}course;
/**************************************************************************************************************/

/**************************************************************************************************************/
/* schedule descriptor type */
typedef struct schedule{
    /* schedule fields */
    course listOfCourses[LISTOFCOURSES_MAX];/* array of 5 courses */
    int fitnessScore; /* score after going through fitness test of schedule */
}schedule;
/**************************************************************************************************************/

/**************************************************************************************************************/
/* user descriptor type */
typedef struct user_{
    /* user fields */
    string flags[FLAGS_MAX]; /* contains all the desired flags */
    string majorAndMinor[MAJORANDMINOR_MAX]; /* contains all majors and minors */
    int timeSlots[TIMESLOTS_MAX]; /* contains all the time slots they prefer */
}user_;
/**************************************************************************************************************/
#endif
