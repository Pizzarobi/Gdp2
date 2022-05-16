#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <string>

class MainWindow: public QMainWindow {
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void changeText();

private:
    QPushButton *button;
    bool clicked = false;
    std::string text = "PepeLaugh";
};

#endif // MAINWINDOW_H
