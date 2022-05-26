
#include "isomorphic.h"

#include <iostream>
using namespace std;


Isomorphic::Isomorphic(QList<QList<int>> arr_matrix)
{
    matrix = arr_matrix;
    size = arr_matrix.size();

    // Set coords animation (width, height, radius)
    width_root = 0;
    height_root = 0;
    radius_root = 150;

    create_root_coords();

    graph = new Graph(matrix);

    for (int ind_circle = 0; ind_circle < size; ind_circle++) {
        int x0 = arr_root_coords[ind_circle].x0;
        int y0 = arr_root_coords[ind_circle].y0;
        int r = arr_root_coords[ind_circle].r;

        QPen style_number;
        style_number.setColor(QColor(0, 0, 0));
        style_number.setWidth(2);

        QColor background_circle;
        background_circle.setRgb(255, 255, 255);

        QPen style_circle;
        style_circle.setColor(QColor(0, 0, 0));
        style_circle.setWidth(2);

        graph->set_coords_circle(ind_circle, x0, y0, r);
        graph->set_visable_circle(ind_circle, false);
        graph->set_update_circle(ind_circle, false);
        graph->set_number_circle(ind_circle, ind_circle + 1, style_number);
        graph->set_style_circle(ind_circle, background_circle, style_circle);


        int ind = 0;
        for (int ind_vector = 0; ind_vector < arr_matrix[ind_circle].size(); ind_vector++) {
            if (arr_matrix[ind_circle][ind_vector] != 0 && arr_matrix[ind_circle][ind_vector] != -1) {
                int x1 = arr_root_coords[ind_vector].x0;
                int y1 = arr_root_coords[ind_vector].y0;
                int value_1 = arr_matrix[ind_circle][ind_vector];
                int value_2 = 0;

                QPen style_vector;
                style_vector.setBrush(QBrush(QColor(0, 0, 0)));
                style_vector.setWidth(2);

                graph->set_coords_vector(ind_circle, ind, x0, y0, x1, y1, ind_vector);
                graph->set_visable_vector(ind_circle, ind, false);
                graph->set_update_vector(ind_circle, ind, false);
                graph->set_values_vector(ind_circle, ind, value_1, value_2);
                graph->set_style_vector(ind_circle, ind, style_vector);

                ind = ind + 1;
            }
        }

        int x0_label = x0 - r;
        int y0_label = y0 - r;

        graph->set_coords_label(ind_circle, x0_label, y0_label);
        graph->set_value_label(ind_circle, -1);
        graph->set_visable_label(ind_circle, false);
        graph->set_update_label(ind_circle, false);
        graph->set_constant_label(ind_circle, false);
    }

    arr_animations.append(graph);

    set_circles_to_scene();
    set_vectors_to_scene();

    create_groups();

    rebuilding_objects_on_scene();

//    for (int ind_1 = 0; ind_1< arr_groups.size(); ind_1++) {
//        cout << "Group " << ind_1 << " : ";

//        for (int ind_2 = 0; ind_2 < arr_groups[ind_1].size(); ind_2++) {
//            cout << arr_groups[ind_1][ind_2] << " ";
//        }

//        cout << "" << endl;
//    }
}


Isomorphic::~Isomorphic()
{

}



QList<Graph*> Isomorphic::get_arr_animations() {
    return arr_animations;
}


//Graph* Isomorphic::get_graph(int index) {
//    return arr_animations[index];
//}


void Isomorphic::create_root_coords() {
    int ind = 0;

    for (float angle = M_PI; angle > -M_PI; angle -= 2*M_PI / size) {
        struct_coords coord;
        coord.ind_circle = ind;

        coord.x0 = width_root + (int) radius_root*cos(angle);
        coord.y0 = height_root - (int) radius_root*sin(angle);

        coord.r = 25;

        arr_root_coords.append(coord);
        ind = ind + 1;
    }
}


void Isomorphic::set_circles_to_scene() {
    for (int ind_circle = 0; ind_circle < size; ind_circle++) {
        Graph *new_graph = new Graph(graph);

//        cout << "New  " << new_graph << "    Old  " << graph << endl;

        new_graph->set_visable_circle(ind_circle, true);
        new_graph->set_update_circle(ind_circle, true);

        graph = new_graph;
        arr_animations.append(graph);
    }
}


void Isomorphic::set_vectors_to_scene() {
    for (int ind_circle = 0; ind_circle < size; ind_circle++) {
        int ind = 0;

        for (int ind_vector = 0; ind_vector < size; ind_vector++) {
            if (matrix[ind_circle][ind_vector] != 0 && matrix[ind_circle][ind_vector] != -1) {
                Graph *new_graph = new Graph(graph);

                new_graph->set_visable_vector(ind_circle, ind, true);
                new_graph->set_update_vector(ind_circle, ind, true);

                graph = new_graph;
                arr_animations.append(graph);

                ind = ind + 1;
            }
        }
    }
}


void Isomorphic::set_labels_to_scene() {
    for (int ind_label = 0; ind_label < size; ind_label++) {
        Graph *new_graph = new Graph(graph);

        new_graph->set_visable_label(ind_label, true);
        new_graph->set_update_label(ind_label, true);

        graph = new_graph;
        arr_animations.append(graph);
    }
}


void Isomorphic::create_groups() {
    QList<int>  added_circle;

    while (added_circle.size() < size) {
        QList<int>  group;

        for (int ind_circle = 0; ind_circle < size; ind_circle++) {
            bool flag = false;
            for (int ind_row = 0; ind_row < size; ind_row++) {
                if ((matrix[ind_row][ind_circle] != 0 &&  matrix[ind_row][ind_circle] != -1 &&
                    added_circle.indexOf(ind_row) == -1) || (added_circle.indexOf(ind_circle) != -1)) {

                    flag = true;
                    break;
                }
            }

            if (!flag) {
                group.append(ind_circle);
            }
        }

        if (group.size()) {
            arr_groups.append(group);

            for (int ind = 0; ind < group.size(); ind++) {
                added_circle.append(group[ind]);
            }
        }
    }
}


void Isomorphic::create_groups_coords() {

}


void Isomorphic::rebuilding_objects_on_scene() {
    for (int ind_group = 0; ind_group < arr_groups.size(); ind_group++) {
        for (int ind = 0; ind < arr_groups[ind_group].size(); ind++) {
            int ind_circle = arr_groups[ind_group][ind];

            Graph *new_graph = new Graph(graph);

            QColor color;
            color.setRgb(0, 255, 0);

            QPen pen;
            pen.setWidth(2);

            new_graph->set_style_circle(ind_circle, color, pen);
            new_graph->set_update_circle(ind_circle, true);

            graph = new_graph;
            arr_animations.append(graph);
        }


//        for (int ind_row = 0; ind_row < arr_groups[ind_group].size(); ind_row++) {
//            for (int ind_col = 0; ind_col < arr_groups[ind].size(); ind++) {
//                Graph *new_graph = new Graph(graph);

//                QPen pen;
//                pen.setBrush(QBrush(QColor(255, 0, 0)));
//                pen.setWidth(2);

//                new_graph->set_style_vector(ind_group, ind, pen);
//                new_graph->set_update_vector(ind_group, ind, true);

//                graph = new_graph;
//                arr_animations.append(graph);
//            }
//        }

//        Graph *new_graph = new Graph(graph);

//        for (int ind = 0; ind < arr_groups[ind_group].size(); ind++) {
//            new_graph->set_visable_vector(ind_group, ind, false);
//            new_graph->set_update_vector(ind_group, ind, true);
//        }

//        graph = new_graph;
//        arr_animations.append(graph);


        // ...
    }
}

