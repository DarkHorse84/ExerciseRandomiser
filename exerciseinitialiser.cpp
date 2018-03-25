#include "exerciseinitialiser.h"
#include <vector>
#include <cstdlib>
#include <time.h>

using namespace std;

ExerciseInitialiser::ExerciseInitialiser(QObject *parent) : QObject(parent)
{

}

void ExerciseInitialiser::initialise()
{
    /*Pushup, 50, 55
     * Pullup, 10, 15
     * Calf Raise, 50, 65
     * Squat, 35, 40
     * Curl, 10, 15
     * Tricep Extension 30, 35
     * Chin Up, 10, 15
     * Palms in Dumbel Press, 20, 25
     * */
    vector<ExerciseHolder*> vec = {};
    srand (time(NULL));
    for(int i = 1; i <= 5;i++)
    {
        vec.push_back(new ExerciseHolder("Pushup", 50, 55));
        vec.push_back(new ExerciseHolder("Pullup", 10, 15));
        vec.push_back(new ExerciseHolder("Calf Raise", 50, 65));
        vec.push_back(new ExerciseHolder("Squat", 35, 40));
        vec.push_back(new ExerciseHolder("Curl", 10, 15));
        vec.push_back(new ExerciseHolder("Tricep Extension", 30, 35));
        vec.push_back(new ExerciseHolder("Chin Up", 10, 15));
        vec.push_back(new ExerciseHolder("Palms in Dumbel Press", 20, 25));
    }
    while(!vec.empty())
    {
        int index = rand() % (vec.size());
        emit sendNewExercise(vec.at(index));
        vec.erase(vec.begin()+index);
    }
    emit doneInitialise();
}
