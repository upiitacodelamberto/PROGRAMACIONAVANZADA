#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qcustomplot.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setupDemo(int demoIndex);
    void setupQuadraticDemo(QCustomPlot *customPlot);

private:
    Ui::MainWindow *ui;
    QString demoName;
    int currentDemoIndex;
};

#endif // MAINWINDOW_H
