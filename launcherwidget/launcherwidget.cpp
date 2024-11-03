#include "launcherwidget.h"

LauncherWidget::LauncherWidget(QWidget *parent) : QWidget(parent)
{
    initLauncherWidgetUi();
}

void LauncherWidget::initLauncherWidgetUi(void)
{

    m_pLauncherLayout = new QVBoxLayout(this);
    m_pLauncherLayout->setObjectName(QString::fromUtf8("m_pLauncherLayout"));


    m_pTopWidget = new TopWidget();




    m_pLauncherLayout->addWidget(m_pTopWidget);


    m_pUserScrollArea = new QScrollArea(this);
    m_pUserScrollArea->setObjectName(QString::fromUtf8("userScrollArea"));
    m_pUserScrollArea->setWidgetResizable(true);


    m_pUserWiget = new UserWidget();

    m_pUserScrollArea->setWidget(m_pUserWiget);

    m_pLauncherLayout->addWidget(m_pUserScrollArea);

    m_pQuickWidget = new QWidget(this);
    auto quickLayout = new QHBoxLayout(m_pQuickWidget);

    pushButton_8 = new QPushButton(m_pQuickWidget);
    pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

    quickLayout->addWidget(pushButton_8);

    pushButton_9 = new QPushButton(m_pQuickWidget);
    pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

    quickLayout->addWidget(pushButton_9);

    pushButton_10 = new QPushButton(m_pQuickWidget);
    pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

    quickLayout->addWidget(pushButton_10);


    m_pLauncherLayout->addWidget(m_pQuickWidget);
    this->setLayout(m_pLauncherLayout);

}

