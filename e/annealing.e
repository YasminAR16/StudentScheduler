#ifndef ANNEALING
#define ANNEALING

/************************* annealing.e *****************************
*
*  The externals declaration file for the annealing
*    Module.
*
*  Written by Yasmin Alvarado-Rayo
*/

#include "../h/types.h"

/* global variables */
extern schedule topFive[LISTOFCOURSES_MAX]; /* array of size five for top 5 schedules                           */
extern  int cutOffFitnessScore;             /* int containing the min fitness score of the top five schedules   */

/* global functions */
extern int SimAnnealing(void);              /* method for simulated annealing algorithm                         */
extern void printTopFiveSchedules(void);    /* printing info of the top five schedules                          */

/***************************************************************/

#endif
