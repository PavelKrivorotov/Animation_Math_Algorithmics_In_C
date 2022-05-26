#ifndef VECTOR_H
#define VECTOR_H

#include <QGraphicsItem>
#include <QPen>


#define DISTANCE_AFTER_X0   40
#define DISTANCE_AFTER_Y0   10

#define WIDTH_TEXT_LABEL    15
#define HEIGHT_TEXT_LABEL   10


class Vector : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Vector(QObject *parent = nullptr);
    ~Vector();

public:
    void set_coords_vector(int x0=0, int y0=0, int x1=0, int y1=0, int dx=0);

    void set_value_vector(int value=0);

    void set_style_vector(QPen pen=QPen(QBrush(QColor(0, 0, 0)), 1.5), int arrow_width=3, int arrow_height=10);

public:
    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int x0, y0, x1, y1;
    int radius_circle;

    int value;

    int arrow_width, arrow_height;

    QColor  color_arrow;
    QPen    pen_arrow;

private:
    void get_angle_rotation_and_point_of_text(QPointF &pointf, float &angle);
};

#endif // VECTOR_H
