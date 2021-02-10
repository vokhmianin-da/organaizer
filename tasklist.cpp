#include "tasklist.h"
#include <QDebug>


TaskList::TaskList()
{
    if(!createConnection()) return;
    QSqlQuery query;
    QString strQuery = "CREATE TABLE tasks ("
                       "id INTEGER PRIMARY KEY NOT NULL,"
            "'Название задачи' TEXT,"
            "'Дата начала' TEXT,"
            "'Прогресс' TEXT);";
    if(!query.exec(strQuery))
    {
        qDebug() << "Таблица уже создана";
    }
    table = new QTableView;
    model = new QSqlQueryModel;
    model->setQuery("SELECT * FROM tasks;");
    table->setModel(model);
    table->resize(400, 500);
}

void TaskList::writeTaskName(QString str)
{
    taskName = str;
}

QString TaskList::getTaskName()
{
    return taskName;
}

void TaskList::writeTaskDateEnd(QString str)
{
    taskDateEnd = str;
}

QString TaskList::gettaskDateEnd()
{
    return taskDateEnd;
}

void TaskList::writeProgress(QString str)
{
    taskProgress = str;
}

QString TaskList::getTaskProgress()
{
    return taskProgress;
}

QString TaskList::getTasksQuantity()
{
    int count = 0;
    QSqlQuery query1;
    query1.exec("SELECT COUNT(*) FROM tasks");
    query1.next();
    count = query1.value(0).toInt();
    return QString::number(count);
}

void TaskList::writeStringToBD()
{
    QSqlQuery query;
    QString strQuery;

    QString strF = "INSERT INTO tasks ('Название задачи', 'Дата начала', 'Прогресс')"
                   "VALUES('%1', '%2', '%3');";
    strQuery = strF.arg(taskName).arg(taskDateEnd).arg(taskProgress);
    if (!query.exec(strQuery)){
            qDebug() << "Не удалось вставить запись";
        }

}

void TaskList::showTable()
{
    model->setQuery("SELECT * FROM tasks;");
    table->show();
}

bool TaskList::createConnection()
{
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("tasksList.db");
    if(!db.open())
    {
        qDebug() << "НЕ удалось открыть БД";
        return false;
    }
    return true;
}
