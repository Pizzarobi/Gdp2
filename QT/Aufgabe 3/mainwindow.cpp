#include <QResizeEvent>
#include "mainwindow.h"

MainWindow::MainWindow()
{
    QIcon icon("../signal/thi_icon.png");
    setWindowTitle("Hello");
    setWindowIcon(icon);
    edit = new QLineEdit();
    setCentralWidget(edit);
    resize(400,60);

    connect(edit,SIGNAL(textChanged(QString)),this,SLOT(changeText(QString)));
    //button = new QPushButton("Hello world");
    //setCentralWidget(button);
    //connect(button, SIGNAL(pressed()), this, SLOT(changeText()));
    //connect(button, SIGNAL(released()), this, SLOT(changeText()));
}

MainWindow::~MainWindow()
{
    delete edit;
}

void MainWindow::changeText(QString t)
{
    setWindowTitle(t);
}

void MainWindow::resizeEvent(QResizeEvent *event){
    const QSize s = event->size();
    int h = s.height();
    int w = s.width();
    text = std::to_string(w) + "/" + std::to_string(h);
    //button->setText(QString::fromStdString(text));
}

