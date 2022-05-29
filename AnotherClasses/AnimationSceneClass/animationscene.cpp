
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
    delete datadialog;
    delete timer;
    delete graph;
}



void AnimationScene::resizeEvent(QResizeEvent *event) {

}



void AnimationScene::create_graphics_objects() {
    graph = new Graph();
    graph = static_cast<Graph*>(arr_animations[0]);

    for (int ind = 0; ind < graph->get_count_circles(); ind++) {
        Circle *circle = new Circle();

        circle->setVisible(false);
        arr_circles.append(circle);
    }

    for (int ind = 0; ind < graph->get_count_vectors(); ind++) {
        Vector *vector = new Vector();

        vector->setVisible(false);
        arr_vectors.append(vector);
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


    for (int ind = 0; ind < arr_vectors.size(); ind++) {
        scene->addItem(arr_vectors[ind]);
    }


    for (int ind = 0; ind < arr_labels.size(); ind++) {
        scene->addItem(arr_labels[ind]);
    }


    timer->start(800);
}


void AnimationScene::set_graphics_objects() {
//    animation_scene_number = arr_animations.size() - 1;
    graph = static_cast<Graph*>(arr_animations[animation_scene_number]);

    for (int ind_circle = 0; ind_circle < arr_circles.size(); ind_circle++) {
        bool update = false;
        graph->get_update_circle(ind_circle, update);

        if (update) {
            int x0, y0, r, number;
            bool visable;
            QColor color_circle;
            QPen style_number, style_circle;

            graph->get_coords_circle(ind_circle, x0, y0, r);
            graph->get_value_circle(ind_circle, number, style_number);
            graph->get_visable_circle(ind_circle, visable);
            graph->get_style_circle(ind_circle, color_circle, style_circle);

            arr_circles[ind_circle]->set_coords_circle(x0, y0, r);
            arr_circles[ind_circle]->set_number_circle(number);
            arr_circles[ind_circle]->set_style_circle(color_circle);
            arr_circles[ind_circle]->setVisible(visable);

            scene->update();
        }
    }


    for (int ind_vector = 0; ind_vector < arr_vectors.size(); ind_vector++) {
        bool update = false;
        graph->get_update_vector(ind_vector, update);

        if (update) {
            int x0, y0, x1, y1, value_1, value_2;
            bool visable;
            QPen style_vector;

            graph->get_coords_vector(ind_vector, x0, y0, x1, y1);
            graph->get_values_vector(ind_vector, value_1, value_2);
            graph->get_visable_vector(ind_vector, visable);
            graph->get_style_vector(ind_vector, style_vector);

            arr_vectors[ind_vector]->set_coords_vector(x0, y0, x1, y1, 25);
            arr_vectors[ind_vector]->set_value_vector(value_1);
            arr_vectors[ind_vector]->set_style_vector(style_vector);
            arr_vectors[ind_vector]->setVisible(visable);

            scene->update();
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

