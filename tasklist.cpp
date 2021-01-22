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
