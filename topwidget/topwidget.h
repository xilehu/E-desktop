#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
class TopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent = nullptr);

signals:

private:
    QLabel *pSysTime = new QLabel("10:02:57", this);

};

#endif // TOPWIDGET_H
