#include "iSense.h"
#include "ui_iSense.h"

iSense::iSense(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::iSense)
{
        qDebug()<<"Created iSense"<<endl;
	ui->setupUi(this);
}

iSense::~iSense()
{
	delete ui;
}

// Slots definitions
void iSense::displayAbout()
{
	QMessageBox::about(this, tr("About"),
		tr("Politechnika Wrocławska"));
}
void iSense::displayAboutQT()
{
    QApplication::aboutQt();
}
