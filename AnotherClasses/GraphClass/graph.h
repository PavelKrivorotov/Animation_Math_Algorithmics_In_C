#ifndef GRAPH_H
#define GRAPH_H

#include <QColor>
#include <QPen>


struct struct_circle {
    int         x0;
    int         y0;
    int         r;

    bool        visable;
    bool        update;

    int         number;
    QPen        style_value;

    QColor      background;
    QPen        outline;
};

struct struct_vector {
    int         x0;
    int         y0;
    int         x1;
    int         y1;
    int         move_to_index;

    bool        visable;
    bool        update;

    int         value_1;
    int         value_2;

    QPen        style;
};

struct struct_label {
    int         x0;
    int         y0;
    QList<int>  values;

    bool        visable;
    bool        update;
    bool        constant;
};


class Graph : public QObject
{
    Q_OBJECT
public:
    explicit Graph(QList<QList<int>> matrix);
    explicit Graph(Graph *graph);
    ~Graph();

public:
    // Node functions
    void get_coords_circle(int index, int &x0, int &y0, int &r);

    void get_visable_circle(int index, bool &visable);

    void get_update_circle(int index, bool &update);

    void get_number_circle(int index, int &number, QPen &style);

    void get_style_circle(int index, QColor &background, QPen &style);

    int  get_count_nodes();


    void set_coords_circle(int index, int x0, int y0, int r);

    void set_visable_circle(int index, bool visable);

    void set_update_circle(int index, bool update);

    void set_number_circle(int index, int number, QPen style);

    void set_style_circle(int index, QColor background, QPen style);


    // Vector functions
    void get_coords_vector(int ind_row, int ind_col, int &x0, int &y0, int &x1, int &y1, int &move_to_index);

    void get_visable_vector(int ind_row, int ind_col, bool &visable);

    void get_update_vector(int ind_row, int ind_col, bool &update);

    void get_values_vector(int ind_row, int ind_col, int &value_1, int &value_2);

    void get_style_vector(int ind_row, int ind_col, QPen &style);

    QList<int> get_count_vectors();


    void set_coords_vector(int ind_row, int ind_col, int x0, int y0, int x1, int y1, int move_to_index);

    void set_visable_vector(int ind_row, int ind_col, bool visable);

    void set_update_vector(int ind_row, int ind_col, bool update);

    void set_values_vector(int ind_row, int ind_col, int value_1, int value_2);

    void set_style_vector(int ind_row, int ind_col, QPen style);


    void set_move_coords_vector(int index, int move_to_index, int x0, int y0, int x1, int y1);

    void set_move_visable_vector(int index, int move_to_index, bool visable);

    void set_move_update_vector(int index, int move_to_index, bool update);

    void set_move_values_vector(int index, int move_to_index, int value_1, int value_2);

    void set_move_style_vector(int index, int move_to_index, QPen style);


    // Label functions
    void get_coords_label(int index, int &x0, int &y0);

    void get_values_label(int index, QList<int> &values);

    void get_visable_label(int index, bool &visable);

    void get_update_label(int index, bool &update);

    void get_constant_label(int index, bool &constant);

    int  get_count_labels();


    void set_coords_label(int index, int x0, int y0);

    void set_value_label(int index, int value);

    void set_visable_label(int index, bool visable);

    void set_update_label(int index, bool update);

    void set_constant_label(int index, bool constant);

private:
    QList<struct_circle>            arr_circles;
    QList<QList<struct_vector>>     arr_vectors;
    QList<struct_label>             arr_labels;
    QStringList                     arr_text;
};

#endif // GRAPH_H
