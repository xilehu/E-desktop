#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QVBoxLayout>
#include <QScrollArea>
#include <QStackedWidget>

#include <./lockwidget/lockwidget.h>
//#include <./topwidget/topwidget.h>



class MainWidget : public QWidget
{
    Q_OBJECT

    static constexpr int m_screenWidth = 800/2;
    static constexpr int m_screenHeigh = 1280/2;
public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    void initMainWidgetUi(void);
    void initMainWidgetCtrl(void);
    void setBackground(const QPixmap &pixmap);


private slots:
    void lockToLaunchChange();

private:

    QVBoxLayout *m_pMainLayout;
    QStackedWidget *m_pStackedWidget;

    QWidget *m_pLanuchWidget;
    QVBoxLayout *m_pLanuchLayout;
    QPushButton *m_pLanuchButton;


    LockWidget *m_pLockWidget;
    QVBoxLayout *m_pLockLayout;



};
#endif // WIDGET_H
