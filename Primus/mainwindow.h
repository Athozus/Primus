#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include "cmath"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void calculate();

private:
    Ui::MainWindow *ui;
    QSpinBox *minSpin;
    QSpinBox *maxSpin;
    QProgressBar *progressBar;
    QLabel *resultsExaminated;
    QLabel *resultsFound;
    QLabel *resultsPercentage;
};
#endif // MAINWINDOW_H
