#include "controller.h"

Controller::Controller(int& argc, char** argv)
	: QApplication(argc,argv)
{
	m_iSense = new iSense();
#if SPLASH_SCREEN
	QSplashScreen* pSplashScreen = new QSplashScreen();
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

Controller::~Controller()
{
	delete m_iSense;
}

void Controller::setApplicationTitle(const QString a_sTitle)
{
	Q_ASSERT(!a_sTitle.isEmpty());
	if(m_iSense!=nullptr)
	{
	m_iSense->setWindowTitle(a_sTitle);
	}
	else
		qCritical()<<"m_iSense not created yet !"<<__FILE__ << __LINE__<<endl;
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
void Controller::setModel(MainModel *mod)
{
	m_pmodel = mod;
}

//Slots
void Controller::onStatusChanged()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	m_iSense->setStatus(m_pmodel->getStatus());
}
