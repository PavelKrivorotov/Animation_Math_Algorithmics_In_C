#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "AnotherClasses/SplashClass/splashwindow.h"
#include "AnotherClasses/AnimationSceneClass/animationscene.h"

#include <QMainWindow>
#include <QTimer>


// Indexes of Windows
#define SPLASCH_WINDOW_INDEX         0
#define ANIMATION_WINDOW_INDEX       1


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void set_page_show(int page_index);

    void set_enabled_button(QAction *action, bool enabled);

    void set_previous_button(QAction *previous);

    void set_window_title(QString title);

    void set_all_window_settings(QAction *action, int page_index, QString title);

    void set_new_window_settings(QAction *active, int page_index, QString title);


    void on_actionBack_to_Root_window_triggered();

    void on_action_Isomorphic_animation_triggered();

    void on_action_Dijkstra_animation_triggered();

    void on_action_BelmanMore_animation_triggered();

    void on_action_MaximumPath_animation_triggered();

    void on_actionSettings_triggered();

    void on_actionAuthor_triggered();

    void on_actionAbout_triggered();

signals:
    void show_datadialog(int ind);

public slots:
    void show_completed_clicked();

private:
    QStringList title_of_windows;
    QString     new_title;

    int new_page_index;

private:
    Ui::MainWindow  *ui;
    QAction         *previous_button, *active_button;

    Splash          *splash_window;
    AnimationScene  *animation_window;
};


#endif // MAINWINDOW_H
