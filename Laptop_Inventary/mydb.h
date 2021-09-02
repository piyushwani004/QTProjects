#ifndef MYDB_H
#define MYDB_H
#include <QDebug>

#include <QSqlDatabase>
#include <QFile>
#include <QDebug>
#include <QSqlError>


class MyDB
{
private:
    MyDB();
    static MyDB *instance;
    void init();
    QSqlDatabase db;
public:
    static MyDB* getInstance();
    static void ResetInstance();
    void addLaptop();
    void findLaptop();
    void getReport();
    void updateLaptop();
    int getAvailableCount();
    int getInUseCount();
    int getOutOfOrderCount();
    QSqlDatabase getDBInstance();

    ~MyDB();
};

#endif // MYDB_H
