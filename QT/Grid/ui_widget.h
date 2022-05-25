#ifndef UI_WIDGET_H
#define UI_WIDGET_H

//#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <string>

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {
        // init
        layout = new QGridLayout();
        edit = new QLineEdit();
        button = new QPushButton("Click");
        label = new QLabel();

        // Layout
        label->setAlignment(Qt::AlignHCenter);

        layout->addWidget(label,0,0);
        layout->addWidget(edit,0,1,0,2);
        layout->addWidget(button,1,0,1,2);
//        layout->addWidget(edit, 0,0);
//        layout->addWidget(button,0,1);
//        layout->addWidget(label,1,0,1,2);

        setLayout(layout);
        connect(button, SIGNAL(clicked()), this, SLOT(changeText()));
    }

    ~MainWidget()
    {
        delete edit;
        delete button;
        delete label;
        delete layout;
    }

private slots:
    void changeText()
    {
        label->setText(edit->text());
    }

private:
    QLineEdit *edit;
    QPushButton *button;
    QLabel *label;
    QGridLayout *layout;
    std::string text;
};

#endif // UI_WIDGET_H
