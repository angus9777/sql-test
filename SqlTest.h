#ifndef SQLTEST_H
#define SQLTEST_H


namespace SqlTest {

    class MainWindow;
    class Group;
    class User;

    bool createConnection();
    void addTestTables(bool createMode = true);
    void insertTestData();
}


#endif // SQLTEST_H
