#pragma once

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

class Lab2_3sem_GUI : public QMainWindow
{
    Q_OBJECT

public:
    Lab2_3sem_GUI(QWidget *parent = nullptr);
    ~Lab2_3sem_GUI();
    void Execute();
public slots:
    void clickedSlot();
    void slot1();
    void slot2();
    void changeR(int);
    void change_count(int);


private:
    Ui::Lab2_3sem_GUIClass ui;
};
