#ifndef APPBUTTON_H
#define APPBUTTON_H

#include <QObject>
#include <QPushButton>
#include <QPainter>
#include <QPixmap>
#include <QPainterPath>

#include "commontool.h"
class AppButton : public QPushButton {
    Q_OBJECT

public:
    AppButton(const QString &imagePath, QWidget *parent = nullptr)
        : QPushButton(parent), m_imagePath(imagePath) {
        this->setObjectName("appBtn");
        CommonTool::setStyleSheet(":/resources/style/default.qss", this);
    }

protected:
    void paintEvent(QPaintEvent *event) override {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);

        // 创建一个圆角矩形的路径
        QPainterPath path;
        path.addRoundedRect(rect(), 20, 20); // 设置圆角半径为 20

        // 设置剪切区域
        painter.setClipPath(path);

        // 绘制背景图像
        QPixmap pixmap(m_imagePath); // 替换为你的图片路径
        if (!pixmap.isNull()) {
            // 将图像缩放到按钮的大小
            painter.drawPixmap(rect(), pixmap.scaled(size(), Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
        }
    }

private:
    QString m_imagePath; // 存储图像路径
};

#endif // APPBUTTON_H
