
#include "splashwindow.h"

//#include <iostream>
//using namespace std;


Splash::Splash(QWidget *parent)
    : QOpenGLWidget(parent)
{

}


void Splash::initializeGL() {
    initializeOpenGLFunctions();
    glClearColor(0.0f, 1.0f, 0.0f, 1.0f);

//    cout << "first" << endl;
}


void Splash::paintGL() {
//    cout << "threed" << endl;
}


void Splash::resizeGL(int w, int h) {
//    cout << "second" << endl;
}


