
#include "label.h"

#include <QPainter>
#include <QList>
#include <QPointF>

Label::Label(QObject *parent) : QObject(parent), QGraphicsItem()
{
    set_coords_label();
    set_state_label();
    set_values_label();
}


Label::~Label()
{

}


QRectF Label::boundingRect() const {
    return QRectF(x0 - radius_circle - DEFAULT_WIDTH_LABEL/2, y0 - radius_circle - DEFAULT_HEIGHT_LABEL/2,
                  DEFAULT_WIDTH_LABEL, DEFAULT_HEIGHT_LABEL);
}


void Label::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPointF text_point;
    text_point.setX(x0 - radius_circle - DEFAULT_WIDTH_LABEL/2);
    text_point.setY(y0 - radius_circle - DEFAULT_HEIGHT_LABEL/2);

    QString text_label;
    text_label = get_text_label();

    painter->drawText(text_point, text_label);
}



void Label::set_coords_label(int center_x0, int center_y0, int r) {
    x0 = center_x0;
    y0 = center_y0;
    radius_circle = r;
}


void Label::set_state_label(bool f) {
    label_state = f;
}


void Label::set_values_label(int value) {
    arr_values.append(value);
}



QString Label::get_text_label() {
    QString text = "d= ";

    int ind = 0;
    while (ind < arr_values.size() - 1) {
        text = text + QString::number(arr_values[ind]) + ", ";

        ind++;
    }

    text = text + QString::number(arr_values[ind]);

    return text;
}

