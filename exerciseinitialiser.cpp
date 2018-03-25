#include "exerciseinitialiser.h"
#include <vector>
#include <cstdlib>
#include <iostream>
#include <time.h>
#include <QFile>

using namespace std;

ExerciseInitialiser::ExerciseInitialiser(QObject *parent) : QObject(parent)
{

}

void ExerciseInitialiser::initialise()
{
    vector<ExerciseHolder*> vec = {};
    srand (time(NULL));
    //Read data from file format is <Name>,<min>,<Max>
    QFile file("C:/ExerciseRandomiser/config.cfg");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;
    cout<<"file.atEnd():"<<file.atEnd()<<endl;
    while (!file.atEnd()) {
            QByteArray line = file.readLine();
            process_line(line, vec);
        }



    while(!vec.empty())
    {
        int index = rand() % (vec.size());
        emit sendNewExercise(vec.at(index));
        vec.erase(vec.begin()+index);
    }
    emit doneInitialise();
}

void ExerciseInitialiser::process_line(QByteArray line, vector<ExerciseHolder*>& exVector)
{
    QString tmpString(line);
    cout<<"Processing "<<tmpString.toStdString()<<endl;
    QStringList pieces = tmpString.split(",");
    QString name = pieces[0];
    int min = pieces[1].toInt();
    int max = pieces[2].toInt();
    for(int i = 0; i < 5; i++)
    {
        exVector.push_back(new ExerciseHolder(name.toStdString(), min, max));
    }
}
