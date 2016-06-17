#include "mainmodel.h"
#include "controller.h"

extern Controller* g_pController;

MainModel::MainModel(QObject *parent) : QObject(parent)
{
	connect(this,SIGNAL(statusChanged()),g_pController,SLOT(onStatusChanged()));
}

MainModel::~MainModel()
{
	/**/
}

QPair<QString,QString> MainModel::getStatus()
{
	return m_status;
}

void MainModel::setStatus(QPair<QString,QString> status)
{
	m_status = status;
	emit statusChanged();
}
