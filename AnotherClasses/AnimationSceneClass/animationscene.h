#ifndef ANIMATIONSCENE_H
#define ANIMATIONSCENE_H

#include "GraphicsItems/circle.h"
#include "GraphicsItems/vector.h"
#include "GraphicsItems/label.h"

#include "Windows/Dialogs/datadialog.h"

#include "MathAlgorithmics/isomorphic.h"

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QTimer>


class AnimationScene : public QGraphicsView
{
    Q_OBJECT
public:
    explicit AnimationScene(QWidget *parent = nullptr);
    ~AnimationScene();

public:
    void create_graphics_objects();

    void set_graphics_objects();

    void show_animation();

    void ok_cliced();

protected:
    void resizeEvent(QResizeEvent *event);

signals:
    void show_completed_cliced();

public slots:
    void show_datadialog(int ind);

private:
    int                     index_algorithm;
    int                     animation_scene_number;

    QList<QList<int>>       matrix;
    QList<Graph*>           arr_animations;

    QList<Circle*>          arr_circles;
    QList<QList<Vector*>>   arr_vectors;
    QList<Label*>           arr_labels;
    QStringList             arr_text;

private:
    QGraphicsScene  *scene;
    QTimer          *timer;

    DataDialog      *datadialog;

    Graph           *graph;

    Isomorphic      *isomorphic;
};

#endif // ANIMATIONSCENE_H
