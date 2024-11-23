#ifndef CAMERAAPP_H
#define CAMERAAPP_H

#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraViewfinder>
#include <QComboBox>
#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QScopedPointer>
#include <QTimer>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QEvent>
#include <QCameraInfo>
#include <QCoreApplication>


class CameraApp : public QDialog
{
    Q_OBJECT
public:
    explicit CameraApp(QWidget *parent = nullptr);

private:
    void initUi();
    void initCtrl();

protected:
    bool eventFilter(QObject *o, QEvent *e);

protected slots:
    void updateCamInfo();
    void switchCamBtnClicked();
    void takePhotoBtnClicked();
    void takeVedioBtnClicked();
    void camResBoxChanged(int index);
    void displayCameraError();
private:
    QWidget m_ctrlWidget;
    QComboBox m_camComBox;
    QComboBox m_camResBox;
    QPushButton m_switchBtn;
    QPushButton m_takePhotoBtn;
    QPushButton m_takeVideoBtn;
    QPushButton m_camScanBtn;
    QLabel m_stateLbl;
    QCameraViewfinder m_cameraViewfinder;

    QScopedPointer<QCameraImageCapture> m_imageCapture;
    QScopedPointer<QCamera> m_camera;
    QTimer m_timer;

};

#endif // CAMERAAPP_H
