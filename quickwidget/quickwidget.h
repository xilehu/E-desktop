#ifndef QUICKWIDGET_H
#define QUICKWIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVector>
#include <QPushButton>
#include "../commontool.h"
#include <QDebug>

class QuickWidget : public QWidget
{
    Q_OBJECT
    static constexpr int quickAppRows = 1;
    static constexpr int quickAppCols = 4;
public:
    explicit QuickWidget(QWidget *parent = nullptr);
    int isQuickWidgetFull();

    void addQuickApp(QPushButton *app,const QString &appName);
    void delQuickApp(QPushButton *app);

private:
    void initQuickWidgetUi(void);
    QPair<int, QWidget*>* getFirstEmptyWidget();
    QWidget* findQuickWidget(QPushButton *app);

private:
    QHBoxLayout *m_pQuickWidgetLayout;
    QVector<QVector<QPair<int, QWidget*>>> m_quickWidgetVector;
    int m_quickWidgetCnt;
};

#endif // QUICKWIDGET_H
