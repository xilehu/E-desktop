#include "userwidget.h"

UserWidget::UserWidget(QWidget *parent) : QWidget(parent)
{
    initUserWidgetUi();
//    cameraButton = new QPushButton(this);
//    cameraButton->setText("Camera");
//    addUserApp(cameraButton,"hello");
//    auto a = new QPushButton(this);
//    a->setText("sss");
//    addUserApp(a,"hello");
//delUserApp(cameraButton);
//auto b = new QPushButton(this);
//b->setText("bbb");
//addUserApp(b,"hello");
    //    findAppWidget(a);
}

int UserWidget::isUserWidgetFull()
{
    if(m_appWidgetCnt>userAppRows*userAppCols) {
        return 1;
    }
    return 0;
}

void UserWidget::initUserWidgetUi(void)
{
    m_appWidgetCnt = 0;
    m_pUserGridLayout = new QGridLayout(this);
    m_pUserGridLayout->setObjectName(QString::fromUtf8("m_pUserGridLayout"));
    m_userWidgetVector.resize(userAppRows);
    for (int i = 0; i < userAppRows; ++i) {
        m_userWidgetVector[i].resize(userAppCols);
        for (int j = 0; j < userAppCols; ++j) {
            QWidget* widget = new QWidget;
            widget->setFixedSize(50, 50);  // 设置占位符的大小（可选）
            widget->setStyleSheet("background-color: lightgray;");
            // 将int和QWidget*的配对存入QVector
            m_userWidgetVector[i][j] = qMakePair(0, widget);
            m_pUserGridLayout->addWidget(widget, i, j);
        }
    }
}

void UserWidget::addUserApp(QPushButton *app,const QString &appName)
{
    auto emptyWidget = getFirstEmptyWidget();
    if(emptyWidget !=nullptr) {
        auto Applayout = new QHBoxLayout;
        Applayout->addWidget(app);
        Applayout->setContentsMargins(0, 0, 0, 0);
        Applayout->setSpacing(0);
        emptyWidget->second->setLayout(Applayout);
        emptyWidget->first = 1;
        m_appWidgetCnt++;
    }
}

void UserWidget::delUserApp(QPushButton *app)
{
    QWidget* appWidget = findAppWidget(app);
    if(appWidget) {
        for (int i = 0; i < m_userWidgetVector.size(); ++i) {
            for (int j = 0; j < m_userWidgetVector[i].size(); ++j) {
                if (m_userWidgetVector[i][j].second == appWidget) {
                    m_userWidgetVector[i][j].first = 0;
                    break;
                }
            }
        }
        auto appLayout = appWidget->layout();
        if (appLayout != nullptr) {
               while (QLayoutItem *item = appLayout->takeAt(0)) {
                   QWidget *widgetItem = item->widget();
                   if (widgetItem) {
                       widgetItem->deleteLater();
                   }
                   delete item;
               }
               delete appLayout;
               m_appWidgetCnt--;
        }
    }
}



QPair<int, QWidget*>* UserWidget::getFirstEmptyWidget()
{
    for (int i = 0; i < m_userWidgetVector.size(); ++i) {
        for (int j = 0; j < m_userWidgetVector[i].size(); ++j) {
            if (m_userWidgetVector[i][j].first == 0) {
                return &m_userWidgetVector[i][j];
            }
        }
    }
    return nullptr;
}

QWidget* UserWidget::findAppWidget(QPushButton *app)
{
    QWidget* currentWidget = app->parentWidget();
    if(currentWidget) {
        return  currentWidget;
    }
    return nullptr;
}
