#ifndef LOCKWIDGET_H
#define LOCKWIDGET_H

#include <QWidget>
#include <QPixmap>
#include <QPalette>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QScroller>
#include <iostream>
#include <QScrollBar>
#include "../commontool.h"
#include "../topwidget/topwidget.h"


class LockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit LockWidget(QWidget *parent = nullptr);
    void updateDateText(const QString &text);
    void updateClockText(const QString &text);

signals:
    void lockToLanuchWidget();


private:
    void initLockWidgetUi(void);
    void initLockWidgetCtrl(void);
    QWidget* bodyWidgetInit(void);


private slots:
    void emitSignal(void) {
        emit lockToLanuchWidget();
    }
    void onCameraClicked(void) {
        std::cout<<"打开相机"<<std::endl;
    }
    void onLedClicked(void) {
        std::cout<<"打开闪光灯"<<std::endl;
    }
    void onScrollerStateChanged(void) {
        /*3:表示的状态是？*/
        if(QScroller::scroller(m_BodyScrollArea)->state() == 3){
            int Value = m_BodyScrollArea->verticalScrollBar()->sliderPosition();
            if(Value > 3) {
               std::cout<<"verticalScrollBar up:"<<std::endl;
                emitSignal();
            }
            else {
                std::cout<<"verticalScrollBar down:"<<std::endl;
            }
        }
    }


private:
    /*lockwidget-top:  topWidget */
    TopWidget *m_pTopWidget;

    /*lockwidget-body: bodyScrollArea  */
    QScrollArea *m_BodyScrollArea;
    QWidget *m_BodyWidget;


    /*lockwidget-lock picture: lockLabel*/
    QLabel *m_pLockUp,*m_pLockDown;

    /*lockwidget-times: DateLabel and ClockLabel*/
    QLabel *m_pDate;
    QLabel *m_pClock;


    /*lockwidget-tools:  CameraButton  and LedButton*/
    QPushButton* m_pCameraButton;
    QPushButton* m_pLedButton;

    /*lockwidget layout: layout */
    QVBoxLayout *m_pMainLayout;


};

#endif // LOCKWIDGET_H
