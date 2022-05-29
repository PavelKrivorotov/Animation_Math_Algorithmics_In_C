
#include "graph.h"

Graph::Graph()
{

}


Graph::Graph(Graph *graph)
{
    arr_circles = graph->arr_circles;
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        arr_circles[ind].update = false;
    }

    arr_vectors = graph->arr_vectors;
    for (int ind_1 = 0; ind_1 < arr_vectors.size(); ind_1++) {
        arr_vectors[ind_1].update = false;
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

void Graph::append_new_circle(int num_circle) {
    struct_circle circle;
    circle.number_circle = num_circle;

    arr_circles.append(circle);
}



void Graph::get_coords_circle(int num_circle, int &x0, int &y0, int &r) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            x0 = arr_circles[ind].x0;
            y0 = arr_circles[ind].y0;
            r = arr_circles[ind].r;
            break;
        }
    }
}


void Graph::get_visable_circle(int num_circle, bool &visable) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            visable = arr_circles[ind].visable;
            break;
        }
    }
}


void Graph::get_update_circle(int num_circle, bool &update) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            update = arr_circles[ind].update;
            break;
        }
    }
}


void Graph::get_value_circle(int num_circle, int &value, QPen &style) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            value = arr_circles[ind].value;
            style = arr_circles[ind].style_value;
            break;
        }
    }
}


void Graph::get_style_circle(int num_circle, QColor &background, QPen &style) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            background = arr_circles[ind].background;
            style = arr_circles[ind].outline;
        }
    }
}


int Graph::get_index_circle(int num_circle) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            return ind;
        }
    }

    return -1;
}


int  Graph::get_count_circles() {
    return arr_circles.size();
}



void Graph::set_coords_circle(int num_circle, int x0, int y0, int r) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            arr_circles[ind].x0 = x0;
            arr_circles[ind].y0 = y0;
            arr_circles[ind].r = r;
            break;
        }
    }
}


void Graph::set_visable_circle(int num_circle, bool visable) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            arr_circles[ind].visable = visable;
            break;
        }
    }
}


void Graph::set_update_circle(int num_circle, bool update) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            arr_circles[ind].update = update;
            break;
        }
    }
}


void Graph::set_value_circle(int num_circle, int value, QPen style_number) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            arr_circles[ind].value = value;
            arr_circles[ind].style_value = style_number;
            break;
        }
    }
}


void Graph::set_style_circle(int num_circle, QColor background, QPen style) {
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        if (arr_circles[ind].number_circle == num_circle) {
            arr_circles[ind].background = background;
            arr_circles[ind].outline = style;
            break;
        }
    }
}



// Vector statments

void Graph::append_new_vector(int move_from_number, int move_to_number) {
    struct_vector vector;
    vector.move_from_number = move_from_number;
    vector.move_to_number = move_to_number;

    arr_vectors.append(vector);
}



void Graph::get_coords_vector(int ind_vector, int &x0, int &y0, int &x1, int &y1) {
    x0 = arr_vectors[ind_vector].x0;
    y0 = arr_vectors[ind_vector].y0;
    x1 = arr_vectors[ind_vector].x1;
    y1 = arr_vectors[ind_vector].y1;
}


void Graph::get_coords_vector(int move_from_number, int move_to_number, int &x0, int &y0, int &x1, int &y1) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            x0 = arr_vectors[ind].x0;
            y0 = arr_vectors[ind].y0;
            x1 = arr_vectors[ind].x1;
            y1 = arr_vectors[ind].y1;
        }
    }
}


void Graph::get_visable_vector(int ind_vector, bool &visable) {
    visable = arr_vectors[ind_vector].visable;
}


void Graph::get_visable_vector(int move_from_number, int move_to_number, bool &visable) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            visable = arr_vectors[ind].visable;
        }
    }
}


void Graph::get_update_vector(int ind_vector, bool &update) {
    update = arr_vectors[ind_vector].update;
}


void Graph::get_update_vector(int move_from_number, int move_to_number, bool &update) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            update = arr_vectors[ind].update;
        }
    }
}


void Graph::get_values_vector(int ind_vector, int &value_1, int &value_2) {
    value_1 = arr_vectors[ind_vector].value_1;
    value_2 = arr_vectors[ind_vector].value_2;
}


void Graph::get_values_vector(int move_from_number, int move_to_number, int &value_1, int &value_2) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            value_1 = arr_vectors[ind].value_1;
            value_2 = arr_vectors[ind].value_2;
        }
    }
}


void Graph::get_style_vector(int ind_vector, QPen &style) {
    style = arr_vectors[ind_vector].style;
}


void Graph::get_style_vector(int move_from_number, int move_to_number, QPen &style) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            style = arr_vectors[ind].style;
        }
    }
}


int  Graph::get_index_vector(int move_from_number, int move_to_number) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            return ind;
        }
    }

    return -1;
}


int  Graph::get_count_vectors() {
    return arr_vectors.size();
}



void Graph::set_coords_vector(int ind_vector, int x0, int y0, int x1, int y1) {
    arr_vectors[ind_vector].x0 = x0;;
    arr_vectors[ind_vector].y0 = y0;
    arr_vectors[ind_vector].x1 = x1;
    arr_vectors[ind_vector].y1 = y1;
}


void Graph::set_coords_vector(int move_from_number, int move_to_number, int x0, int y0, int x1, int y1) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            arr_vectors[ind].x0 = x0;
            arr_vectors[ind].y0 = y0;
            arr_vectors[ind].x1 = x1;
            arr_vectors[ind].y1 = y1;
        }
    }
}


void Graph::set_visable_vector(int ind_vector, bool visable) {
    arr_vectors[ind_vector].visable = visable;
}


void Graph::set_visable_vector(int move_from_number, int move_to_number, bool visable) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            arr_vectors[ind].visable = visable;
        }
    }
}


void Graph::set_update_vector(int ind_vector, bool update) {
    arr_vectors[ind_vector].update = update;
}


void Graph::set_update_vector(int move_from_number, int move_to_number, bool update) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            arr_vectors[ind].update = update;
        }
    }
}


void Graph::set_values_vector(int ind_vector, int value_1, int value_2) {
    arr_vectors[ind_vector].value_1 = value_1;
    arr_vectors[ind_vector].value_2 = value_2;
}


void Graph::set_values_vector(int move_from_number, int move_to_number, int value_1, int value_2) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            arr_vectors[ind].value_1 = value_1;
            arr_vectors[ind].value_2 = value_2;
        }
    }
}


void Graph::set_style_vector(int ind_vector, QPen style) {
    arr_vectors[ind_vector].style = style;
}


void Graph::set_style_vector(int move_from_number, int move_to_number, QPen style) {
    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        if (arr_vectors[ind].move_from_number == move_from_number && arr_vectors[ind].move_to_number == move_to_number) {
            arr_vectors[ind].style = style;
        }
    }
}



// Label statments

void Graph::append_new_label(int num_label) {
    struct_label label;
    label.number_label = num_label;

    arr_labels.append(label);
}



void Graph::get_coords_label(int num_label, int &x0, int &y0) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            x0 = arr_labels[ind].x0;
            y0 = arr_labels[ind].y0;
            break;
        }
    }
}


void Graph::get_values_label(int num_label, QList<int> &values) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            values = arr_labels[ind].values;
            break;
        }
    }
}


void Graph::get_visable_label(int num_label, bool &visable) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            visable = arr_labels[ind].visable;
            break;
        }
    }
}


void Graph::get_update_label(int num_label, bool &update) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            update = arr_labels[ind].update;
            break;
        }
    }
}


void Graph::get_constant_label(int num_label, bool &constant) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            constant = arr_labels[ind].constant;
            break;
        }
    }
}


int  Graph::get_index_label(int num_label) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            return ind;
        }
    }

    return -1;
}


int  Graph::get_count_labels() {
    return arr_labels.size();
}



void Graph::set_coords_label(int num_label, int x0, int y0) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            arr_labels[ind].x0 = x0;
            arr_labels[ind].y0 = y0;
            break;
        }
    }
}


void Graph::set_value_label(int num_label, int value) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            arr_labels[ind].values.append(value);
            break;
        }
    }
}


void Graph::set_visable_label(int num_label, bool visable) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            arr_labels[ind].visable = visable;
            break;
        }
    }
}


void Graph::set_update_label(int num_label, bool update) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            arr_labels[ind].update = update;
            break;
        }
    }
}


void Graph::set_constant_label(int num_label, bool constant) {
    for (int ind = 0; ind < arr_labels.size(); ind++) {
        if (arr_labels[ind].number_label == num_label) {
            arr_labels[ind].constant = constant;
            break;
        }
    }
}

