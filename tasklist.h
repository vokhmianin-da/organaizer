#ifndef TASKLIST_H
#define TASKLIST_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>

class TaskList: public QObject
{
    Q_OBJECT
    //Q_PROPERTY(QString taskString WRITE writeTask READ getTaskString)
    Q_PROPERTY(QString quantityTasks READ getTasksQuantity)
    Q_PROPERTY(QString taskName WRITE writeTaskName READ getTaskName)   //запись/чтение названия задачи
    Q_PROPERTY(QString taskDateEnd WRITE writeTaskDateEnd READ gettaskDateEnd)    //запись/чтение даты окончания
    Q_PROPERTY(QString taskProgress WRITE writeProgress READ getTaskProgress)   //запись/чтение прогресса
//    Q_PROPERTY(int result READ getResult NOTIFY resultValueChanged)
public:
    TaskList();
//    Q_INVOKABLE int factorial(const int& n);

//    int getInput() const;
//    void setInput(int value);
//    int getResult() const;
//    void writeTask(QString str);
//    QString getTaskString();

    void writeTaskName(QString str);
    QString getTaskName();

    void writeTaskDateEnd(QString str);
    QString gettaskDateEnd();

    void writeProgress(QString str);
    QString getTaskProgress();

    Q_INVOKABLE QString getTasksQuantity();
    Q_INVOKABLE void writeStringToBD(); //запись задачи в БД

//signals:
//    void inputValueChanged(int);
//    void resultValueChanged(int);

private:

    //QString taskString;
    QString taskName;
    QString taskDateEnd;
    QString taskProgress;
    QString tasks;
    QString quantityTasks;
    QSqlDatabase db;
    bool createConnection();
};

#endif // TASKLIST_H
