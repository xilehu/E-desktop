#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QStackedWidget>
#include <QTimer>
#include <QDateTime>
#include <QDialog>
#include <QStackedWidget>
#include <QIcon>
#include <QPainter>

#include "./lockwidget/lockwidget.h"
#include "./launcherwidget/launcherwidget.h"
#include "./topwidget/topwidget.h"
#include "appbutton.h"
#include "./userapp/cameraApp/cameraapp.h"

class MainWidget : public QWidget
{
    Q_OBJECT

    static constexpr int m_screenWidth = 800;
    static constexpr int m_screenHeigh = 1280;
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void initMainWidgetUi(void);
    void initMainWidgetCtrl(void);
    void setBackground(const QPixmap &pixmap);
    void installSystemApp();
    void installQuickApp();

private slots:
    void lockToLaunchChange();
    void systemTimeChange();
    void cameraBtnClicked();
private:
    QTimer *m_pTime;

    TopWidget *m_pTopWidget;
    QVBoxLayout *m_pMainLayout;
    QStackedWidget *m_pStackedWidget;

    LauncherWidget *m_pLauncherWidget;
    QVBoxLayout *m_pLanuchLayout;

    LockWidget *m_pLockWidget;
    QVBoxLayout *m_pLockLayout;

    QDialog  *m_pAppWidget = nullptr;

};
#endif // WIDGET_H
