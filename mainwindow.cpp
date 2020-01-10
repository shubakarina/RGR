#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <math.h>

#define PI 3.14159265

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int n = 500;
    double A = 20;
    double B = 30;
    double delta = PI / 2;
    double a = 1;
    double b = 2;


    QVector<double> x(n), y(n);
    for (int i=0; i<n; ++i)
    {
      x[i] = A * sin(a * i + delta);
      y[i] = B * sin(b * i);
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-30, 30);
    ui->customPlot->yAxis->setRange(-30, 30);
    ui->customPlot->replot();
}

MainWindow::~MainWindow()
{
    delete ui;
}

