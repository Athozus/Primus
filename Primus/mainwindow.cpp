#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QIcon>
#include <QPoint>
#include <QMouseEvent>
#include "cmath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);
    setWindowTitle("Primus");
    resize(200, 240);
    setWindowIcon(QIcon("Icon.png"));
    setObjectName("mainWindow");

    QWidget *mainWidget = new QWidget();
    mainWidget->setObjectName("mainWidget");
    setCentralWidget(mainWidget);

    QGridLayout *mainLayout = new QGridLayout();
    mainWidget->setLayout(mainLayout);

    QGridLayout *headerLayout = new QGridLayout();
    mainLayout->addLayout(headerLayout, 0, 0);
    
    QLabel *windowTitle = new QLabel("Primus");
    windowTitle->setObjectName("windowTitle");
    headerLayout->addWidget(windowTitle, 0, 0);

    QLabel *version = new QLabel("v.0.2.1 αlpha");
    version->setObjectName("version");
    headerLayout->addWidget(version, 0, 1);
    
    QPushButton *minimizeButton = new QPushButton("-");
    minimizeButton->setObjectName("minimizeButton");
    headerLayout->addWidget(minimizeButton, 0, 2);
    connect(minimizeButton, SIGNAL(clicked()), this, SLOT(showMinimized()));
    
    QPushButton *exitButton = new QPushButton("×");
    exitButton->setObjectName("exitButton");
    headerLayout->addWidget(exitButton, 0, 3);
    connect(exitButton, SIGNAL(clicked()), qApp, SLOT(quit()));

    QFormLayout *formLayout = new QFormLayout();
    mainLayout->addLayout(formLayout, 1, 0);

    minSpin = new QSpinBox();
    minSpin->setRange(2, (int)pow(10, 48));
    maxSpin = new QSpinBox();
    maxSpin->setRange(2, (int)pow(10, 48));
    maxSpin->setValue(1000);

    formLayout->addRow("Min", minSpin);
    formLayout->addRow("Max", maxSpin);

    buttonCalculate = new QPushButton("Calculate");
    mainLayout->addWidget(buttonCalculate, 2, 0);
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));

    progressBar = new QProgressBar();
    progressBar->setValue(0);
    progressBar->setEnabled(false);
    progressBar->setRange(0,1000);
    mainLayout->addWidget(progressBar, 3, 0);

    resultsExaminated = new QLabel("Examinated: 0");
    mainLayout->addWidget(resultsExaminated, 4, 0);

    resultsFound = new QLabel("Found: 0");
    mainLayout->addWidget(resultsFound, 5, 0);

    resultsPercentage = new QLabel("Percentage: 0.000 %");
    mainLayout->addWidget(resultsPercentage, 6, 0);
}

void MainWindow::launchCalculating()
{
    //buttonCalculate->setText("Stop calculating");
    buttonCalculate->setEnabled(false);
    buttonCalculate->disconnect();
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(stop()));
    calculate();
}

void MainWindow::calculate()
{
    int min;
    int max;
    min = minSpin->value();
    max = maxSpin->value();
    
    int n(0);
    
    if (((min > 80000) or ((max-min) < 2048) or (max > pow(10, 6)))) {
        for (int i = min; i <= max; i++) {
            bool prime = true;
            for(int j = 2; j <= sqrt(i); j++) {
                if (i%j == 0) {
                    prime = false;
                        break;
                }
            }
            if(prime) {
                n++;
            }
            int progress = (int)round(pow(((double)(i-min)/(max-min+1)*1),3)*1000);
            progressBar->setValue(progress);
        }
    }

    else {
        bool array[max+1];
        for (int i = 0; i <= max; i++) {
            array[i] = true;
        }
        for (int i = 2; i <= max; i++) {
            if (array[i]) {
                n++;
                for (int j = i*2; j < max; j += i) {
                    array[j] = false;
                }
            }
        progressBar->setValue((int)round(pow(((double)(i-min)/(max-min+1)*1),3)*1000));
        }
    }

    progressBar->setValue(1000);
    resultsExaminated->setText("Examinated: " + QString::number(max-min+1));
    resultsFound->setText("Found: " + QString::number(n));
    resultsPercentage->setText("Percentage: " + QString::number((ceil((double)n/(max-min+1)*100000)/1000)) + " %");

    system(qPrintable("notify-send 'Primus' '" + QString::number(n) + " prime numbers founded' '-t' 5000 '-u' low"));

    //buttonCalculate->setText("Calculate");
    buttonCalculate->setEnabled(true);
    buttonCalculate->disconnect();
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));
}

void MainWindow::stop()
{

    buttonCalculate->setText("Calculate");
    buttonCalculate->disconnect();
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    mouseDifference = event->pos();
  
    setCursor(QCursor(Qt::SizeAllCursor));
}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
    Q_UNUSED(event);
  
    setCursor(QCursor(Qt::ArrowCursor));
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    QPoint p = event->globalPos();
  
    window()->move(p - mouseDifference);
}

MainWindow::~MainWindow()
{
    delete ui;
}

