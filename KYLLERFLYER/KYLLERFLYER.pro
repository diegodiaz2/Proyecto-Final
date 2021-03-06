QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bala_caida.cpp \
    bala_horizontal.cpp \
    bala_parabolica.cpp \
    bala_vertical.cpp \
    dialog.cpp \
    enemigo_caminante.cpp \
    enemigo_disparador.cpp \
    enemigo_saltarin.cpp \
    enemigo_volador.cpp \
    esfera_gitatoria.cpp \
    main.cpp \
    mainwindow.cpp \
    personaje.cpp \
    poder_circular.cpp \
    poder_vida.cpp

HEADERS += \
    bala_caida.h \
    bala_horizontal.h \
    bala_parabolica.h \
    bala_vertical.h \
    dialog.h \
    enemigo_caminante.h \
    enemigo_disparador.h \
    enemigo_saltarin.h \
    enemigo_volador.h \
    esfera_gitatoria.h \
    mainwindow.h \
    personaje.h \
    poder_circular.h \
    poder_vida.h

FORMS += \
    dialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    imagenes.qrc

RC_ICONS += icon.ico
