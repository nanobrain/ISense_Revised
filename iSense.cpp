#include "iSense.h"
#include "ui_iSense.h"

iSense::iSense(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::iSense)
{
	qDebug()<<"Created iSense"<<__FILE__ << __LINE__<<endl;
	ui->setupUi(this);
	ui->statusBar->showMessage(tr("Not connected!"));
	ui->statusBar->setStyleSheet("QStatusBar { color : red; }");
}

iSense::~iSense()
{
	delete ui;
}

void iSense::setStatus(QPair<QString,QString> status)
{
	ui->statusBar->showMessage(status.first);
	ui->statusBar->setStyleSheet(status.second);
}

// Slots definitions
void iSense::displayAbout()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QMessageBox::about(this, tr("About"),
		tr("Politechnika Wrocławska"));
}
void iSense::displayAboutQT()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QApplication::aboutQt();
}
