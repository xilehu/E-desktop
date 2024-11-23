#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QScroller>
#include <QDebug>
#include <iostream>
#include "../topwidget/topwidget.h"
#include "../userwidget/userwidget.h"
#include "../quickwidget/quickwidget.h"

class LauncherWidget : public QWidget
{
    Q_OBJECT

    static constexpr int maxAppWidgetNum = 5;

public:
    explicit LauncherWidget(QWidget *parent = nullptr);
    void addUserApp(QPushButton *app,const QString &appName);
    void delUserApp(QPushButton *app);
    void addQuickApp(QPushButton *app,const QString &appName);
    void delQuickApp(QPushButton *app);

private:
    void initLauncherWidgetUi(void);
    void initLauncherWidgetCtrl(void);


private:
//    int m_appWidgetNum;
    QVBoxLayout *m_pLauncherLayout;

    TopWidget *m_pTopWidget;

    QScrollArea *m_pUserScrollArea;
    UserWidget *m_pUserWiget;
    QGridLayout *m_pUserGridLayout;

    QuickWidget *m_pQuickWidget;



};

#endif // LAUNCHERWIDGET_H
