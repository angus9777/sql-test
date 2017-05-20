#include "MainWindow.h"

#include <QDebug>
#include <QTableView>
#include <QTreeView>
#include <QSqlTableModel>
#include <QSqlQuery>
#include <QSqlDatabase>
#include <QSqlError>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>


SqlTest::MainWindow::MainWindow(QWidget* parent)
        : QMainWindow(parent) {

    createConnection();

    bool createMode = true;

    addTestTables(true);

    if (createMode) {
        insertTestData();
    }

    QTableView* userTableView = new QTableView;
    QTreeView* userTreeView = new QTreeView;
    QTableView* groupTableView = new QTableView;
    QTreeView* groupTreeView = new QTreeView;

    //

    QSqlTableModel* userSqlTableModel = new QSqlTableModel;

    userSqlTableModel->setTable("user");
    userSqlTableModel->setFilter("age > 25");
    userSqlTableModel->select();
    userSqlTableModel->setHeaderData(1, Qt::Horizontal, "Email");
    userSqlTableModel->setHeaderData(2, Qt::Horizontal, "Age");
    userSqlTableModel->setHeaderData(3, Qt::Horizontal, "GroupId");


    if (userSqlTableModel->lastError().isValid()) {
        qDebug() << userSqlTableModel->lastError();
    }

    //

    QSqlTableModel* groupSqlTableModel = new QSqlTableModel;

    groupSqlTableModel->setTable("user_group");
    groupSqlTableModel->select();
    groupSqlTableModel->setHeaderData(1, Qt::Horizontal, "Name");

    if (groupSqlTableModel->lastError().isValid()) {
        qDebug() << groupSqlTableModel->lastError();
    }

    //

    userTableView->setModel(userSqlTableModel);
    userTableView->hideColumn(0);

    userTreeView->setModel(userSqlTableModel);
    userTreeView->hideColumn(0);

    groupTableView->setModel(groupSqlTableModel);
    groupTableView->hideColumn(0);

    groupTreeView->setModel(groupSqlTableModel);
    groupTreeView->hideColumn(0);

    //

    QWidget* widget = new QWidget;

    QVBoxLayout* widgetLayout = new QVBoxLayout;
    QHBoxLayout* userLayout = new QHBoxLayout;
    QHBoxLayout* groupLayout = new QHBoxLayout;

    userLayout->addWidget(userTableView);
    userLayout->addWidget(userTreeView);

    groupLayout->addWidget(groupTableView);
    groupLayout->addWidget(groupTreeView);

    widgetLayout->addLayout(userLayout);
    widgetLayout->addLayout(groupLayout);

    widget->setLayout(widgetLayout);

    setCentralWidget(widget);
}


SqlTest::MainWindow::~MainWindow() {
}
