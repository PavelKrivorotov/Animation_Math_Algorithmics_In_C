#ifndef ISOMORPHIC_H
#define ISOMORPHIC_H

#include "AnotherClasses/GraphClass/graph.h"


struct struct_coords {
    int number_circle;
    int x0, y0, r;

    int value;

    int number_group;
    int new_x0, new_y0, new_r;
};


class Isomorphic : public QObject
{
public:
    Isomorphic(QList<QList<int>> arr_matrix);
    ~Isomorphic();

public:
    QList<Graph*> get_arr_animations();

private:
    QList<QList<int>>       matrix;
    int                     size;

    Graph                   *graph;
    QList<Graph*>           arr_animations;

    int                     width_root, height_root, radius_root;
    QList<struct_coords>    arr_root_coords;

    int                     width_groups, height_groups;
    int                     width_interval, height_interval;
    int                     speed_x, speed_y;

    QList<int>              arr_index_groups;
    QList<int>              arr_circles_in_group;

private:
    void set_circles_to_scene();

    void set_vectors_to_scene();


    void set_root_coords();

    void set_default_graph();

    void set_groups();

    void set_new_coords();


    void rebuilding_objects_on_scene();
};

#endif // ISOMORPHIC_H
