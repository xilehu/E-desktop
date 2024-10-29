#ifndef COMMONTOOL_H
#define COMMONTOOL_H

#include <QObject>
#include <QFile>
#include <QImage>
#include <QWidget>
#include <QApplication>

class CommonTool : public QObject
{
public:
    CommonTool() =delete;
    CommonTool(const CommonTool&) = delete;
    CommonTool &operator=(const CommonTool&) = delete;

    // 设置皮肤样式
    static void setStyleSheet(const QString &styleSheet, QObject *widget)
    {
        QFile file(styleSheet);
        if (file.open(QIODevice::ReadOnly))
        {
            QWidget *ptr = qobject_cast<QWidget *>(widget);
            if (ptr) {
                ptr->setStyleSheet(file.readAll());
            }
            else {
                qApp->setStyleSheet(file.readAll());
            }

            file.close();
        }
    }

    //切换皮肤颜色
    static QImage replaceWhiteWithTransparent(const QImage& image)
    {
        QImage newImage = image;
        for (int y = 0; y < newImage.height(); ++y) {
            for (int x = 0; x < newImage.width(); ++x) {
                QColor color = newImage.pixelColor(x, y);
                if (color == Qt::white) { // 或者使用 color.rgb() == qRgb(255, 255, 255)
                    newImage.setPixelColor(x, y, QColor(0, 0, 0, 0)); // 透明色，RGB 不重要，alpha 为 0
                }
            }
        }
        return newImage;
    }

};

#endif // COMMONTOOL_H
