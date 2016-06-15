#include "controller.h"

Controller::Controller(int& argc, char** argv)
	: QApplication(argc,argv)
{
#if SPLASH_SCREEN
	QSplashScreen* pSplashScreen = new QSplashScreen();
	m_iSense = new iSense();
	pSplashScreen->setPixmap(QPixmap(":/Images/Images/Splash.jpg"));
	pSplashScreen->show();
	pSplashScreen->raise();
	qApp->processEvents();
	// TODO: SHOW SERVER CONNECTION STATUS IN MESSAGE ON SPLASH SCREEN
	pSplashScreen->showMessage(QObject::trUtf8("Application starts...."), Qt::AlignRight|Qt::AlignBottom, Qt::black);
	QTimer::singleShot(1000,Qt::VeryCoarseTimer, m_iSense,SLOT(showNormal()));
	pSplashScreen->finish(m_iSense);
	delete pSplashScreen;
#else
	m_iSense = new iSense();
	m_iSense->show();
#endif

	setApplicationName(APPLICATION_NAME);
	setApplicationTitle(APPLICATION_TITLE);
	setApplicationVersion(APPLICATION_VERSION);
	setQuitOnLastWindowClosed(true);

}

Controller::~Controller(){};

void Controller::setApplicationTitle(const QString a_sTitle)
{
	Q_ASSERT(!a_sTitle.isEmpty());
	if(m_iSense!=nullptr)
	{
	m_iSense->setWindowTitle(a_sTitle);
	}
	else
		qCritical()<<"m_iSense not created yet !"<<endl;
}

void Controller::setApplicationName(const QString a_sName)
{
	Q_ASSERT(!a_sName.isEmpty());
	QCoreApplication::setApplicationName(a_sName);
}

void Controller::setApplicationVersion(const QString a_sVersion)
{
	Q_ASSERT(!a_sVersion.isEmpty());
	QCoreApplication::setApplicationVersion(a_sVersion);
}
