#include "topwidget.h"

TopWidget::TopWidget(QWidget *parent) : QWidget(parent)
{
    initTopWidgetUi();
}

void TopWidget::initTopWidgetUi()
{
    pSysTime->setText("10:02:57");
    pSysTime->setObjectName("sysTimeLbl");

    QLabel *pWifiLbl = new QLabel(this);
    pWifiLbl->setObjectName("wifiLbl");

    QLabel *pbatteryLbl = new QLabel(this);
    pbatteryLbl->setObjectName("batteryLbl");

    auto *pLayout = new QHBoxLayout;
    pLayout->addSpacing(24);
    pLayout->addWidget(pSysTime);
    pLayout->addStretch();
    pLayout->addWidget(pWifiLbl);
    pLayout->addWidget(pbatteryLbl);
    pLayout->addSpacing(24);
    pLayout->setContentsMargins(0, 8, 0, 8);

    setLayout(pLayout);
    setObjectName("topwidget");

    CommonTool::setStyleSheet(":/topwidget/style/default.qss",this);


    QTimer *m_pSysTimer = new QTimer(this);
    connect(m_pSysTimer, &QTimer::timeout, this, &TopWidget::updateTime);
    m_pSysTimer->start(60000);
//    timer->stop(); // 停止定时器
    updateTime();
}

void TopWidget::registerUpdateTimeCb(updateTimeCb cb)
{
    m_pUpdateTimeCb = cb;
    updateTime();
}
void TopWidget::registerUpdateDateCb(updateDateCb cb)
{
    m_pUpdateDateCb = cb;
    updateDate();

}



void TopWidget::updateTime()
{
    QTime current = QTime::currentTime();
    QString timeString = current.toString("hh:mm");
    pSysTime->setText(timeString);
    if(m_pUpdateTimeCb != nullptr)
        m_pUpdateTimeCb(timeString);
}

void TopWidget::updateDate()
{
    QDateTime current = QDateTime::currentDateTime();
    QDate date = current.date();
    QString month = QString::number(date.month()).rightJustified(2, '0');
    QString day = QString::number(date.day()).rightJustified(2, '0');
    QString dateString = month+"月"+day+"日";
    if(m_pUpdateDateCb != nullptr)
        m_pUpdateDateCb(dateString);
}
