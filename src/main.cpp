#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	a.setApplicationDisplayName("Primus v.0.2.1 αlpha");

	QFontDatabase::addApplicationFont("RedHatDisplay-Regular.woff");
        QFont redHatDisplay("Red Hat Display", 1);
        a.setFont(redHatDisplay);

    	QFile file(a.applicationDirPath() + "/style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	a.setStyleSheet(styleSheet);
    
	MainWindow w;
	w.show();
	return a.exec();
}
