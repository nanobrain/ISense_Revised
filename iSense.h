#pragma once

#include <QMessageBox>
#include <QMainWindow>
#include <QtGui>
#include <QPair>
#include <QString>

namespace Ui {
class iSense;
}

class iSense : public QMainWindow
{
	Q_OBJECT
public:
	explicit iSense(QWidget *parent = 0);
	void setStatus(QPair<QString,QString> status);
	~iSense();

private:
	Ui::iSense* ui;

signals:
public slots:
	void displayAbout();
	void displayAboutQT();

};
