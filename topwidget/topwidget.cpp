#include "topwidget.h"

TopWidget::TopWidget(QWidget *parent) : QWidget(parent)
{
    pSysTime->setText("10:02:57");
    pSysTime->setObjectName("sysTimeLbl");

    QLabel *pWifiLbl = new QLabel(this);
    pWifiLbl->setObjectName("wifiLbl");

    QLabel *pbatteryLbl = new QLabel(this);
    pbatteryLbl->setObjectName("batteryLbl");

    auto *pLayout = new QHBoxLayout;
    pLayout->addSpacing(12);
    pLayout->addWidget(pSysTime);
    pLayout->addStretch();
    pLayout->addWidget(pWifiLbl);
    pLayout->addWidget(pbatteryLbl);
    pLayout->addSpacing(12);
    pLayout->setContentsMargins(0, 8, 0, 8);

    setLayout(pLayout);
    setObjectName("topwidget");

    QFile file(":/topwidget/style/default.qss");
    if (file.open(QIODevice::ReadOnly)) {
        this->setStyleSheet(file.readAll());
        file.close();
    }


}
