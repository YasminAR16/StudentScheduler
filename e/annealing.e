#ifndef ANNEALING
#define ANNEALING

/************************* annealing.e *****************************
*
*  The externals declaration file for the course
*    Module.
*
*  Written by Yasmin Alvarado-Rayo
*/

#include "../h/types.h"

/* global variables */
extern schedule topFive[LISTOFCOURSES_MAX];
extern  int cutOffFitnessScore;

/* global functions */
extern int SimAnnealing(void);
extern void printTopFiveSchedules(void);

/***************************************************************/

#endif
