#ifndef USERWIDGET_H
#define USERWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include <QVector>
#include <QPushButton>
#include <QHBoxLayout>
#include "../commontool.h"

class UserWidget : public QWidget
{
    Q_OBJECT
    static constexpr int userAppRows = 5;
    static constexpr int userAppCols = 4;
public:
    explicit UserWidget(QWidget *parent = nullptr);
    int isUserWidgetFull();

    void addUserApp(QPushButton *app,const QString &appName);
    void delUserApp(QPushButton *app);

private:
    void initUserWidgetUi(void);
    QPair<int, QWidget*>* getFirstEmptyWidget();
    QWidget* findAppWidget(QPushButton *app);

private:
    QGridLayout *m_pUserGridLayout;
    QVector<QVector<QPair<int, QWidget*>>> m_userWidgetVector;

    QPushButton *cameraButton;
    int m_appWidgetCnt;
};

#endif // USERWIDGET_H
