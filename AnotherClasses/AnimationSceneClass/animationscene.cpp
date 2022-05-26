
#include "animationscene.h"

#include <iostream>
using namespace std;

AnimationScene::AnimationScene(QWidget *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(-200, -200, 400, 400);
    this->setScene(scene);

    datadialog = new DataDialog();
    connect(datadialog, &DataDialog::ok_clicked, this, &AnimationScene::ok_cliced);

    timer = new QTimer();
    connect(timer, &QTimer::timeout, this, &AnimationScene::set_graphics_objects);

    animation_scene_number = 0;

    isomorphic = nullptr;
}


AnimationScene::~AnimationScene()
{
    delete scene;
}



void AnimationScene::resizeEvent(QResizeEvent *event) {

}



void AnimationScene::create_graphics_objects() {
    graph = new Graph(matrix);
    graph = static_cast<Graph*>(arr_animations[0]);

    for (int ind = 0; ind < graph->get_count_nodes(); ind++) {
        Circle *circle = new Circle();
        circle->setVisible(false);
        arr_circles.append(circle);
    }

    for (int ind = 0; ind < graph->get_count_vectors().size(); ind++) {
        QList<Vector*> vectors;

        int count = 0;
        while (count < graph->get_count_vectors()[ind]) {
            Vector *vector = new Vector();
            vector->setVisible(false);
            vectors.append(vector);

            count = count + 1;
        }

        arr_vectors.append(vectors);
    }


    for (int ind = 0; ind < graph->get_count_labels(); ind++) {
        Label *label = new Label;
        label->setVisible(false);
        arr_labels.append(label);
    }


    // Add objects to scene;
    for (int ind = 0; ind < arr_circles.size(); ind++) {
        scene->addItem(arr_circles[ind]);
    }


    for (int ind_1 = 0; ind_1 < arr_vectors.size(); ind_1++) {
        for (int ind_2 = 0; ind_2 < arr_vectors[ind_1].size(); ind_2++) {
            scene->addItem(arr_vectors[ind_1][ind_2]);
        }
    }


    timer->start(800);
}


void AnimationScene::set_graphics_objects() {
//    animation_scene_number = arr_animations.size() - 1;
    graph = static_cast<Graph*>(arr_animations[animation_scene_number]);

    for (int ind = 0; ind < arr_circles.size(); ind++) {
        bool update;
        graph->get_update_circle(ind, update);

        if (update) {
            int x0, y0, r, number;
            bool visable;
            QColor color_circle;
            QPen style_number, style_circle;

            graph->get_coords_circle(ind, x0, y0, r);
            graph->get_number_circle(ind, number, style_number);
            graph->get_visable_circle(ind, visable);
            graph->get_style_circle(ind, color_circle, style_circle);

            arr_circles[ind]->set_coords_circle(x0, y0, r);
            arr_circles[ind]->set_number_circle(number);
            arr_circles[ind]->set_style_circle(color_circle);
            arr_circles[ind]->setVisible(visable);

            scene->update();
        }
    }


    for (int ind_1 = 0; ind_1 < arr_vectors.size(); ind_1++) {
        for (int ind_2 = 0; ind_2 < arr_vectors[ind_1].size(); ind_2++) {
            bool update;
            graph->get_update_vector(ind_1, ind_2, update);

            if (update) {
                int x0, y0, x1, y1, move_to_index, value_1, value_2;
                bool visable;
                QPen style_vector;

                graph->get_coords_vector(ind_1, ind_2, x0, y0, x1, y1, move_to_index);
                graph->get_values_vector(ind_1, ind_2, value_1, value_2);
                graph->get_visable_vector(ind_1, ind_2, visable);
                graph->get_style_vector(ind_1, ind_2, style_vector);

                arr_vectors[ind_1][ind_2]->set_coords_vector(x0, y0, x1, y1, 25);
                arr_vectors[ind_1][ind_2]->set_value_vector(value_1);
                arr_vectors[ind_1][ind_2]->set_style_vector(style_vector);
                arr_vectors[ind_1][ind_2]->setVisible(visable);

                scene->update();
            }
        }
    }


    animation_scene_number = animation_scene_number + 1;
    if (animation_scene_number == arr_animations.size()) {
        timer->stop();
    }
}


void AnimationScene::show_datadialog(int ind) {
    datadialog->show();
    index_algorithm = ind;
}


void AnimationScene::ok_cliced() {
    show_completed_cliced();

    datadialog->get_matrix(matrix);

    switch (index_algorithm) {
        case 0: {
            isomorphic = new Isomorphic(matrix);
            arr_animations = isomorphic->get_arr_animations();
        }
    }

    create_graphics_objects();
    set_graphics_objects();
}

