#ifndef UI_WIDGET_H
#define UI_WIDGET_H

//#include <QMainWindow>
#include <QtWidgets>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLabel>
#include <string>
#include "vertical.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QMainWindow *parent = nullptr): QWidget(parent)
    {
        // init
        button = new QPushButton("Click");
        editX = new QLineEdit();
        editY = new QLineEdit();
        editH = new QLineEdit();
        labelX = new QLabel();
        labelY = new QLabel();
        labelH = new QLabel();
        labelInfo = new QLabel();

        // set labels
        labelX->setText("x:");
        labelY->setText("y:");
        labelH->setText("height:");
        button->setText("Start");
        labelInfo->setText("\n\n");

        // Layout
        layout1 = new QGridLayout();
        layout1->addWidget(labelX,0,0);
        layout1->addWidget(editX,0,1);

        layout1->addWidget(labelY,1,0);
        layout1->addWidget(editY,1,1);

        layout1->addWidget(labelH,2,0);
        layout1->addWidget(editH,2,1);

        layout1->addWidget(button,3,0,3,2);

        labelInfo->setAlignment(Qt::AlignHCenter);
        layout1->addWidget(labelInfo,6,0,6,2);

        setLayout(layout1);

        connect(button, SIGNAL(clicked()), this, SLOT(startFlight()));
    }

    ~MainWidget()
    {
        delete button;
        delete editX;
        delete editY;
        delete editH;
        delete labelX;
        delete labelY;
        delete labelH;
        delete labelInfo;
        delete layout;
    }

private slots:
    void startFlight()
    {
        float destX = editX->text().toFloat();
        float destY = editY->text().toFloat();
        float height = editH->text().toFloat();

        labelInfo->setText("Please Wait...");
        Vertical vert("yo");
        vert.flyToDest(destX,destY,height,10);

        //print the String
        char ausgabe[100];
        std::sprintf(ausgabe,"Flight completed\nPosition: %.2f | %.2f | %.2f meter\nFlight Time: %.2f sec",vert.getPosition()[0],vert.getPosition()[1],vert.getPosition()[2],vert.getFtime());
        std::string str(ausgabe);
        labelInfo->setText(QString::fromStdString(str));
    }

private:
    QPushButton *button;
    QLineEdit *editX;
    QLineEdit *editY;
    QLineEdit *editH;
    QLabel *labelX;
    QLabel *labelY;
    QLabel *labelH;
    QLabel *labelInfo;
    QGridLayout *layout;
    QGridLayout *layout1;
    QGridLayout *layout2;
    QWidget *widget1;
    QWidget *widget2;
};

#endif // UI_WIDGET_H
