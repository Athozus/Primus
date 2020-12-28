#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QWidget>
#include <QGridLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QPushButton>
#include <QLabel>
#include <QProgressBar>
#include <QIcon>
#include "cmath"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("Primus");
    setGeometry(240, 240, 200, 240);
    setWindowIcon(QIcon("Icon.png"));

    QWidget *mainWidget = new QWidget();
    setCentralWidget(mainWidget);

    QGridLayout *mainLayout = new QGridLayout();
    mainWidget->setLayout(mainLayout);

    QFormLayout *formLayout = new QFormLayout();
    mainLayout->addLayout(formLayout, 0, 0);

    minSpin = new QSpinBox();
    minSpin->setRange(2, (int)pow(10, 48));
    maxSpin = new QSpinBox();
    maxSpin->setRange(2, (int)pow(10, 48));
    maxSpin->setValue(1000);

    formLayout->addRow("Min", minSpin);
    formLayout->addRow("Max", maxSpin);

    buttonCalculate = new QPushButton("Calculate");
    mainLayout->addWidget(buttonCalculate, 1, 0);
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));

    progressBar = new QProgressBar();
    progressBar->setValue(0);
    progressBar->setEnabled(false);
    mainLayout->addWidget(progressBar, 2, 0);

    resultsExaminated = new QLabel("Examinated: 0");
    mainLayout->addWidget(resultsExaminated, 3, 0);

    resultsFound = new QLabel("Found: 0");
    mainLayout->addWidget(resultsFound, 4, 0);

    resultsPercentage = new QLabel("Percentage: 0.000 %");
    mainLayout->addWidget(resultsPercentage, 5, 0);
}

void MainWindow::launchCalculating()
{
    buttonCalculate->setText("Stop calculating");
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

    int i;
    int n(0);
    for(i = min; i < max ; i++) {
        int j;
        bool prime(true);
        for(j = min; j < sqrt(i); j++) {
            if (i%j == 0) {
                prime = false;
                break;
            }
        }
        if(prime) {
            n++;
        }
        int progress = ( int ) round ( ( double ) ( i - min ) / ( max - min ) * 100 );
        progressBar->setValue(progress);
    }

    progressBar->setValue(100);
    resultsExaminated->setText("Examinated: " + QString::number(max-min));
    resultsFound->setText("Found: " + QString::number(n));
    resultsPercentage->setText( "Percentage: " + QString::number( ( ceil( ( double ) n / ( max - min ) * 1000) / 1000 ) ) + " %" );    

    buttonCalculate->setText("Calculate");
    buttonCalculate->disconnect();
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));
}

void MainWindow::stop()
{

    buttonCalculate->setText("Calculate");
    buttonCalculate->disconnect();
    connect(buttonCalculate, SIGNAL(clicked()), this, SLOT(launchCalculating()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

