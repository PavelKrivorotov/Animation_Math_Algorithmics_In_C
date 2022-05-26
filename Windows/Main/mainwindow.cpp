
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
using namespace std;


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    splash_window = new Splash();
    animation_window = new AnimationScene();

    ui->stackedWidget->addWidget(splash_window);
    ui->stackedWidget->addWidget(animation_window);


    connect(this, &MainWindow::show_datadialog, animation_window, &AnimationScene::show_datadialog);
    connect(animation_window, &AnimationScene::show_completed_cliced, this, &MainWindow::show_completed_clicked);


    set_previous_button(ui->actionBack_to_Root_window);

    title_of_windows = {
        "Demonstration of Math Algorithmics",
        "The `Isomorphic` graph creating",
        "The `Dijkstra` algorithmics",
        "The `BelmanMore` algorithmics",
        "The `MaximumPath` algorithmics"
    };
}

MainWindow::~MainWindow()
{
    delete ui;
}


// ...

void MainWindow::set_page_show(int page_index) {
    ui->stackedWidget->setCurrentIndex(page_index);
}


void MainWindow::set_enabled_button(QAction *action, bool enabled) {
    action->setEnabled(enabled);
}


void MainWindow::set_previous_button(QAction *previous) {
    previous_button = previous;
}


void MainWindow::set_window_title(QString title) {
    this->setWindowTitle(title);
}


void MainWindow::set_all_window_settings(QAction *action, int page_index, QString title) {
    // Set window title
    set_window_title(title);

    // Set window and disabled this button
    set_page_show(page_index);
    set_enabled_button(action, false);

    // Set acivate previous button page
    set_enabled_button(previous_button, true);

    // Set previous button
    set_previous_button(action);
}


void MainWindow::set_new_window_settings(QAction *active, int page_index, QString title) {
    active_button   = active;
    new_page_index  = page_index;
    new_title       = title;
}



// Managers functions (Back_to_Root/Back_one ...)

void MainWindow::on_actionBack_to_Root_window_triggered()
{
    set_all_window_settings(ui->actionBack_to_Root_window, SPLASCH_WINDOW_INDEX, title_of_windows[0]);
}



// Algorithmics functions (Show animation/calculation ...)

void MainWindow::on_action_Isomorphic_animation_triggered()
{
    show_datadialog(0);
    set_new_window_settings(ui->action_Isomorphic_animation, ANIMATION_WINDOW_INDEX, title_of_windows[1]);
}


void MainWindow::on_action_Dijkstra_animation_triggered()
{
    show_datadialog(1);
    set_new_window_settings(ui->action_Dijkstra_animation, ANIMATION_WINDOW_INDEX, title_of_windows[2]);
}


void MainWindow::on_action_BelmanMore_animation_triggered()
{
    show_datadialog(2);
    set_new_window_settings(ui->action_BelmanMore_animation, ANIMATION_WINDOW_INDEX, title_of_windows[3]);
}


void MainWindow::on_action_MaximumPath_animation_triggered()
{
    show_datadialog(3);
    set_new_window_settings(ui->action_MaximumPath_animation, ANIMATION_WINDOW_INDEX, title_of_windows[4]);
}



// Other functions (Settings/Author/About ...)

void MainWindow::on_actionSettings_triggered()
{
    set_all_window_settings(ui->actionSettings, SPLASCH_WINDOW_INDEX, "Settings");
}


void MainWindow::on_actionAuthor_triggered()
{
    set_all_window_settings(ui->actionAuthor, SPLASCH_WINDOW_INDEX, "About Author");
}


void MainWindow::on_actionAbout_triggered()
{
    set_all_window_settings(ui->actionAbout, SPLASCH_WINDOW_INDEX, "About Program");
}



// ...

void MainWindow::show_completed_clicked() {
    cout << "Button 'Ok' clicked" << endl;

    set_all_window_settings(active_button, new_page_index, new_title);
}

