#ifndef TOPWIDGET_H
#define TOPWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QFile>
#include <QTimer>
#include <QTime>
#include <QDate>
#include <functional>

#include "../commontool.h"

class TopWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TopWidget(QWidget *parent = nullptr);
    using updateTimeCb = std::function<void(const QString &)>;
    using updateDateCb = std::function<void(const QString &)>;

    void registerUpdateTimeCb(updateTimeCb cb);
    void registerUpdateDateCb(updateDateCb cb);
    void updateTime();
    void updateDate();
private:
    void initTopWidgetUi();

//    void initTopWidgetUi();

private:
    QTimer *m_pSysTimer;
    QLabel *pSysTime = new QLabel("10:02:57", this);

    updateTimeCb m_pUpdateTimeCb = nullptr;
    updateDateCb m_pUpdateDateCb = nullptr;
};

#endif // TOPWIDGET_H
