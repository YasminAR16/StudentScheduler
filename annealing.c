/*********************************ANNEALING.C*******************************
*
*	This module implements simulated annealing algorithm.
*
*
*      Created by Yasmin
*/

/* should I have a class for a course with vars: dept, #, time, flag, credits, etc. */

/* global list with all course filtered using matching? */
ArrayList list = new ArrayList();

void SimAnnealing(){

    //first configuration of a schedule
    courseClass [] currentCourses = {course1, course2, course3, course4, course5};

    //the next configuration of courses to be tested
    courseClass [] nextCourses = new courseClass[5];

    //the probabilities and local variables
    double probability;
    double alpha = ;
    double temperature = ;
    double epsilon = ;
    double delta;

    /* fuction that checks how well it fits all 5 criterias */
    double fitness = fitnessTest(currentCourses);

    //while the temperature did not reach epsilon
    while(temperature > epsilon){

        //get the next random permutation of courses
        computeNextCourses(currentCourses,nextCourses);

        //compute the fitness of the new permuted configuration //fitness test (hitting 5 criterias)
        delta = fitnessTest(nextCourses)-fitness;

        //if the new distance is better accept it and assign it
        if(delta < 0){
            currentCourses = nextCourses;
            fitness = delta + fitness;
        }

        //if the new distance is worse accept it but with a probability level
        else{
            probability = rnd.Next();

            //if the probability is less than E to the power -delta/temperature.
            //otherwise the old value is kept
            if(probability < (Math.Exp(-delta/temperature))){
                currentCourses = nextCourses;
                fitness = delta + fitness;
            }
        }

        //cooling process on every iteration
        temperature = temperature * alpha;

    }

    return "best schedule is" + distance;

}

void computeNextCourses(courseClass [] currentCourses, courseClass [] nextCourses){
  /* function to select next courses to group together */
}

double fitnessTest(courseClass [] currentCourses){
  /* function to compute how "fit" the schedule is:
  *   pass all five criterias?, etc.
  */
}
