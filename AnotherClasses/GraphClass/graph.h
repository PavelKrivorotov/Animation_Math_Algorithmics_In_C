#ifndef GRAPH_H
#define GRAPH_H

#include <QColor>
#include <QPen>


struct struct_circle {
    int         number_circle;

    int         x0, y0, r;

    int         count_input_vectors;
    int         count_output_vectors;

    bool        visable;
    bool        update;

    int         value;
    QPen        style_value;

    QColor      background;
    QPen        outline;
};

struct struct_vector {
    int         move_from_number;
    int         move_to_number;

    int         x0, y0, x1, y1;

    bool        visable;
    bool        update;

    int         value_1, value_2;

    QPen        style;
};

struct struct_label {
    int         number_label;

    int         x0, y0;

    QList<int>  values;

    bool        visable;
    bool        update;
    bool        constant;
};


class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph();
    explicit Graph(Graph *graph);
    ~Graph();

public:
    // Node functions
    void append_new_circle(int num_circle);


    void get_coords_circle(int num_circle, int &x0, int &y0, int &r);

    void get_visable_circle(int num_circle, bool &visable);

    void get_update_circle(int num_circle, bool &update);

    void get_value_circle(int num_circle, int &value, QPen &style);

    void get_style_circle(int num_circle, QColor &background, QPen &style);

    int  get_index_circle(int num_circle);

    int  get_count_circles();


    void set_coords_circle(int num_circle, int x0, int y0, int r);

    void set_visable_circle(int num_circle, bool visable);

    void set_update_circle(int num_circle, bool update);

    void set_value_circle(int num_circle, int value, QPen style);

    void set_style_circle(int num_circle, QColor background, QPen style);


    // Vector functions
    void append_new_vector(int move_from_number, int move_to_number);


    void get_coords_vector(int ind_vector, int &x0, int &y0, int &x1, int &y1);

    void get_coords_vector(int move_from_number, int move_to_number, int &x0, int &y0, int &x1, int &y1);

    void get_visable_vector(int ind_vector, bool &visable);

    void get_visable_vector(int move_from_number, int move_to_number, bool &visable);

    void get_update_vector(int ind_vector, bool &update);

    void get_update_vector(int move_from_number, int move_to_number, bool &update);

    void get_values_vector(int ind_vector, int &value_1, int &value_2);

    void get_values_vector(int move_from_number, int move_to_number, int &value_1, int &value_2);

    void get_style_vector(int ind_vector, QPen &style);

    void get_style_vector(int move_from_number, int move_to_number, QPen &style);

    int  get_index_vector(int move_from_number, int move_to_number);

    int  get_count_vectors();


    void set_coords_vector(int ind_vector, int x0, int y0, int x1, int y1);

    void set_coords_vector(int move_from_number, int move_to_number, int x0, int y0, int x1, int y1);

    void set_visable_vector(int ind_vector, bool visable);

    void set_visable_vector(int move_from_number, int move_to_number, bool visable);

    void set_update_vector(int ind_vector, bool update);

    void set_update_vector(int move_from_number, int move_to_number, bool update);

    void set_values_vector(int ind_vector, int value_1, int value_2);

    void set_values_vector(int move_from_number, int move_to_number, int value_1, int value_2);

    void set_style_vector(int ind_vector, QPen style);

    void set_style_vector(int move_from_number, int move_to_number, QPen style);


    // Label functions
    void append_new_label(int num_label);


    void get_coords_label(int num_label, int &x0, int &y0);

    void get_values_label(int num_label, QList<int> &values);

    void get_visable_label(int num_label, bool &visable);

    void get_update_label(int num_label, bool &update);

    void get_constant_label(int num_label, bool &constant);

    int  get_index_label(int num_label);

    int  get_count_labels();


    void set_coords_label(int num_label, int x0, int y0);

    void set_value_label(int num_label, int value);

    void set_visable_label(int num_label, bool visable);

    void set_update_label(int num_label, bool update);

    void set_constant_label(int num_label, bool constant);

private:
    QList<struct_circle>            arr_circles;
    QList<struct_vector>            arr_vectors;
    QList<struct_label>             arr_labels;
    QStringList                     arr_text;
};

#endif // GRAPH_H
