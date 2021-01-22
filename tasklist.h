#ifndef TASKLIST_H
#define TASKLIST_H

#include <QObject>
#include <QString>
#include <QFile>
#include <QTextStream>

class taskList: public QObject
{
    Q_OBJECT
//    Q_PROPERTY(int input WRITE setInput READ getInput NOTIFY inputValueChanged)
//    Q_PROPERTY(int result READ getResult NOTIFY resultValueChanged)
public:
    taskList();
//    Q_INVOKABLE int factorial(const int& n);

//    int getInput() const;
//    void setInput(int value);
//    int getResult() const;

//signals:
//    void inputValueChanged(int);
//    void resultValueChanged(int);

private:
    int input;
    int result;
    QString taskString;
};

#endif // TASKLIST_H
