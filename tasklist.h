#ifndef TASKLIST_H
#define TASKLIST_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QTableView>
#include <QWidget>

class TaskList: public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString quantityTasks READ getTasksQuantity)
    Q_PROPERTY(QString taskName WRITE writeTaskName READ getTaskName)   //запись/чтение названия задачи
    Q_PROPERTY(QString taskDateEnd WRITE writeTaskDateEnd READ gettaskDateEnd)    //запись/чтение даты окончания
    Q_PROPERTY(QString taskProgress WRITE writeProgress READ getTaskProgress)   //запись/чтение прогресса
public:
    TaskList();

    void writeTaskName(QString str);
    QString getTaskName();

    void writeTaskDateEnd(QString str);
    QString gettaskDateEnd();

    void writeProgress(QString str);
    QString getTaskProgress();

    Q_INVOKABLE QString getTasksQuantity();
    Q_INVOKABLE void writeStringToBD(); //запись задачи в БД
    Q_INVOKABLE void showTable();   //показать таблицу

private:

    QString taskName;
    QString taskDateEnd;
    QString taskProgress;
    QString tasks;
    QString quantityTasks;
    QSqlDatabase db;
    QTableView* table;
    QSqlQueryModel* model;
    bool createConnection();
};

#endif // TASKLIST_H
