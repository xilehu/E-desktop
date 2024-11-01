#include "mainwidget.h"

#include <QStackedWidget>

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    initMainWidgetUi();
    initMainWidgetCtrl();

    //width = 800 , height = 1280

}

MainWidget::~MainWidget()
{
}

void MainWidget::initMainWidgetUi(void)
{
    m_pMainLayout = new QVBoxLayout(this);
    m_pStackedWidget = new QStackedWidget(this);

    m_pLanuchWidget = new QWidget();
    m_pLanuchLayout = new QVBoxLayout(m_pLanuchWidget);
    m_pLanuchButton = new QPushButton(m_pLanuchWidget);
    m_pLanuchButton->setText("home");
    m_pLanuchLayout->addWidget(m_pLanuchButton);
    m_pStackedWidget->addWidget(m_pLanuchWidget);



    m_pLockWidget = new LockWidget(this);
    m_pStackedWidget->addWidget(m_pLockWidget);



    setLayout(m_pMainLayout);

    setObjectName("mainwindow");
    setFixedSize(m_screenWidth,m_screenHeigh);

    m_pMainLayout->addWidget(m_pStackedWidget);
    m_pStackedWidget->setCurrentIndex(1);

    setBackground(QPixmap(":/mainwidget/image/background_1.jpeg"));

}

void MainWidget::initMainWidgetCtrl(void)
{
    connect(m_pLockWidget,&LockWidget::lockToLanuchWidget,this,&MainWidget::lockToLaunchChange);
}


void MainWidget::lockToLaunchChange()
{
    m_pStackedWidget->setCurrentIndex(0);
}









void MainWidget::setBackground(const QPixmap &pixmap)
{
    QPalette  palette = this->palette();
    palette.setBrush(backgroundRole(), pixmap.scaled(m_screenWidth, m_screenHeigh, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    setPalette(palette);
    setAutoFillBackground(true);
}


