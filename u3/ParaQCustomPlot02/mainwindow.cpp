#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setGeometry(400, 200, 800, 600);
    setupDemo(0);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::setupQuadraticDemo(QCustomPlot *customPlot)
{
  demoName = "Quadratic Demo";
  // generate some data:
  QVector<double> x(101), y(101); // initialize with entries 0..100
  //QVector<double> x(201), y(201); // initialize with entries 0..200
  for (int i=0; i<101; ++i)
  //for (int i=0; i<201; ++i)
  {
    x[i] = i/50.0 - 1; // x goes from -1 to 1
    //x[i] = i/100.0 - 1; // x goes from -1 to 1
    y[i] = x[i]*x[i];  // let's plot a quadratic function
    //y[i] = x[i] >= 0 ? x[i]*x[i] : -x[i]*x[i];  // let's plot a quadratic function
    //y[i] = sin(16*x[i]);
    //y[i] = exp(-x[i]/0.2)*sin(16*x[i]);
  }
  // create graph and assign data to it:
  customPlot->addGraph();
  customPlot->graph(0)->setData(x, y);
  // give the axes some labels:
  customPlot->xAxis->setLabel("x");
  customPlot->yAxis->setLabel("y");
  // set axes ranges, so we see all data:
  customPlot->xAxis->setRange(-1, 1);
  //customPlot->xAxis->setRange(-2, 2);
  //customPlot->xAxis->setRange(0, 1);
  customPlot->yAxis->setRange(0, 1);
  //customPlot->yAxis->setRange(-1, 1);
}
void MainWindow::setupDemo(int demoIndex)
{
  switch (demoIndex)
  {
    case 0:  setupQuadraticDemo(ui->customPlot); break;
 /*
    case 1:  setupSimpleDemo(ui->customPlot); break;
    case 2:  setupSincScatterDemo(ui->customPlot); break;
    case 3:  setupScatterStyleDemo(ui->customPlot); break;
    case 4:  setupScatterPixmapDemo(ui->customPlot); break;
    case 5:  setupLineStyleDemo(ui->customPlot); break;
    case 6:  setupDateDemo(ui->customPlot); break;
    case 7:  setupTextureBrushDemo(ui->customPlot); break;
    case 8:  setupMultiAxisDemo(ui->customPlot); break;
    case 9:  setupLogarithmicDemo(ui->customPlot); break;
    case 10: setupRealtimeDataDemo(ui->customPlot); break;
    case 11: setupParametricCurveDemo(ui->customPlot); break;
    case 12: setupBarChartDemo(ui->customPlot); break;
    case 13: setupStatisticalDemo(ui->customPlot); break;
    case 14: setupSimpleItemDemo(ui->customPlot); break;
    case 15: setupItemDemo(ui->customPlot); break;
    case 16: setupStyledDemo(ui->customPlot); break;
    case 17: setupAdvancedAxesDemo(ui->customPlot); break;
    */
  }
  setWindowTitle("QCustomPlot: "+demoName);
  statusBar()->clearMessage();
  currentDemoIndex = demoIndex;
  ui->customPlot->replot();
}
