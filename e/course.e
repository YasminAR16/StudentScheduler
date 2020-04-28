#ifndef COURSE
#define COURSE

/************************* course.e *****************************
*
*  The externals declaration file for the course
*    Module.
*
*  Written by Yasmin Alvarado-Rayo
*/

#include "../h/types.h"

/* global variables */
extern course allCourses[TOTALCOURSES];

/* global functions */
extern void initCourse(int index, string courseDept, int courseNum, int courseTime, string courseFlags, string courseInstr);

/***************************************************************/

#endif