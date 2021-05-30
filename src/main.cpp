#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationDisplayName("Primus v.0.2.1 αlpha");

	MainWindow w;
	w.show();
	return a.exec();
}
