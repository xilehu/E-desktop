#include "launcherwidget.h"

LauncherWidget::LauncherWidget(QWidget *parent) : QWidget(parent)
{
    initLauncherWidgetUi();
}

void LauncherWidget::initLauncherWidgetUi(void)
{

    m_pLauncherLayout = new QVBoxLayout();

    m_pTopWidget = new TopWidget();
    m_pLauncherLayout->addWidget(m_pTopWidget);

    m_pUserScrollArea = new QScrollArea();
    m_pUserScrollArea->setAlignment(Qt::AlignCenter);
    m_pUserScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pUserScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_pUserScrollArea->setWidgetResizable(true);
    m_pUserWiget = new UserWidget();
    m_pUserScrollArea->setWidget(m_pUserWiget);
    m_pUserWiget->setFixedWidth(400*2);

    auto scroller = QScroller::scroller(m_pUserScrollArea);
    scroller->grabGesture(m_pUserScrollArea, QScroller::LeftMouseButtonGesture);

    auto properties = scroller->scrollerProperties();
    properties.setScrollMetric(QScrollerProperties::SnapTime, 0.8);
    properties.setScrollMetric(QScrollerProperties::MinimumVelocity, 1);
    scroller->setScrollerProperties(properties);

    auto *userLayout = new QHBoxLayout();
    auto userspacerLeft = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    userLayout->addItem(userspacerLeft);

    userLayout->addWidget(m_pUserScrollArea);
    auto  *userspacerRight = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    userLayout->addItem(userspacerRight);
    m_pLauncherLayout->addLayout(userLayout);
//    m_pLauncherLayout->addSpacing(30);

    auto *quickLayout = new QHBoxLayout();
    auto quickspacerLeft = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    quickLayout->addItem(quickspacerLeft);
    m_pQuickWidget = new QuickWidget();
    quickLayout->addWidget(m_pQuickWidget);
    auto  *quickspacerRight = new QSpacerItem(20, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);
    quickLayout->addItem(quickspacerRight);
    m_pLauncherLayout->addLayout(quickLayout);

    m_pLauncherLayout->addSpacing(10);
    m_pLauncherLayout->setMargin(0);
    this->setLayout(m_pLauncherLayout);

    this->setStyleSheet("background-color: transparent;");

}
void LauncherWidget::addUserApp(QPushButton *app, const QString &appName)
{
    m_pUserWiget->addUserApp(app,appName);
}

void LauncherWidget::delUserApp(QPushButton *app)
{
    m_pUserWiget->delUserApp(app);
}

void LauncherWidget::addQuickApp(QPushButton *app, const QString &appName)
{
    m_pQuickWidget->addQuickApp(app,appName);
}

void LauncherWidget::delQuickApp(QPushButton *app)
{
    m_pQuickWidget->delQuickApp(app);
}

