
#include "graph.h"

Graph::Graph(QList<QList<int>> matrix)
{
    struct_circle circle;
    arr_circles.fill(circle, matrix.size());

    for (int ind_1 = 0; ind_1 < matrix.size(); ind_1++) {
        QList<struct_vector> vectors;

        for (int ind_2 = 0; ind_2 < matrix.size(); ind_2++) {
            if (matrix[ind_1][ind_2] != 0 && matrix[ind_1][ind_2] != -1) {
                struct_vector vector;
                vectors.append(vector);
            }
        }

        arr_vectors.append(vectors);
    }

    struct_label label;
    arr_labels.fill(label, matrix.size());
}


Graph::Graph(Graph *graph)
{
    arr_circles = graph->arr_circles;
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        arr_circles[ind].update = false;
    }

    arr_vectors = graph->arr_vectors;
    for (int ind_1 = 0; ind_1 < arr_vectors.size(); ind_1++) {
        for (int ind_2 = 0; ind_2 < arr_vectors[ind_1].size(); ind_2++) {
            arr_vectors[ind_1][ind_2].update = false;
        }
    }

    arr_labels = graph->arr_labels;
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        arr_labels[ind].update = false;
    }

    arr_text = graph->arr_text;
}


Graph::~Graph()
{

}



// Circle statments

void Graph::get_coords_circle(int index, int &x0, int &y0, int &r) {
    x0 = arr_circles[index].x0;
    y0 = arr_circles[index].y0;
    r = arr_circles[index].r;
}


void Graph::get_visable_circle(int index, bool &visable) {
    visable = arr_circles[index].visable;
}


void Graph::get_update_circle(int index, bool &update) {
    update = arr_circles[index].update;
}


void Graph::get_number_circle(int index, int &number, QPen &style) {
    number = arr_circles[index].number;
    style = arr_circles[index].style_value;
}


void Graph::get_style_circle(int index, QColor &background, QPen &style) {
    background = arr_circles[index].background;
    style = arr_circles[index].outline;
}



void Graph::set_coords_circle(int index, int x0, int y0, int r) {
    arr_circles[index].x0 = x0;
    arr_circles[index].y0 = y0;
    arr_circles[index].r = r;
}


void Graph::set_visable_circle(int index, bool visable) {
    arr_circles[index].visable = visable;
}


void Graph::set_update_circle(int index, bool update) {
    arr_circles[index].update = update;
}


void Graph::set_number_circle(int index, int number, QPen style_number) {
    arr_circles[index].number = number;
    arr_circles[index].style_value = style_number;
}


void Graph::set_style_circle(int index, QColor background, QPen style) {
    arr_circles[index].background = background;
    arr_circles[index].outline = style;
}


int Graph::get_count_nodes() {
    return arr_circles.count();
}



// Vector statments

void Graph::get_coords_vector(int ind_row, int ind_col, int &x0, int &y0, int &x1, int &y1, int &move_to_index) {
    x0 = arr_vectors[ind_row][ind_col].x0;
    y0 = arr_vectors[ind_row][ind_col].y0;
    x1 = arr_vectors[ind_row][ind_col].x1;
    y1 = arr_vectors[ind_row][ind_col].y1;
    move_to_index = arr_vectors[ind_row][ind_col].move_to_index;
}


void Graph::get_visable_vector(int ind_row, int ind_col, bool &visable) {
    visable = arr_vectors[ind_row][ind_col].visable;
}


void Graph::get_update_vector(int ind_row, int ind_col, bool &update) {
    update = arr_vectors[ind_row][ind_col].update;
}


void Graph::get_values_vector(int ind_row, int ind_col, int &value_1, int &value_2) {
    value_1 = arr_vectors[ind_row][ind_col].value_1;
    value_2 = arr_vectors[ind_row][ind_col].value_2;
}


void Graph::get_style_vector(int ind_row, int ind_col, QPen &style) {
    style = arr_vectors[ind_row][ind_col].style;
}



void Graph::set_coords_vector(int ind_row, int ind_col, int x0, int y0, int x1, int y1, int move_to_index) {
    arr_vectors[ind_row][ind_col].x0 = x0;
    arr_vectors[ind_row][ind_col].y0 = y0;
    arr_vectors[ind_row][ind_col].x1 = x1;
    arr_vectors[ind_row][ind_col].y1 = y1;
    arr_vectors[ind_row][ind_col].move_to_index = move_to_index;
}


void Graph::set_move_coords_vector(int index, int move_to_index, int x0, int y0, int x1, int y1) {
    for (int ind = 0; ind < arr_vectors[index].size(); ind++) {
        if (arr_vectors[index][ind].move_to_index == move_to_index) {
            arr_vectors[index][ind].x0 = x0;
            arr_vectors[index][ind].y0 = y0;
            arr_vectors[index][ind].x1 = x1;
            arr_vectors[index][ind].y1 = y1;
            break;
        }
    }
}


void Graph::set_visable_vector(int ind_row, int ind_col, bool visable) {
    arr_vectors[ind_row][ind_col].visable = visable;
}


void Graph::set_move_visable_vector(int index, int move_to_index, bool visable) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[index][ind].move_to_index == move_to_index) {
            arr_vectors[index][ind].visable = visable;
            break;
        }
    }
}


void Graph::set_update_vector(int ind_row, int ind_col, bool update) {
    arr_vectors[ind_row][ind_col].update = update;
}


void Graph::set_move_update_vector(int index, int move_to_index, bool update) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[index][ind].move_to_index == move_to_index) {
            arr_vectors[index][ind].update = update;
            break;
        }
    }
}


void Graph::set_values_vector(int ind_row, int ind_col, int value_1, int value_2) {
    arr_vectors[ind_row][ind_col].value_1 = value_1;
    arr_vectors[ind_row][ind_col].value_2 = value_2;
}


void Graph::set_move_values_vector(int index, int move_to_index, int value_1, int value_2) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[index][ind].move_to_index == move_to_index) {
            arr_vectors[index][ind].value_1 = value_1;
            arr_vectors[index][ind].value_2 = value_2;
            break;
        }
    }
}


void Graph::set_style_vector(int ind_row, int ind_col, QPen style) {
    arr_vectors[ind_row][ind_col].style = style;
}


void Graph::set_move_style_vector(int index, int move_to_index, QPen style) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[index][ind].move_to_index == move_to_index) {
            arr_vectors[index][ind].style = style;
        }
    }
}


QList<int> Graph::get_count_vectors() {
    QList<int> count_vectors;

    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].size() != 0) {
            count_vectors.append(arr_vectors[ind].size());
        }
    }

    return count_vectors;
}



// Label statments

void Graph::get_coords_label(int index, int &x0, int &y0) {
    x0 = arr_labels[index].x0;
    y0 = arr_labels[index].y0;
}


void Graph::get_values_label(int index, QList<int> &values) {
    values = arr_labels[index].values;
}


void Graph::get_visable_label(int index, bool &visable) {
    visable = arr_labels[index].visable;
}


void Graph::get_update_label(int index, bool &update) {
    update = arr_labels[index].update;
}


void Graph::get_constant_label(int index, bool &constant) {
    constant = arr_labels[index].constant;
}



void Graph::set_coords_label(int index, int x0, int y0) {
    arr_labels[index].x0 = x0;
    arr_labels[index].y0 = y0;
}


void Graph::set_value_label(int index, int value) {
    arr_labels[index].values.append(value);
}


void Graph::set_visable_label(int index, bool visable) {
    arr_labels[index].visable = visable;
}


void Graph::set_update_label(int index, bool update) {
    arr_labels[index].update = update;
}


void Graph::set_constant_label(int index, bool constant) {
    arr_labels[index].constant = constant;
}


int Graph::get_count_labels() {
    return arr_labels.size();
}
