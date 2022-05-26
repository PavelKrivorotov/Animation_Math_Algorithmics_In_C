#ifndef CIRCLE_H
#define CIRCLE_H

#include <QGraphicsItem>


class Circle : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Circle(QObject *parent = nullptr);
    ~Circle();

public:
    void set_coords_circle(int x_center=0, int y_center=0, int radius=10);

    void set_number_circle(int number=0);

    void set_style_circle(QColor brush_color=QColor(255, 255, 255), QColor font_color=QColor(0, 0, 0));

public:
    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
//    int x_center, y_center, radius;
//    int number_circle;

    int x0, y0, radius, number;

    QColor brush_color_circle, font_color_circle;
};

#endif // CIRCLE_H
