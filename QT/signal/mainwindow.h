#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <string>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private slots:
    void changeText();

private:
    void resizeEvent(QResizeEvent *event) override;
    QPushButton *button;
    bool toggle = false;
    std::string text = "Hello again";
    QLineEdit* edit;
};

#endif // MAINWINDOW_H
