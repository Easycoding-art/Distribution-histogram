#include "Lab2_3sem_GUI.h"
#include "Using.h"
#include <QString>
#include "Histogram.h"
int distribytion = 0;
int r = 0;
int number = 0;
Lab2_3sem_GUI::Lab2_3sem_GUI(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

Lab2_3sem_GUI::~Lab2_3sem_GUI()
{}

void Lab2_3sem_GUI::Execute()
{
    this->setStyleSheet("background-color: green");
    QPushButton* button = new QPushButton(this);
    button->setText("Draw histogram");
    button->move(20, 100);
    button->resize(50, 60);
    button->setStyleSheet("background-color: purple; color: white");
    QObject::connect(button, SIGNAL(clicked()), this, SLOT(clickedSlot()));


    QPushButton* button2 = new QPushButton(this);
    button2->setText("Poisson distribution");
    button2->move(20, 10);
    button2->resize(50, 60);
    button2->setStyleSheet("background-color:blue; color: white");
    QObject::connect(button2, SIGNAL(clicked()), this, SLOT(slot1()));

    QPushButton* button3 = new QPushButton(this);
    button3->setText("Uniform distribution");
    button3->move(50, 10);
    button3->resize(50, 60);
    button3->setStyleSheet("background-color:blue; color: white");
    QObject::connect(button3, SIGNAL(clicked()), this, SLOT(slot2()));

    QWidget* centralWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(centralWidget);
    layout->addWidget(button);
    layout->addWidget(button2);
    layout->addWidget(button3);
    
    QSlider* ps2 = new QSlider(Qt::Horizontal);
    ps2->setStyleSheet("background-color: pink");
    //устнавливаем диапазон значений
    ps2->setRange(0, 5000);
    //устанавливаем шаг страницы
    ps2->setPageStep(1);
    //задаем стартовое значение
    ps2->setValue(0);
    //задаем шаг для рисования рисок
    ps2->setTickInterval(2);
    //установим риски снизу и сверху
    ps2->setTickPosition(QSlider::TicksBothSides);
    //создаем надписи
    QLabel* label_1 = new QLabel("Number of people");
    label_1->setAlignment(Qt::AlignCenter);
    label_1->setFrameStyle(QFrame::Panel | QFrame::Plain);
    QLabel* label1 = new QLabel("0");
    label1->setAlignment(Qt::AlignCenter);
    label1->setFrameStyle(QFrame::Panel | QFrame::Plain);
    label1->setStyleSheet("background-color:brown; color: white");
    label_1->setStyleSheet("background-color:brown; color: white");
    //методом connect() сигнал ползунка
    //valueChanged(int) соединяется со слотом
    //надписи setNum(int)
    QObject::connect(ps2, SIGNAL(valueChanged(int)), label1, SLOT(setNum(int)));
    QObject::connect(ps2, SIGNAL(valueChanged(int)), this, SLOT(change_count(int)));
    //выполняется размещение элементов на поверхности
    //виджета wgt при помощи горизонтальной компоновки
    //QHBoxLayout* phbxL = new QHBoxLayout;
    //layout->setMargin(2);
    layout->setSpacing(7);
    layout->addWidget(label_1);
    layout->addWidget(ps2);
    layout->addWidget(label1);
    //this->setLayout(phbxL);


    QSlider* ps3 = new QSlider(Qt::Horizontal);
    ps3->setStyleSheet("background-color: yellow");
    //устнавливаем диапазон значений
    ps3->setRange(0, 20);
    //устанавливаем шаг страницы
    ps3->setPageStep(1);
    //задаем стартовое значение
    ps2->setValue(0);
    //задаем шаг для рисования рисок
    ps3->setTickInterval(2);
    //установим риски снизу и сверху
    ps3->setTickPosition(QSlider::TicksBothSides);
    //создаем надписи
    QLabel* label_3 = new QLabel("Radius of partition");
    label_3->setAlignment(Qt::AlignCenter);
    label_3->setFrameStyle(QFrame::Panel | QFrame::Plain);
    QLabel* label3 = new QLabel("0");
    label3->setAlignment(Qt::AlignCenter);
    label3->setFrameStyle(QFrame::Panel | QFrame::Plain);
    label3->setStyleSheet("background-color:black; color: white");
    label_3->setStyleSheet("background-color:black; color: white");
    //методом connect() сигнал ползунка
    //valueChanged(int) соединяется со слотом
    //надписи setNum(int)
    QObject::connect(ps3, SIGNAL(valueChanged(int)), label3, SLOT(setNum(int)));
    QObject::connect(ps3, SIGNAL(valueChanged(int)), this, SLOT(changeR(int)));
    //выполняется размещение элементов на поверхности
    //виджета wgt при помощи горизонтальной компоновки
    //QHBoxLayout* phbxL = new QHBoxLayout;
    //layout->setMargin(2);
    layout->setSpacing(7);
    layout->addWidget(label_3);
    layout->addWidget(ps3);
    layout->addWidget(label3);
    //this->setLayout(phbxL);
    setCentralWidget(centralWidget);
    setWindowTitle("Lab2_3sem");
    show();
}


void Lab2_3sem_GUI::clickedSlot()
{
    if (distribytion != 0 && r != 0 && number != 0) {
        Sequence<Person> people_sequence = create_people(number, distribytion);
        Histogram hist = Histogram(people_sequence, 0, number, distribytion, r);
        hist.draw();
        distribytion = 0;
    }
}

void Lab2_3sem_GUI::slot1() {
        distribytion = 1;
}

void Lab2_3sem_GUI::slot2() {
        distribytion = 2;
}
void Lab2_3sem_GUI::change_count(int value) {
    number = value;
}

void Lab2_3sem_GUI::changeR(int value) {
    r = value;
}