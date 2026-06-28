#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load stylesheet
    QFile file(":/style.qss");

    if(file.open(QFile::ReadOnly))
    {
        QString style = file.readAll();
        a.setStyleSheet(style);
        file.close();
    }

    MainWindow w;
    w.show();

    return a.exec();
}