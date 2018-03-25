#include "exerciseholder.h"
#include <cstdlib>
#include <time.h>

ExerciseHolder::ExerciseHolder(string name, int min, int max)
{

    this->name = name;
    this->min = min;
    this->max = max;
}

ExerciseHolder::ExerciseHolder(ExerciseHolder* source)
{
    source->name = name;
    source->min = min;
    source->max = max;
}

string ExerciseHolder::getName()
{
    return name;
}

int ExerciseHolder::getReps()
{


    if(reps == -1)
    {
        reps = rand() % (max - min + 1) + min;
    }
    return reps;
}

