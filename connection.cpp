#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnection(){
    db = QSqlDatabase::addDatabase("QODBC");
    bool test = false;
    db.setDatabaseName("project");
    db.setUserName("achraf");
    db.setPassword("esprit18");
    if (db.open()) test=true;
    return test;
}
void Connection::closeConnection(){
    db.close();
}
