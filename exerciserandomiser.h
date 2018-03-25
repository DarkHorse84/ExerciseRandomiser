#ifndef EXERCISERANDOMISER_H
#define EXERCISERANDOMISER_H

#include <QMainWindow>
#include "exerciseholder.h"

namespace Ui {
class ExerciseRandomiser;
}

class ExerciseRandomiser : public QMainWindow
{
    Q_OBJECT

public:
    explicit ExerciseRandomiser(QWidget *parent = 0);
    ~ExerciseRandomiser();

private:
    Ui::ExerciseRandomiser *ui;
    int index=0;
    int labellingIndex=0;
    vector<ExerciseHolder*> exercises;

signals:
    void initialise();
    void rightKey();
    void leftKey();

public slots:
    void doneInitialising();
    void receiveExercise(ExerciseHolder* exercise);
    void next();
    void previous();

};

#endif // EXERCISERANDOMISER_H
