#ifndef ISOMORPHIC_H
#define ISOMORPHIC_H

#include "AnotherClasses/GraphClass/graph.h"


struct struct_coords {
    int ind_circle;
    int x0;
    int y0;
    int r;
};


class Isomorphic : public QObject
{
public:
    Isomorphic(QList<QList<int>> arr_matrix);
    ~Isomorphic();

public:
    Graph* get_graph(int index);

    QList<Graph*> get_arr_animations();

private:
    QList<QList<int>>       matrix;
    int                     size;

    Graph                   *graph;
    QList<Graph*>           arr_animations;

    int                     width_root;
    int                     height_root;
    int                     radius_root;
    QList<struct_coords>    arr_root_coords;

    int                     width_groups;
    int                     height_groups;
    int                     width_interval;
    int                     height_interval;
    QList<QList<int>>       arr_groups;
    QList<int>              arr_groups_coords;

private:
    void set_circles_to_scene();

    void set_vectors_to_scene();

    void set_labels_to_scene();


    void create_root_coords();

    void create_groups();

    void create_groups_coords();


    void rebuilding_objects_on_scene();
};

#endif // ISOMORPHIC_H
