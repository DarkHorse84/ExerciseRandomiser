#ifndef EXERCISEHOLDER_H
#define EXERCISEHOLDER_H

#include <string>

using namespace std;

class ExerciseHolder
{
public:
    ExerciseHolder(ExerciseHolder* source);
    ExerciseHolder(string name, int min, int max);
    string getName();
    int getReps();


private:
    string name;
    int max;
    int min;
    int reps = -1;

};

#endif // EXERCISEHOLDER_H
