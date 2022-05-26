
#include "vector.h"

#include <QPainter>
#include <QList>
#include <QPointF>
#include <QColor>

//#include <iostream>
//using namespace std;

Vector::Vector(QObject *parent) : QObject(parent), QGraphicsItem()
{
    set_coords_vector();
    set_value_vector();
    set_style_vector();
}


Vector::~Vector()
{

}


QRectF Vector::boundingRect() const {
    return QRectF(x0, y0, x1 - x0, y1 - y0);
}


void Vector::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
//    this->setPos(x0, y0);
    painter->translate(x0, y0);

    float line_width, angle;
    QPointF text_point;

    line_width = sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2));
    get_angle_rotation_and_point_of_text(text_point, angle);

    painter->save();

    painter->rotate(angle);
    painter->setPen(pen_arrow);
    painter->setBrush(QBrush(color_arrow));

    painter->drawLine(radius_circle, 0, line_width - radius_circle - arrow_width, 0);

    QList<QPoint> points;
    points.append(QPoint(line_width - radius_circle, 0));
    points.append(QPoint(line_width - radius_circle - arrow_height, arrow_width));
    points.append(QPoint(line_width - radius_circle - arrow_height, -arrow_width));
    painter->drawPolygon(QPolygon(points));

    painter->translate(text_point);
    painter->rotate(-angle);

    painter->drawText(QPointF(0, 0), QString::number(value));

    painter->restore();
};



void Vector::set_coords_vector(int start_x0, int start_y0, int stop_x1, int stop_y1, int dx) {
    x0 = start_x0;
    y0 = start_y0;
    x1 = stop_x1;
    y1 = stop_y1;
    radius_circle = dx;
}


void Vector::set_value_vector(int val) {
    value = val;
}


void Vector::set_style_vector(QPen pen, int arrow_w, int arrow_h) {
    color_arrow = pen.color();
    pen_arrow = pen;

    arrow_width = arrow_w;
    arrow_height = arrow_h;
}



void Vector::get_angle_rotation_and_point_of_text(QPointF &pointf, float &angle) {
    angle = asin((y1 - y0) / sqrt(pow(x1 - x0, 2) + pow(y1 - y0, 2)));
    angle= abs(angle) * 180 / M_PI;

    if ((x1 - x0) > 0 && (y1 - y0) > 0) {
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(0);
    }

    else if ((x1 - x0) < 0 && (y1 - y0) > 0) {
        angle = 180 - angle;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(-DISTANCE_AFTER_Y0);
    }

    else if ((x1 - x0) < 0 && (y1 - y0) < 0) {
        angle = 180 + angle;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(0);
    }

    else if ((x1 - x0) > 0 && (y1 - y0) < 0) {
        angle = 360 - angle;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(DISTANCE_AFTER_Y0);
    }

    else if ((x1 - x0) == 0 && (y1 - y0) > 0) {
        angle = 90;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(-DISTANCE_AFTER_Y0);
    }

    else if ((x1 - x0) == 0 && (y1 - y0) < 0) {
        angle = 270;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(DISTANCE_AFTER_Y0);
    }

    else if ((x1 - x0) > 0 && (y1 - y0) == 0) {
        angle = 0;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(DISTANCE_AFTER_Y0);
    }

    else if ((x1 - x0) < 0 && (y1 - y0) == 0) {
        angle = 180;
        pointf.setX(DISTANCE_AFTER_X0);
        pointf.setY(-DISTANCE_AFTER_Y0);
    }
}

