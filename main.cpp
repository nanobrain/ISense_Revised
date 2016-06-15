#include "iSense.h"
#include "controller.h"
#include <QApplication>

Controller* g_controller;

int main(int argc, char *argv[])
{
	//QApplication a(argc, argv);
	//g_controller = new Controller(g_app,argc,argv);
	Controller controller(argc,argv);
	//iSense w;
	//w.show();
	//return a.exec();
	//return controller.exec();
	return QCoreApplication::exec();
}
