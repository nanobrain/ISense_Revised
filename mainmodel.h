#pragma once
#include <QObject>
#include <QPair>

class MainModel : public QObject
{
	Q_OBJECT
public:
	explicit MainModel(QObject *parent=0);
	~MainModel();
	QPair<QString,QString> getStatus();
	void setStatus(QPair<QString,QString> status);
private:
	QPair<QString,QString> m_status;

signals:
	void statusChanged();
public slots:

};
