// mainwindow
#include "mainwindow.h"

MainWindow::MainWindow(){
    QIcon icon("D:/Stuff_3.0/Repos/Gdp2/QT/thi_icon.png");
    setWindowIcon(icon);
    setWindowTitle("Cock And Balls");
    button = new QPushButton("HalloWeld");
    setCentralWidget(button);
    connect(button, SIGNAL(clicked()), this, SLOT(changeText()));
}

MainWindow::~MainWindow(){
    delete button;
}

void MainWindow::changeText(){
    clicked = !clicked;
    if(clicked){
        button->setText(QString::fromStdString(text));
    }else
    {
        button->setText("Yo");
    }
}
