#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainterPath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene.setSceneRect(-300,-300,600,600);
    QPainterPath path;
    path.addRect(-10,-10,20,20);
    //scene.setSelectionArea(path);
    QPainterPath path1;
    path.addRect(40,40,20,20);
    scene.setSelectionArea(path);
    ui->graphicsView->setScene(&scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}
