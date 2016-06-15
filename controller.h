#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "commons.h"
#include <QApplication>
#include <QSplashScreen>
#include <QPixmap>
#include <QDir>
#include <QTimer>

class Controller : QApplication
{
public:
	explicit Controller(int& argc, char** argv);
	~Controller();
	void setApplicationTitle(const QString a_sTitle);
	void setApplicationName(const QString a_sName);
	void setApplicationVersion(const QString a_sVersion);
private:
	QTimer* m_drivesUpdateTimer=nullptr;
	iSense* m_iSense=nullptr;
};

#endif // CONTROLLER_H
