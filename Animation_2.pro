QT       += core gui openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

LIBS += -lopengl32

SOURCES += \
    AnotherClasses/AnimationSceneClass/animationscene.cpp \
    AnotherClasses/GraphClass/graph.cpp \
    Windows/Dialogs/datadialog.cpp \
    Windows/Main/main.cpp \
    Windows/Main/mainwindow.cpp \
    MathAlgorithmics/isomorphic.cpp \
    AnotherClasses/SplashClass/splashwindow.cpp \
    GraphicsItems/circle.cpp \
    GraphicsItems/label.cpp \
    GraphicsItems/vector.cpp

HEADERS += \
    AnotherClasses/AnimationSceneClass/animationscene.h \
    AnotherClasses/GraphClass/graph.h \
    Windows/Dialogs/datadialog.h \
    Windows/Main/mainwindow.h \
    MathAlgorithmics/isomorphic.h \
    AnotherClasses/SplashClass/splashwindow.h \
    GraphicsItems/circle.h \
    GraphicsItems/label.h \
    GraphicsItems/vector.h

FORMS += \
    Windows/Dialogs/datadialog.ui \
    Windows/Main/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
