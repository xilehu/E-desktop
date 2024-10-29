#include "lockwidget.h"

LockWidget::LockWidget(QWidget *parent) : QWidget(parent)
{
    initLockWidgetUi();
    initLockWidgetCtrl();
}


void LockWidget::initLockWidgetUi(void)
{
    m_pMainLayout = new QVBoxLayout(this);
    m_pTopWidget = new TopWidget(this);
    m_pMainLayout->addWidget(m_pTopWidget);


    m_BodyScrollArea = new QScrollArea(this);
    m_BodyScrollArea->setWidgetResizable(true);

    m_BodyScrollArea->setAlignment(Qt::AlignCenter);
    m_BodyScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_BodyScrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    m_BodyScrollArea->setStyleSheet("background: transparent;");

    auto scroller = QScroller::scroller(m_BodyScrollArea);
    scroller->grabGesture(m_BodyScrollArea, QScroller::LeftMouseButtonGesture);

    auto properties = scroller->scrollerProperties();
    properties.setScrollMetric(QScrollerProperties::SnapTime, 0.8);
    properties.setScrollMetric(QScrollerProperties::MinimumVelocity, 1);
    scroller->setScrollerProperties(properties);

    m_BodyWidget = bodyWidgetInit();
    m_BodyScrollArea->setWidget(m_BodyWidget);
    m_BodyWidget->setFixedHeight(550);
    m_pMainLayout->addWidget(m_BodyScrollArea);
    setLayout(m_pMainLayout);
}

void LockWidget::initLockWidgetCtrl(void)
{
    connect(m_pCameraButton,&QPushButton::clicked,this,&LockWidget::onCameraClicked);
    connect(m_pLedButton,&QPushButton::clicked,this,&LockWidget::onLedClicked);
    connect(QScroller::scroller(m_BodyScrollArea), &QScroller::stateChanged, this, &LockWidget::onScrollerStateChanged);
    connect(this, &LockWidget::lockToLanuchWidget, this, [](){
        std::cout<<"进入主界面"<<std::endl;
    });
}




QWidget* LockWidget::bodyWidgetInit(void)
{
    auto bodyWidget = new QWidget(this);
    bodyWidget->setStyleSheet("background: transparent;");

    /*锁屏图标＆布局*/
    auto lockLabelWidget = new QWidget(bodyWidget);
    auto lockLabelLayout = new QGridLayout(lockLabelWidget);

    m_pLockUp = new QLabel(bodyWidget);
    m_pLockUp->setObjectName("lockUpLbl");
    m_pLockDown = new QLabel(bodyWidget);
    m_pLockDown->setObjectName("lockDownLbl");

    lockLabelLayout->setSpacing(0);
    lockLabelLayout->addWidget(m_pLockUp, 0, 0);
    lockLabelLayout->addWidget(m_pLockDown, 1, 0);
    lockLabelLayout->setContentsMargins(0, 0, 0, 0);
    lockLabelWidget->setLayout(lockLabelLayout);

    /*锁屏时间＆布局*/
    auto dateWidget = new QWidget(bodyWidget);
    auto dateLayout = new QHBoxLayout(dateWidget);

    m_pDate = new QLabel(dateWidget);
    m_pDate->setText("10月20日 周六");
    m_pDate->setObjectName("dateLbl");

    dateLayout->addStretch(1);
    dateLayout->addWidget(m_pDate);
    dateLayout->addStretch(1);
    dateLayout->setContentsMargins(0, 0, 0, 0);
    dateWidget->setLayout(dateLayout);

    auto clockWidget = new QWidget(bodyWidget);
    auto clockLayout = new QHBoxLayout(clockWidget);

    m_pClock = new QLabel(clockWidget);
    m_pClock->setText("00:00");
    m_pClock->setObjectName("clockLbl");

    clockLayout->addStretch(1);
    clockLayout->addWidget(m_pClock);
    clockLayout->addStretch(1);
    clockLayout->setContentsMargins(0, 0, 0, 0);
    clockWidget->setLayout(clockLayout);

    /*锁屏工具-相机和闪光灯＆布局*/
    auto toolsWidget = new QWidget(bodyWidget);
    auto toolsLayout = new QHBoxLayout(toolsWidget);


    m_pCameraButton = new QPushButton(toolsWidget);
    m_pCameraButton->setObjectName("cameraButton");

    m_pLedButton = new QPushButton(toolsWidget);
    m_pLedButton->setObjectName("ledButton");

    toolsLayout->addSpacing(20);
    toolsLayout->addWidget(m_pCameraButton);
    toolsLayout->addStretch();
    toolsLayout->addWidget(m_pLedButton);
    toolsLayout->addSpacing(20);
    toolsLayout->setContentsMargins(0, 8, 0, 8);
    toolsWidget->setLayout(toolsLayout);

    /*锁屏界面-主体Widget布局*/
    auto bodyLayout = new QVBoxLayout(bodyWidget);
    bodyLayout->addSpacing(20);
    bodyLayout->addWidget(lockLabelWidget);
    bodyLayout->addSpacing(10);
    bodyLayout->addWidget(dateWidget);
    bodyLayout->addSpacing(10);
    bodyLayout->addWidget(clockWidget);

    bodyLayout->addStretch();
    bodyLayout->addWidget(toolsWidget);
    bodyLayout->addSpacing(50);
    bodyLayout->setMargin(0);
    bodyLayout->setSpacing(0);
    bodyWidget->setLayout(bodyLayout);

    CommonTool::setStyleSheet(":/lockwidget/style/default.qss", this);

    return bodyWidget;
}


