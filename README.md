# StudentScheduler
Students find it incredibly frustrating to register for classes at Xavier University. They must independently find courses and create multiple schedules. My project focuses on creating a system that combines DegreeWorks and Xavier’s registration system to provide five mock-up schedules for students using the simulated annealing algorithm. It relies on the given criteria from the following five categories: classes taken, current academic courses offered, major/core requirements, student’s interests, and student’s desired times to have classes. This will aid students to have options before them that fit their needs when the time comes to register for classes.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

What things you need to install the software:

Be able to build C code. I am currently using X-Code to build and run program.

### Installing

A step by step series of examples that tells you how to get a development env running

Clone repo on desired file:
```
$ git clone https://github.com/YasminAR16/StudentScheduler.git
```

## Iteration Function Tests

The current test file created a user with preferences (major, minor, flags, and time slot preferences). After, it takes in 15 courses with their attributes (course number, department, flags, instructor, and time slot). Using the simulated annealing algorithm, it produces the top five schedules that user can use for registration that avoid duplicate courses and courses within the same time slot per schedule. It prints the course details per schedule.

## Built With

* C

## Authors

* **Yasmin Alvarado-Rayo** - *Initial work* - [YasminAR16](https://github.com/YasminAR16)


See also the list of [contributors](https://github.com/YasminAR16/StudentScheduler/contributors) who participated in this project.
