#ifndef EXERCISEINITIALISER_H
#define EXERCISEINITIALISER_H

#include <QObject>
#include "exerciseholder.h"

class ExerciseInitialiser : public QObject
{
    Q_OBJECT
public:
    explicit ExerciseInitialiser(QObject *parent = nullptr);

signals:
    void sendNewExercise(ExerciseHolder* exercise);
    void doneInitialise();
public slots:
    void initialise();

private:
    void process_line(QByteArray line, vector<ExerciseHolder*> &exVector);
};

#endif // EXERCISEINITIALISER_H
