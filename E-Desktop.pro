QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    commontool.cpp \
    launcherwidget/launcherwidget.cpp \
    lockwidget/lockwidget.cpp \
    main.cpp \
    mainwidget.cpp \
    quickwidget/quickwidget.cpp \
    topwidget/topwidget.cpp \
    userapp/cameraApp/cameraapp.cpp \
    userwidget/userwidget.cpp

HEADERS += \
    appbutton.h \
    commontool.h \
    launcherwidget/launcherwidget.h \
    lockwidget/lockwidget.h \
    mainwidget.h \
    quickwidget/quickwidget.h \
    topwidget/topwidget.h \
    userapp/cameraApp/cameraapp.h \
    userwidget/userwidget.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

