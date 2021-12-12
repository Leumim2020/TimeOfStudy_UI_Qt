QT       += core gui multimedia
 QT_QPA_PLATFORM=wayland
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    form02.cpp \
    form3.cpp \
    main.cpp \
    form1.cpp

HEADERS += \
    form02.h \
    form1.h \
    form3.h

FORMS += \
    form02.ui \
    form1.ui \
    form3.ui
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    filesMidia.qrc

DISTFILES += \
    arquivos de texto/mensagem.txt
