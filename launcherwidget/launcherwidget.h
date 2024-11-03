#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QPushButton>
#include <QDebug>
#include <../topwidget/topwidget.h>
#include <../userwidget/userwidget.h>

class LauncherWidget : public QWidget
{
    Q_OBJECT

    static constexpr int maxAppWidgetNum = 5;

public:
    explicit LauncherWidget(QWidget *parent = nullptr);
    void addQuickApp();
    void delQuickApp();

//    void addUserWidget();
//signals:

private:
    void initLauncherWidgetUi(void);
    void initLauncherWidgetCtrl(void);


private:
    int m_appWidgetNum;
    QVBoxLayout *m_pLauncherLayout;
    TopWidget *m_pTopWidget;

    QScrollArea *m_pUserScrollArea;
    UserWidget *m_pUserWiget;
    QGridLayout *m_pUserGridLayout;

    QWidget *m_pQuickWidget;

    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;

};

#endif // LAUNCHERWIDGET_H
