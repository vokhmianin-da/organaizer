#ifndef TASKLIST_H
#define TASKLIST_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>

class TaskList: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString taskString WRITE writeTask READ getTaskString)
    Q_PROPERTY(QString quantityTasks READ getTasksQuantity)
//    Q_PROPERTY(int result READ getResult NOTIFY resultValueChanged)
public:
    TaskList();
//    Q_INVOKABLE int factorial(const int& n);

//    int getInput() const;
//    void setInput(int value);
//    int getResult() const;
    void writeTask(QString str);
    QString getTaskString();
    Q_INVOKABLE QString getTasksQuantity();

//signals:
//    void inputValueChanged(int);
//    void resultValueChanged(int);

private:
//    int input;
//    int result;
    QString taskString;
    QString tasks;
    QString quantityTasks;
};

#endif // TASKLIST_H
