#pragma once
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QDir>
#include <QTimer>
#include <QPair>
#include <QString>

#include "commons.h"
#include "mainmodel.h"
#include "connectioncontroller.h"

class Controller : public QApplication
{
	Q_OBJECT
public:
	explicit Controller(int& argc, char** argv);
	~Controller();
	void setApplicationTitle(const QString a_sTitle);
	void setApplicationName(const QString a_sName);
	void setApplicationVersion(const QString a_sVersion);
	void setModel(MainModel* mod);
private:
	iSense* m_iSense=nullptr;
	MainModel* m_pmodel;

signals:
	void setStatusBarMessage();
public slots:
	void onStatusChanged();
};
