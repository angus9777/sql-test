#include "SqlTest.h"
#include "Group.h"
#include "User.h"

#include <QDebug>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>
#include <QList>
#include <QtWidgets>


bool SqlTest::createConnection() {
    QSqlDatabase sqlDatabase = QSqlDatabase::addDatabase("QSQLITE");

    sqlDatabase.setDatabaseName("../sql-test/test.db");

    if (!sqlDatabase.open()) {
        qDebug() << "Cannot open database:" << sqlDatabase.lastError();
        return false;
    }

    return true;
}


void SqlTest::addTestTables(bool createMode) {
    QSqlDatabase database = QSqlDatabase::database();
    QSqlQuery query(database);

    QStringList sqlDropTables = QStringList()
            << "DROP TABLE IF EXISTS user"
            << "DROP TABLE IF EXISTS user_group";

    QStringList sqlCreateTables = QStringList()
            << "CREATE TABLE IF NOT EXISTS user ("
               "id Integer PRIMARY KEY AUTOINCREMENT, "
               "email Varchar(64) NOT NULL UNIQUE, "
               "age Integer, "
               "group_id Integer"
               ")"

            << "CREATE TABLE IF NOT EXISTS user_group ("
               "id Integer PRIMARY KEY AUTOINCREMENT, "
               "name Varchar(64) NOT NULL UNIQUE"
               ")";

    if (createMode) {
        foreach (QString sql, sqlDropTables) {
            if (!query.exec(sql)) {
                qDebug() << query.lastQuery();
                qDebug() << query.lastError();
            }
        }
    }

    if (createMode) {
        foreach (QString sql, sqlCreateTables) {
            if (!query.exec(sql)) {
                qDebug() << query.lastQuery();
                qDebug() << query.lastError();
            }
        }
    }
}


void SqlTest::insertTestData() {
    QSqlDatabase database = QSqlDatabase::database();
    QSqlQuery query(database);

    QList<Group> groups;

    groups.append(Group(-1, "Peppers"));
    groups.append(Group(-1, "Butterflies"));
    groups.append(Group(-1, "Socks"));

    QList<User> users;

    users.append(User(-1, "Hank", 34, 1));
    users.append(User(-1, "Boris", 23, 1));
    users.append(User(-1, "Jane", 32, 1));
    users.append(User(-1, "Nick", 12, 2));
    users.append(User(-1, "Lasley", 52, 2));
    users.append(User(-1, "Zoe", 16, 2));
    users.append(User(-1, "John", 45, 3));
    users.append(User(-1, "Sara", 72, 3));
    users.append(User(-1, "Laura", 19, 3));

    QString sqlGroupStmt = "INSERT INTO user_group (name) VALUES (:name)";

    QString sqlUserStmt = "INSERT INTO user (email, age, group_id) "
                          "VALUES (:email, :age, :group_id)";

    query.prepare(sqlGroupStmt);

    foreach (Group group, groups) {
        query.bindValue(":name", QVariant(group.getName()));

        if (!query.exec()) {
            qDebug() << query.lastQuery();
            qDebug() << query.lastError();
        }
    }

    query.prepare(sqlUserStmt);

    foreach (User user, users) {
        query.bindValue(":email", user.getEmail());
        query.bindValue(":age", user.getAge());
        query.bindValue(":group_id", (long long) user.getGroupId());

        if (!query.exec()) {
            qDebug() << query.lastQuery();
            qDebug() << query.lastError();
        }
    }
}
