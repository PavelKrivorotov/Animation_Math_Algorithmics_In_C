#ifndef SPLASH_H
#define SPLASH_H

#include <QWidget>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class Splash : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    Splash(QWidget *parent = nullptr);

protected:
    void initializeGL() override;

    void paintGL() override;

    void resizeGL(int w, int h) override;
};

#endif // SPLASH_H
