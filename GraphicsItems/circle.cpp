
#include "circle.h"

#include <QPainter>
#include <QRectF>
#include <QColor>


//#include <iostream>
//using namespace std;

Circle::Circle(QObject *parent) : QObject(parent), QGraphicsItem()
{
    set_coords_circle();
    set_number_circle();
    set_style_circle();
}


Circle::~Circle()
{

}


QRectF Circle::boundingRect() const {
    return QRectF(x0 - radius, y0 - radius, 2*radius, 2*radius);
}


void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(QBrush(brush_color_circle));

    painter->drawEllipse(x0 - radius, y0 - radius, 2*radius, 2*radius);

    painter->setFont(QFont("Helvetica", 16, 1));
    painter->setPen(QPen(QBrush(font_color_circle), 1));

    QRectF rect_text;
    rect_text.setCoords(x0 - radius*cos(M_PI/4), y0 - radius*sin(M_PI/4),
                        x0 + radius*cos(M_PI/4), y0 + radius*sin(M_PI/4));
    painter->drawText(rect_text ,Qt::Alignment(Qt::AlignHCenter | Qt::AlignVCenter),
                      QString::number(number));
}



void Circle::set_coords_circle(int center_x0, int center_y0, int r) {
    x0 = center_x0;
    y0 = center_y0;
    radius = r;
}


void Circle::set_number_circle(int num) {
    number = num;
}


void Circle::set_style_circle(QColor brush_color, QColor font_color) {
    brush_color_circle = brush_color;
    font_color_circle = font_color;
}
