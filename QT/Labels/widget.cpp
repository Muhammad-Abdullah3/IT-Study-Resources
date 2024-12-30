#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    // set the title
    setWindowTitle("QLabels");
    //Set the size
    resize(1280,720);
}
Widget::~Widget() {}
