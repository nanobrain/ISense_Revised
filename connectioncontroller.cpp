#include "connectioncontroller.h"

ConnectionController::ConnectionController(QObject *parent) : QObject(parent)
{
	m_pSocket= new QTcpSocket(this);
	connect( this, SIGNAL(connectionClosed()), this, SLOT(onDisconnected()) );
	connect( m_pSocket, SIGNAL(connected()), this, SLOT(onConnected()) );
	connect( m_pSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)) );
	connect( m_pSocket, SIGNAL(readyRead()), this, SLOT(onRead()) );
	qDebug()<<"Created ConnectionControler"<<__FILE__ << __LINE__<<endl;
}

ConnectionController::~ConnectionController()
{
	m_pSocket->write(SERVER_CMD_EXIT);
}

void ConnectionController::connectToServer()
{
	bool reconnect=1;

	while(reconnect)
	{
		m_pSocket->connectToHost("127.1.1.1", 1666);
		if( m_pSocket->waitForConnected(SERVER_RECONNECT_TIME) )
		{
			introduceMyself();
			qDebug()<<"Connected to server"<<__FILE__ << __LINE__<<endl;
			reconnect=0;
		}
		else
			{
				qWarning() << "Failed to bind to server !"<<__FILE__ << __LINE__<<endl;
				if( QMessageBox::information(0,tr("Server error"),tr("Cannot connect to server. Retry?"), QMessageBox::Yes|QMessageBox::No) == QMessageBox::No)
				{
					reconnect=0;
				}
			}
	}
}

void ConnectionController::disconnectFromServer()
{
	m_pSocket->disconnectFromHost();
	emit connectionClosed();
}

QVector<Sensor*> ConnectionController::getSensorsList()
{
	METHOD_NOT_IMPLEMENTED
}

void ConnectionController::introduceMyself()
{
	m_pSocket->write(SERVER_CMD_MY_NAME);
}

void ConnectionController::setModel(MainModel *mod)
{
	m_pmodel = mod;
}

// slots:
void ConnectionController::onRead()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QString result;
	result = static_cast<QString>(m_pSocket->readAll());
	qDebug()<< result.split("\r\n");
}

void ConnectionController::onConnected()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QPair<QString,QString> status;
	status.first=tr("Connected");
	status.second="QStatusBar { color : blue; }";
	m_pmodel->setStatus(status);
	//emit connectionEstablished();
}

void ConnectionController::onDisconnected()
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QPair<QString,QString> status;
	status.first=tr("Not connected");
	status.second="QStatusBar { color : red; }";
	m_pmodel->setStatus(status);
	//emit connectionFailed();
}

void ConnectionController::onError(QAbstractSocket::SocketError error)
{
	qDebug()<<"Invoked: "<<__PRETTY_FUNCTION__<<endl;
	QPair<QString,QString> status;
	status.first=QString(tr("Cannot connect to server ! Error code: %1")).arg(QString::number(error));
	status.second="QStatusBar { color : red; }";
	m_pmodel->setStatus(status);
	//emit connectionError();
}
