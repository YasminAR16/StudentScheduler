
/*********************************SIMANNEALTEST.C*******************************
 *
 *	Test program for the modules of
 *   course.c, annealing.c, user.c, schedule.c and including types.h
 *
 *
 *
 *      Created by Yasmin Alvarado-Rayo
 */

#include <math.h>
#include <stdio.h>
#include "h/types.h"
#include "e/course.e"
#include "e/schedule.e"
#include "e/annealing.e"
#include "e/user.e"


int main() {

    /**************************************************************************************************************/

    /* create a user with preferences */
    printf("assigning user flags...\n");
    string userFlags[FLAGS_MAX] = {"ERS", "Diversity"};

    printf("assigning user major and minor...\n");
    string userMajorAndMinors[MAJORANDMINOR_MAX] = {"Computer Science", "Mathematics"};

    printf("assigning user preferred time slots... \n");
    int userTimeSlots[TIMESLOTS_MAX] = {1, 2, 3, 4, 5, 6};

    printf("initiating user... \n");
	initUser(userFlags, userMajorAndMinors, userTimeSlots);


    /* create courses */
    printf("assigning total amount of courses...\n");
    /* state total # of courses to use for array */
    /* MAKE SURE TOTALCOURSES constant in types.h matches the following assigned number */
    totalCourses = 15;

    printf("initiating courses...\n");
    initCourse(1, "CSCI", 180, 1, "Computer Science", "Gary Lewandowski");
    initCourse(2, "MAKE", 102, 2, "", "Amy Gardner");
    initCourse(3, "CJUS", 101, 5, "Diversity", "Ronald Springman");
    initCourse(4, "SOCI", 269, 12, "ERS", "Weissbuch");
    initCourse(5, "CSCI", 390, 8, "Computer Science", "Liz  Johnson");
    initCourse(6, "DIFT", 210, 13, "Music, Creative Perspective", "White");
    initCourse(7, "PSYC", 499, 7, "Psychology", "Ashley Fox");
    initCourse(8, "SOCW", 101, 4, "Social Work", "Karen O'Hara");
    initCourse(9, "MUSC", 101, 10, "ERS, Music", "Lindsey Boxx");
    initCourse(10, "MATH", 316, 11, "Mathematics", "Dena Morton");
    initCourse(11, "CSCI", 170, 6, "Computer Science", "Liz  Johnson");
    initCourse(12, "MATH", 225, 3, "Mathematics", "Mikey G");
    initCourse(13, "SOCI", 101, 10, "ERS", "Morgan");
    initCourse(14, "MAKE", 101, 1, "", "Amy Gardner");
    initCourse(15, "CORE", 499, 9, "", "Lisa Ottum");
    printf("created courses \n");

    printf("Starting Simulated Annealing... \n");
    /* simulated annealing on courses above */
    SimAnnealing();
    printf("Simulated Annealing Processed \n");

    printTopFiveSchedules();

    /**************************************************************************************************************/

    return 1;
}
