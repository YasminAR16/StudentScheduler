
/*********************************ANNEALING.C*******************************
*
*	This module implements simulated annealing algorithm.
*
*
*      Created by Yasmin
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "h/types.h"
#include "e/course.e"
#include "e/schedule.e"

/* prototypes so it doesn't get mad */
void insertSchedule(schedule, int);
int evaluateCutOffFitnessScore(void);

/* global variables */
/* array of top 5 schedules that each contains 5 courses */
schedule topFive[LISTOFCOURSES_MAX];
 /* fitnessScore that is cutoff */
 int cutOffFitnessScore;
 /* main user created that will be used globally is in user.c */

/**************************************************************************************************************/
int SimAnnealing(){

    printf("Grabbing random schedule... \n");
    //first configuration of a schedule
    schedule currentSchedule = createRandomSchedule();
    printf("Grabbed it. \n");

    //the probabilities and local variables
    double probability;
    double alpha = 0.95;
    double temperature = 10.0;
    double epsilon = 0.000001;
    int delta;

    /* int to keep track of how many times we iterate */
    int iteration = 0;

    /* current cutoff of fitness is 0 */
    cutOffFitnessScore = 0;

    //while the temperature did not reach epsilon
    while(temperature > epsilon){ //5 zeros and 22 zeros

        iteration++; /* add to iteration */

        //cooling process on every iteration
        temperature = temperature * alpha;

        //get the next random permutation of courses
        //the next configuration of courses to be tested
        schedule nextSchedule = createRandomSchedule();

        printf("Grabbed next random schedule \n");

        //compute the diff of fitness of the new permuted configuration //fitness test (hitting 5 criterias)
        delta = nextSchedule.fitnessScore - currentSchedule.fitnessScore;

        //if the new fitnessScore is better accept it and assign it
        if(delta > 0){
            currentSchedule = nextSchedule;
            currentSchedule.fitnessScore = delta + currentSchedule.fitnessScore;
            if(currentSchedule.fitnessScore > cutOffFitnessScore){
                insertSchedule(currentSchedule, currentSchedule.fitnessScore);
                cutOffFitnessScore = evaluateCutOffFitnessScore();
                printf("Cutoff is now ");
                printf("%d", cutOffFitnessScore);
                printf("\n");

             }
        }

        //if the new distance is worse accept it but with a probability level
        else{
            probability = randomNumber(0, 10);

            //if the probability is less than E to the power -delta/temperature.
            //otherwise the old value is kept
            if(probability < (exp(-delta/temperature))){
                currentSchedule = nextSchedule;
                currentSchedule.fitnessScore = delta + currentSchedule.fitnessScore;
            }
        }
    }

    printf("Iterations in sim annealing: ");
    printf("%d", iteration);
    printf("\n");
    return currentSchedule.fitnessScore;

}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* Function to sort an array using insertion sort (in this case sorted by fitnessScore) given a schedule to insert and its fitness score
    Return: 0 if not inserted, return 1 if inserted */
void insertSchedule(schedule currentSchedule, int fitness){

    /* take out the schedule that's the worst in the sorted array and place new schedule there */
    /* last schedule is the worst */
    topFive[4] = currentSchedule;

    /* now sort the list */
    for (int index = 1; index < 5; index++) {
        int keyNum = topFive[index].fitnessScore;
        schedule temp = topFive[index];
      int j = index - 1;

      // Compare key with each element on the left of it until an element bigger than
      // it is found.
        while (keyNum > topFive[j].fitnessScore && j >= 0) {
            topFive[j + 1] = topFive[j];
            j--;
        }
        topFive[j + 1] = temp;
    }
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* evaluated the current cutoffFitnessScore
 Returns the fitnessScore of last element bc it is the worst of the top five */
int evaluateCutOffFitnessScore(){
    int result = topFive[4].fitnessScore;
    return result;
}
/**************************************************************************************************************/

/**************************************************************************************************************/
/* Function to print off the top five schedules and its contents
    Return: none */
void printTopFiveSchedules(){
    /* access schedule by index */
    for(int schedule = 0; schedule < 5; schedule++){
        /* access classes of current schedule by index */
        printf("SCHEDULE: \n");
        for(int class = 0; class < 5; class++){
            printf("%s",((topFive[schedule]).listOfCourses[class]).department);
            printf(" ");
            printf("%d",((topFive[schedule]).listOfCourses[class]).courseNumber);
            printf(" ");
            printf("%s",((topFive[schedule]).listOfCourses[class]).instructor);
            printf(" ");
            printf("%d",((topFive[schedule]).listOfCourses[class]).time);
            printf(" ");
            printf("\n");
        }
        printf("-Fitness Score of ");
        printf("%d",(topFive[schedule]).fitnessScore);
        printf("\n ----------------------\n");
    }
}
/**************************************************************************************************************/
