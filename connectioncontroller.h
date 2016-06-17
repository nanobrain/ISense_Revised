#pragma once

#include "commons.h"
#include "sensor.h"
#include "mainmodel.h"
#include <QObject>
#include <QVector>
#include <QTcpSocket>
#include <QPair>
#include <QString>

#define SERVER_CMD_LIST "list\r\n"
#define SERVER_CMD_MY_NAME "QT APP\r\n"
#define SERVER_CMD_EXIT "exit\r\n"
#define SERVER_RECONNECT_TIME 2000

enum {
	CON_ERROR_CANNOT_CONNECT,
	CON_ERROR_SERVER_NOT_RESPONDING,
	CON_ERROR_SERVER_DISCONNECTED,
	CON_ERROR_DATA_CORRUPTED
};

class ConnectionController : public QObject
{
	Q_OBJECT
public:
	explicit ConnectionController(QObject *parent = 0);
	~ConnectionController();

	void setModel(MainModel* mod);
	void connectToServer();
	void disconnectFromServer();
	QVector<Sensor*> getSensorsList();
private:
	QTcpSocket* m_pSocket;
	MainModel* m_pmodel;
	void introduceMyself();
signals:
	void connectionClosed();
	void connectionEstablished();
	void connectionError();
	void statusChanged();
public slots:
	void onRead();
	void onDisconnected();
	void onError(QAbstractSocket::SocketError error);
	void onConnected();
};
