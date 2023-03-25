#include "Lab2_3sem_GUI.h"
#include <QtWidgets/QApplication>

#include <QtWidgets/QMainWindow>
#include "ui_Lab2_3sem_GUI.h"
#include <QPushButton>
#include <QMessageBox>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QPainter>
#include <QDebug>
#include <QComboBox>
#include <QLayout>
#include <QLabel>
#include <Windows.h>
#include <QString>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab2_3sem_GUI w;
    w.Execute();
    return a.exec();
}
