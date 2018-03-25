#include "exerciserandomiser.h"
#include "ui_exerciserandomiser.h"
#include "exerciseinitialiser.h"
#include <iostream>
#include <QShortcut>

using namespace std;

ExerciseRandomiser::ExerciseRandomiser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExerciseRandomiser)
{
    ui->setupUi(this);
    ExerciseInitialiser* initer = new ExerciseInitialiser();
    ui->tableExerciseList->setRowCount(40);
    ui->tableExerciseList->setColumnCount(3);

    ui->taqbleCurrentExercise->setRowCount(1);
    ui->taqbleCurrentExercise->setColumnCount(3);
    QStringList header;
    header<<"#"<<"Reps"<<"Exercise";
    ui->tableExerciseList->setHorizontalHeaderLabels(header);
    ui->taqbleCurrentExercise->setHorizontalHeaderLabels(header);

    ui->tableExerciseList->horizontalHeader()->setStretchLastSection(true);
    ui->taqbleCurrentExercise->horizontalHeader()->setStretchLastSection(true);

    connect(this, SIGNAL(initialise()), initer, SLOT(initialise()));
    connect(initer, SIGNAL(sendNewExercise(ExerciseHolder*)), this, SLOT(receiveExercise(ExerciseHolder*)));
    connect(ui->pushNext, SIGNAL(pressed()), this, SLOT(next()));
    connect(initer, SIGNAL(doneInitialise()), this, SLOT(doneInitialising()));
    QShortcut * shortcut_next = new QShortcut(QKeySequence(Qt::Key_Right), this, SLOT(next()));
    emit(initialise());
}

ExerciseRandomiser::~ExerciseRandomiser()
{
    delete ui;
}


void ExerciseRandomiser::doneInitialising()
{
    ExerciseHolder* exercise = exercises.at(0);
    cout<<"Exercise #:"<<index<<" ExerciseName:"<<exercise->getName()<<" Reps:"<<exercise->getReps()<<endl;
    ui->taqbleCurrentExercise->setItem(0, 0, new QTableWidgetItem(QString::number(index+1)));
    ui->taqbleCurrentExercise->setItem(0, 1, new QTableWidgetItem(QString::number(exercise->getReps())));
    ui->taqbleCurrentExercise->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(exercise->getName())));
    index=1;
    ui->tableExerciseList->selectRow(0);
}

void ExerciseRandomiser::receiveExercise(ExerciseHolder* exercise)
{
    exercises.push_back(exercise);
    cout<<"Exercise #:"<<labellingIndex<<" ExerciseName:"<<exercise->getName()<<" Reps:"<<exercise->getReps()<<endl;
    ui->tableExerciseList->setItem(labellingIndex, 0, new QTableWidgetItem(QString::number(labellingIndex+1)));
    ui->tableExerciseList->setItem(labellingIndex, 1, new QTableWidgetItem(QString::number(exercise->getReps())));
    ui->tableExerciseList->setItem(labellingIndex, 2, new QTableWidgetItem(QString::fromStdString(exercise->getName())));
    labellingIndex++;
}

void ExerciseRandomiser::next()
{
    if(index <= 39){
        ExerciseHolder* exercise = exercises.at(index);
        cout<<"Exercise #:"<<index<<" ExerciseName:"<<exercise->getName()<<" Reps:"<<exercise->getReps()<<endl;
        ui->taqbleCurrentExercise->setItem(0, 0, new QTableWidgetItem(QString::number(index+1)));
        ui->taqbleCurrentExercise->setItem(0, 1, new QTableWidgetItem(QString::number(exercise->getReps())));
        ui->taqbleCurrentExercise->setItem(0, 2, new QTableWidgetItem(QString::fromStdString(exercise->getName())));
        ui->tableExerciseList->selectRow(index);
        index++;
    }
}

void ExerciseRandomiser::previous()
{

}
