#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QFont>
#include <QFontDatabase>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    a.setApplicationDisplayName("Primus v.0.2.1 αlpha");

    QFile file(a.applicationDirPath() + "/style.qss");
	file.open(QFile::ReadOnly);
	QString styleSheet = QLatin1String(file.readAll());
	a.setStyleSheet(styleSheet);

	QFontDatabase::addApplicationFont("RedHatDisplay-Regular.ttf");
	QFont redHatDisplay("RedHatDisplay-Regular", 16, QFont::Normal);
	a.setFont(redHatDisplay);
    
	MainWindow w;
	w.show();
	return a.exec();
}
