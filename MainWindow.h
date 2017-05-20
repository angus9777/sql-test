#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include "SqlTest.h"

#include <QMainWindow>


class SqlTest::MainWindow : public QMainWindow {

        Q_OBJECT

    public:
        MainWindow(QWidget* parent = 0);
        ~MainWindow();
};


#endif // MAINWINDOW_H
