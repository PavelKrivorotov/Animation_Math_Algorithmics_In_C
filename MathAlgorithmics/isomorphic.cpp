
#include "isomorphic.h"

#include <iostream>
using namespace std;


Isomorphic::Isomorphic(QList<QList<int>> arr_matrix)
{
    matrix = arr_matrix;
    size = arr_matrix.size();

    width_root = 0;
    height_root = 0;
    radius_root = 150;

    width_groups = 0;
    height_groups = 0;
    width_interval = 80;
    height_interval = 50;

    speed_x = 20;
    speed_y = 20;

    set_root_coords();

    set_default_graph();

    set_circles_to_scene();
    set_vectors_to_scene();

    set_groups();
    set_new_coords();


//    cout << arr_root_coords.size() << endl;


//    for (int ind = 0; ind < arr_root_coords.size(); ind++) {
//        cout << "Number - " << arr_root_coords[ind].value << "   Group - " << arr_root_coords[ind].number_group << endl;
//    }


//    cout << "\n\n" << endl;


//    for (int ind = 0; ind < indexes_groups.size(); ind++) {
//        cout << "Group - " << indexes_groups[ind] << "   Count - " << count_circles_in_group[ind] << endl;
//    }

    rebuilding_objects_on_scene();
}


Isomorphic::~Isomorphic()
{
    for (int ind = 0; ind < arr_animations.size(); ind++) {
        delete arr_animations[ind];
    }
}



QList<Graph*> Isomorphic::get_arr_animations() {
    return arr_animations;
}



void Isomorphic::set_root_coords() {
    float angle = M_PI;

    int ind = 0;
    while (ind < size) {
        struct_coords coord;
        coord.number_circle = ind;
        coord.x0 = width_root + (int) radius_root*cos(angle);
        coord.y0 = height_root - (int) radius_root*sin(angle);
        coord.r = 25;
        coord.value = ind + 1;

        arr_root_coords.append(coord);

        angle = angle - 2*M_PI / size;
        ind = ind + 1;
    }
}


void Isomorphic::set_default_graph() {
    graph = new Graph();

    for (int ind_coords = 0; ind_coords < arr_root_coords.size(); ind_coords++) {
        int x0, y0, r, value;
        x0 = arr_root_coords[ind_coords].x0;
        y0 = arr_root_coords[ind_coords].y0;
        r = arr_root_coords[ind_coords].r;
        value = arr_root_coords[ind_coords].value;

        QColor  color_circle;
        color_circle.setRgb(255, 255, 255);

        QPen    pen_value;
        pen_value.setColor(QColor(0, 0, 0));
        pen_value.setWidth(2);

        QPen    pen_circle;
        pen_circle.setColor(QColor(0, 0, 0));
        pen_circle.setWidth(2);

        graph->append_new_circle(ind_coords);
        graph->set_coords_circle(ind_coords, x0, y0, r);
        graph->set_value_circle(ind_coords, value, pen_circle);
        graph->set_style_circle(ind_coords, color_circle, pen_circle);
        graph->set_visable_circle(ind_coords, false);
        graph->set_update_circle(ind_coords, true);
    }

    for (int ind_row = 0; ind_row < size; ind_row++) {
        for (int ind_col = 0; ind_col < size; ind_col++) {
            if (matrix[ind_row][ind_col] != 0 && matrix[ind_row][ind_col] != -1) {
                int x0, y0, x1, y1, value_1, value_2;
                x0 = arr_root_coords[ind_row].x0;
                y0 = arr_root_coords[ind_row].y0;
                x1 = arr_root_coords[ind_col].x0;
                y1 = arr_root_coords[ind_col].y0;
                value_1 = matrix[ind_row][ind_col];
                value_2 = 0;

                QPen pen_vector;
                pen_vector.setColor(QColor(0, 0, 0));
                pen_vector.setWidth(2);

                graph->append_new_vector(ind_row, ind_col);
                graph->set_coords_vector(ind_row, ind_col, x0, y0, x1, y1);
                graph->set_values_vector(ind_row, ind_col, value_1, value_2);
                graph->set_style_vector(ind_row, ind_col, pen_vector);
                graph->set_visable_vector(ind_row, ind_col, false);
                graph->set_update_vector(ind_row, ind_col, true);
            }
        }
    }

    arr_animations.append(graph);
}


void Isomorphic::set_circles_to_scene() {
    for (int ind_circle = 0; ind_circle < size; ind_circle++) {
        Graph *new_graph = new Graph(graph);

        new_graph->set_visable_circle(ind_circle, true);
        new_graph->set_update_circle(ind_circle, true);

        graph = new_graph;
        arr_animations.append(graph);
    }
}


void Isomorphic::set_vectors_to_scene() {
    for (int ind_row = 0; ind_row < size; ind_row++) {
        for (int ind_col = 0; ind_col < size; ind_col++) {
            if (matrix[ind_row][ind_col] != 0 && matrix[ind_row][ind_col] != -1) {
                Graph *new_graph = new Graph(graph);

                new_graph->set_visable_vector(ind_row, ind_col, true);
                new_graph->set_update_vector(ind_row, ind_col, true);

                graph = new_graph;
                arr_animations.append(graph);
            }
        }
    }
}


void Isomorphic::set_groups() {
    QList<int>  added_circle;
    int ind_group = 0;
    int ind_count = 0;

    while (added_circle.size() < size) {
        QList<int> group;

        for (int ind_col = 0; ind_col < size; ind_col++) {
            bool flag = true;
            for (int ind_row = 0; ind_row < size; ind_row++) {
                if ((matrix[ind_row][ind_col] != 0 &&  matrix[ind_row][ind_col] != -1 &&
                    added_circle.indexOf(ind_row) == -1) || (added_circle.indexOf(ind_col) != -1)) {
                    flag = false;
                }
            }

            if (flag) {
                arr_root_coords[ind_col].number_group = ind_group;
                group.append(ind_col);

                ind_count = ind_count + 1;
            }
        }

        for (int ind = 0; ind < group.size(); ind++) {
            added_circle.append(group[ind]);
        }

        arr_index_groups.append(ind_group);
        arr_circles_in_group.append(ind_count);

        ind_group = ind_group + 1;
        ind_count = 0;
    }
}


void Isomorphic::set_new_coords() {
    int count_groups = arr_index_groups.size();
    int x_left;

    // Set coords x;
    if (count_groups % 2 == 0) {
        x_left = width_groups -((count_groups/2 - 1)*(2*arr_root_coords[0].r + width_interval) +
                 arr_root_coords[0].r + width_interval/2);
    }

    else {
        x_left = width_groups -(count_groups/2 * (2*arr_root_coords[0].r + width_interval));
    }

    for (int ind_groups = 0; ind_groups < count_groups; ind_groups++) {
        int x0 = x_left + ind_groups * (2*arr_root_coords[0].r + width_interval);

        for (int ind_coords = 0; ind_coords < arr_root_coords.size(); ind_coords++) {
            if (arr_root_coords[ind_coords].number_group == arr_index_groups[ind_groups]) {
                arr_root_coords[ind_coords].new_x0 = x0;
            }
        }
    }


    // Set coords y
    for (int ind_objects = 0; ind_objects < arr_circles_in_group.size(); ind_objects++) {
        int count_circles = arr_circles_in_group[ind_objects];
        int y_top;

        if (count_circles % 2 == 0) {
            y_top = height_groups -((count_circles/2 - 1)*(2*arr_root_coords[0].r + height_interval) +
                    arr_root_coords[0].r + height_interval/2);
        }

        else {
            y_top = height_groups -(count_circles/2 * (2*arr_root_coords[0].r + height_interval));
        }

        int ind = 0;
        for (int ind_coords = 0; ind_coords < arr_root_coords.size(); ind_coords++) {
            if (arr_root_coords[ind_coords].number_group == ind_objects) {
                int y0 = y_top + ind * (2*arr_root_coords[0].r + height_interval);
                arr_root_coords[ind_coords].new_y0 = y0;
                ind = ind + 1;
            }
        }
    }
}


void Isomorphic::rebuilding_objects_on_scene() {
    for (int ind_groups = 0; ind_groups < arr_index_groups.size(); ind_groups++) {
        QList<int> temp_index_circles, temp_index_vectors;

        // Подсвечиваем зелёным цветом все узлы, удовлетворяющие условию
        for (int ind_coords = 0; ind_coords < arr_root_coords.size(); ind_coords++) {
            if (arr_root_coords[ind_coords].number_group == ind_groups) {
                Graph *new_graph = new Graph(graph);

                QColor color_circle;
                color_circle.setRgb(0, 255, 0);

                QPen pen_circle;
                pen_circle.setColor(QColor(0, 0, 0));
                pen_circle.setWidth(2);

                new_graph->set_style_circle(ind_coords, color_circle, pen_circle);
                new_graph->set_visable_circle(ind_coords, true);
                new_graph->set_update_circle(ind_coords, true);

                temp_index_circles.append(ind_coords);

                graph = new_graph;
                arr_animations.append(graph);
            }
        }


        // Выделяем красным цветом все вектора, исходящие из подходящих узлов.
        for (int ind_coords = 0; ind_coords < temp_index_circles.size(); ind_coords++) {
            for (int ind_col = 0; ind_col < size; ind_col++) {
                int num_circle = temp_index_circles[ind_coords];

                if (matrix[num_circle][ind_col] != 0 && matrix[num_circle][ind_col] != -1) {
                    Graph *new_graph = new Graph(graph);

                    int ind_vector = graph->get_index_vector(num_circle, ind_col);

                    QPen pen_vector;
                    pen_vector.setColor(QColor(255, 0, 0));
                    pen_vector.setWidth(2);

                    new_graph->set_style_vector(ind_vector, pen_vector);
                    new_graph->set_visable_vector(ind_vector, true);
                    new_graph->set_update_vector(ind_vector, true);

                    temp_index_vectors.append(ind_vector);

                    graph = new_graph;
                    arr_animations.append(graph);
                }
            }
        }


        // Делаем все выделенные вектора красным цветом - невидимыми.
        Graph *new_graph = new Graph(graph);

        for (int ind = 0; ind < temp_index_vectors.size(); ind++) {
            int ind_vector = temp_index_vectors[ind];

            QPen pen_vector;
            pen_vector.setColor(QColor(0, 0, 0));
            pen_vector.setWidth(2);

            new_graph->set_style_vector(ind_vector, pen_vector);
            new_graph->set_visable_vector(ind_vector, false);
            new_graph->set_update_vector(ind_vector, true);
        }

        graph = new_graph;
        arr_animations.append(graph);


        // Перестраиваем выбранные узлы на новые координаты.
        bool flag_1 = true;
        while (flag_1) {
            for (int ind_coords = 0; ind_coords < temp_index_circles.size(); ind_coords++) {
                int ind_circle = temp_index_circles[ind_coords];

                if (arr_root_coords[ind_circle].x0 > arr_root_coords[ind_circle].new_x0) {
                    int temp_x = arr_root_coords[ind_circle].x0 - speed_x;

                    if (temp_x > arr_root_coords[ind_circle].new_x0) {
                        arr_root_coords[ind_circle].x0 = temp_x;
                    }

                    else {
                        arr_root_coords[ind_circle].x0 = arr_root_coords[ind_circle].new_x0;
                    }
                }

                else {
                    int temp_x = arr_root_coords[ind_circle].x0 + speed_x;

                    if (temp_x < arr_root_coords[ind_circle].new_x0) {
                        arr_root_coords[ind_circle].x0 = temp_x;
                    }

                    else {
                        arr_root_coords[ind_circle].x0 = arr_root_coords[ind_circle].new_x0;
                    }
                }


                if (arr_root_coords[ind_circle].y0 > arr_root_coords[ind_circle].new_y0) {
                    int temp_y = arr_root_coords[ind_circle].y0 - speed_y;

                    if (temp_y > arr_root_coords[ind_circle].new_y0) {
                        arr_root_coords[ind_circle].y0 = temp_y;
                    }

                    else {
                        arr_root_coords[ind_circle].y0 = arr_root_coords[ind_circle].new_y0;
                    }
                }

                else {
                    int temp_y = arr_root_coords[ind_circle].y0 + speed_y;

                    if (temp_y < arr_root_coords[ind_circle].new_y0) {
                        arr_root_coords[ind_circle].y0 = temp_y;
                    }

                    else {
                        arr_root_coords[ind_circle].y0 = arr_root_coords[ind_circle].new_y0;
                    }
                }
            }

            bool flag_2 = true;
            for (int ind_coords = 0; ind_coords < temp_index_circles.size(); ind_coords++) {
                int ind_circle = temp_index_circles[ind_coords];

                if (arr_root_coords[ind_circle].x0 != arr_root_coords[ind_circle].new_x0 ||
                    arr_root_coords[ind_circle].y0 != arr_root_coords[ind_circle].new_y0) {
                    flag_2 = false;
                    break;
                }
            }

            if (flag_2) {
                flag_1 = false;
            }


            Graph *new_graph = new Graph(graph);

            for (int ind_coords = 0; ind_coords < temp_index_circles.size(); ind_coords++) {
                int ind_circle = temp_index_circles[ind_coords];

                int x0 = arr_root_coords[ind_circle].x0;
                int y0 = arr_root_coords[ind_circle].y0;
                int r = arr_root_coords[ind_circle].r;

                new_graph->set_coords_circle(ind_circle, x0, y0, r);
                new_graph->set_visable_circle(ind_circle, true);
                new_graph->set_update_circle(ind_circle, true);
            }

            graph = new_graph;
            arr_animations.append(graph);
        }


        temp_index_circles.clear();
        temp_index_vectors.clear();
    }


    // Выставляем вектора на перестроенные вершины.
    for (int ind_groups = 0; ind_groups < arr_index_groups.size(); ind_groups++) {
        for (int ind_coords = 0; ind_coords < arr_root_coords.size(); ind_coords++) {
            if (arr_root_coords[ind_coords].number_group == ind_groups) {
                for (int ind_col = 0; ind_col < size; ind_col++) {
                    if (matrix[ind_coords][ind_col] !=0 && matrix[ind_coords][ind_col] != -1) {
                        Graph *new_graph = new Graph(graph);

                        int ind_vector = graph->get_index_vector(ind_coords, ind_col);

                        int x0 = arr_root_coords[ind_coords].x0;
                        int y0 = arr_root_coords[ind_coords].y0;
                        int x1 = arr_root_coords[ind_col].x0;
                        int y1 = arr_root_coords[ind_col].y0;

                        new_graph->set_coords_vector(ind_vector, x0, y0, x1, y1);
                        new_graph->set_visable_vector(ind_vector, true);
                        new_graph->set_update_vector(ind_vector, true);

                        graph = new_graph;
                        arr_animations.append(graph);
                    }
                }
            }
        }
    }
}


