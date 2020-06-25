#include <QApplication>
#include "fastsnipewindow.h"

int main(int argc, char* argv[]) {
	QApplication app(argc, argv);

	app.setStyle("fusion");
	
	FastSnipeWindow win;
	win.show();

	return app.exec();
}
