#include "tasklist.h"


TaskList::TaskList()
{
    QFile file("organaizer.txt");
    if (file.open(QFile::ReadOnly))
    {
//        QTextStream stream(&file);
//        taskString = stream.readAll();
//        file.close();
    }
}

void TaskList::writeTask(QString str)
{
    QFile file("organaizer.txt");
    taskString += str;

    if (file.open(QFile::Append))
    {
        QTextStream stream(&file);
        stream << "\n" << taskString;
        taskString.clear();
        file.close();
    }
}

QString TaskList::getTaskString()
{
    return taskString;
}

QString TaskList::getTasksQuantity()
{
    int x = 0;
    int count = 0;
    QFile file("organaizer.txt");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        tasks = stream.readAll();
        file.close();
    }
    while(x != -1)
    {
        x = tasks.indexOf("\n", x+1);
        if(x != -1)
        {
            count++;
        }
    }
    return QString::number(count);
}
