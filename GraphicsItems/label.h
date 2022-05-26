#ifndef LABEL_H
#define LABEL_H

#include <QGraphicsItem>


#define DEFAULT_WIDTH_LABEL     40
#define DEFAULT_HEIGHT_LABEL    10


class Label : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit Label(QObject *parent = nullptr);
    ~Label();

public:
    void set_coords_label(int x_center=0, int y_center=0, int radius=10);

    void set_state_label(bool constant=false);

    void set_values_label(int value=-1);

public:
    virtual QRectF boundingRect() const override;

    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int x0, y0, radius_circle;

    bool label_state;

    QList<int> arr_values;

private:
    QString get_text_label();
};

#endif // LABEL_H
