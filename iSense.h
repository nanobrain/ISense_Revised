#ifndef iSense_H
#define iSense_H

#include <QMessageBox>
#include <QMainWindow>
#include <QtGui>

namespace Ui {
class iSense;
}

class iSense : public QMainWindow
{
    Q_OBJECT

public:
	explicit iSense(QWidget *parent = 0);
    ~iSense();

private:
	Ui::iSense* ui;

signals:
public slots:
    void displayAbout();
    void displayAboutQT();

};

#endif // iSense_H
