#include "tasklist.h"

taskList::taskList()
{
    QFile file(":/new/text/organaizer.txt");
    if (file.open(QFile::ReadOnly))
    {
        QTextStream stream(&file);
        taskString = stream.readAll();
        file.close();
    }
}
