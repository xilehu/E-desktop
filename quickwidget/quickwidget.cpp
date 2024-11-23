#include "quickwidget.h"

QuickWidget::QuickWidget(QWidget *parent) : QWidget(parent)
{
    initQuickWidgetUi();
}

void QuickWidget::initQuickWidgetUi(void)
{
    m_quickWidgetCnt = 0;
    m_pQuickWidgetLayout = new QHBoxLayout();
    m_quickWidgetVector.resize(quickAppRows);
    for (int i = 0; i < quickAppRows; ++i) {
        m_quickWidgetVector[i].resize(quickAppCols);
        for (int j = 0; j < quickAppCols; ++j) {
            QWidget* widget = new QWidget;
            widget->setObjectName("quickAppWidget");
            CommonTool::setStyleSheet(":/quickwidget/style/default.qss",widget);
            // 将int和QWidget*的配对存入QVector
            m_quickWidgetVector[i][j] = qMakePair(0, widget);
            m_pQuickWidgetLayout->addWidget(widget);
        }
    }
//     layout->setContentsMargins(10, 0, 10, 0); // 左、上、右、下边距
    int left, top, right, bottom;
    m_pQuickWidgetLayout->getContentsMargins(&left, &top, &right, &bottom);
    qDebug() << "当前边距: 左" << left << "上" << top << "右" << right << "下" << bottom;

    setObjectName("quickWidget");
    setLayout(m_pQuickWidgetLayout);
    //解决Widget无法设置问题
    setAttribute(Qt::WA_StyledBackground);
    CommonTool::setStyleSheet(":/quickwidget/style/default.qss",this);

}

void QuickWidget::addQuickApp(QPushButton *app,const QString &appName)
{
    auto emptyWidget = getFirstEmptyWidget();
    if(emptyWidget !=nullptr) {
        auto quickLayout = new QHBoxLayout;
        quickLayout->addWidget(app);
        quickLayout->setContentsMargins(0, 0, 0, 0);
        quickLayout->setSpacing(0);
        emptyWidget->second->setLayout(quickLayout);
        emptyWidget->first = 1;
        m_quickWidgetCnt++;
    }
}
void QuickWidget::delQuickApp(QPushButton *app)
{
    QWidget* quickWidget = findQuickWidget(app);
    if(quickWidget) {
        for (int i = 0; i < m_quickWidgetVector.size(); ++i) {
            for (int j = 0; j < m_quickWidgetVector[i].size(); ++j) {
                if (m_quickWidgetVector[i][j].second == quickWidget) {
                    m_quickWidgetVector[i][j].first = 0;
                    break;
                }
            }
        }
        auto quickLayout = quickWidget->layout();
        if (quickLayout != nullptr) {
               while (QLayoutItem *item = quickLayout->takeAt(0)) {
                   QWidget *widgetItem = item->widget();
                   if (widgetItem) {
                       widgetItem->deleteLater();
                   }
                   delete item;
               }
               delete quickLayout;
               m_quickWidgetCnt--;
        }
    }
}

QPair<int, QWidget*>* QuickWidget::getFirstEmptyWidget()
{
    for (int i = 0; i < m_quickWidgetVector.size(); ++i) {
        for (int j = 0; j < m_quickWidgetVector[i].size(); ++j) {
            if (m_quickWidgetVector[i][j].first == 0) {
                return &m_quickWidgetVector[i][j];
            }
        }
    }
    return nullptr;
}


QWidget* QuickWidget::findQuickWidget(QPushButton *app)
{
    QWidget* currentWidget = app->parentWidget();
    if(currentWidget) {
        return  currentWidget;
    }
    return nullptr;
}
