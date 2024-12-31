#include "widget.h"
#include<QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // set the title
    setWindowTitle("QLabels");
    //Set the size
    resize(1280,720);

    // Creating Q Label
    QLabel *label1 = new QLabel(this);
    // setting text
    label1->setText("This is the label");
    //label position
    label1->move(100,100);
    //label stylsheet

}
Widget::~Widget() {}
