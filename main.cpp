#include "MainWindow.h"

#include <QApplication>


int main(int argc, char* argv[]) {
    QApplication application(argc, argv);
    SqlTest::MainWindow mainWindow;

    mainWindow.showMaximized();

    return application.exec();
}
