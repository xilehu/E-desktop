#include "mainwidget.h"


MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    initMainWidgetUi();
    initMainWidgetCtrl();
    installSystemApp();
    installQuickApp();
    //width = 800 , height = 1280

}

MainWidget::~MainWidget()
{
}

void MainWidget::initMainWidgetUi(void)
{
    m_pMainLayout = new QVBoxLayout(this);
    m_pStackedWidget = new QStackedWidget(this);

    m_pLauncherWidget = new LauncherWidget(this);
    m_pStackedWidget->addWidget(m_pLauncherWidget);

    m_pLockWidget = new LockWidget(this);
    m_pStackedWidget->addWidget(m_pLockWidget);

    m_pStackedWidget->setCurrentIndex(1);

    m_pMainLayout->addWidget(m_pStackedWidget);
    m_pMainLayout->setSpacing(0);
    m_pMainLayout->setMargin(0);

    setLayout(m_pMainLayout);
    setObjectName("mainwindow");
    setFixedSize(m_screenWidth,m_screenHeigh);



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

void MainWidget::systemTimeChange()
{
    QDateTime current = QDateTime::currentDateTime();

}
void MainWidget::installSystemApp()
{

    auto *pCameraBtn = new AppButton(":/resources/image/cameraApp.png");
    m_pLauncherWidget->addUserApp(pCameraBtn,"cameraBtn");

    connect(pCameraBtn, &QPushButton::clicked, this, &MainWidget::cameraBtnClicked);



    auto *pMessageBtn = new AppButton(":/resources/image/messageApp.png");
    m_pLauncherWidget->addUserApp(pMessageBtn,"messageBtn");


    auto *phoneBtn = new AppButton(":/resources/image/phoneApp.png");
    m_pLauncherWidget->addUserApp(phoneBtn,"phoneBtn");


    auto *pbookBtn = new AppButton(":/resources/image/bookApp.png");
    m_pLauncherWidget->addUserApp(pbookBtn,"bookBtn");


    auto *pclacBtn = new AppButton(":/resources/image/clacApp.png");
    m_pLauncherWidget->addUserApp(pclacBtn,"clacBtn");


    auto *pgoogleBtn = new AppButton(":/resources/image/googleApp.png");
    m_pLauncherWidget->addUserApp(pgoogleBtn,"googleBtn");


    auto *pledBtn = new AppButton(":/resources/image/ledApp.png");
    m_pLauncherWidget->addUserApp(pledBtn,"ledBtn");



    auto *pmapBtn = new AppButton(":/resources/image/mapApp.png");
    m_pLauncherWidget->addUserApp(pmapBtn,"mapBtn");



    auto *pmusicBtn = new AppButton(":/resources/image/musicApp.png");
    m_pLauncherWidget->addUserApp(pmusicBtn,"musicBtn");



}

void MainWidget::installQuickApp()
{
    auto *ppictureBtn = new AppButton(":/resources/image/pictureApp.png");
    m_pLauncherWidget->addQuickApp(ppictureBtn,"pictureBtn");

    auto *psystemtoolBtn = new AppButton(":/resources/image/systemtoolApp.png");
    m_pLauncherWidget->addQuickApp(psystemtoolBtn,"systemtoolBtn");

    auto *ptalkBtn = new AppButton(":/resources/image/talkApp.png");
    m_pLauncherWidget->addQuickApp(ptalkBtn,"talkBtn");

    auto *pvideoBtn = new AppButton(":/resources/image/videoApp.png");
    m_pLauncherWidget->addQuickApp(pvideoBtn,"videoBtn");
}


void MainWidget::setBackground(const QPixmap &pixmap)
{
    QPalette  palette = this->palette();
    palette.setBrush(backgroundRole(), pixmap.scaled(m_screenWidth, m_screenHeigh, Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    setPalette(palette);
    setAutoFillBackground(true);
}
void MainWidget::cameraBtnClicked()
{
    m_pAppWidget = new CameraApp(this);
    m_pAppWidget->installEventFilter(this);
    m_pAppWidget->setFixedSize(this->size());
    m_pAppWidget->show();
}

