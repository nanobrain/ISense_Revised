#include "controller.h"
#include "connectioncontroller.h"
#include "mainmodel.h"
#include <QApplication>

Controller* g_pController;
ConnectionController* g_pConController;

int main(int argc, char *argv[])
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	g_pController = new Controller(argc,argv);
	g_pConController = new ConnectionController();
	MainModel* pmodel = new MainModel();
	g_pController->setModel(pmodel);
	g_pConController->setModel(pmodel);
	g_pConController->connectToServer();
	return QCoreApplication::exec();
}
