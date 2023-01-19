QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    okno_dialogowe.cpp \
    panel_dostep_do_sali.cpp \
    panel_logowania.cpp \
    panel_potwierdzania_przegladu.cpp \
    panel_technika.cpp \
    panel_wyswietlania_rezerwacji.cpp \
    panel_zglaszania_awarii.cpp

HEADERS += \
    mainwindow.h \
    okno_dialogowe.h \
    panel_dostep_do_sali.h \
    panel_logowania.h \
    panel_potwierdzania_przegladu.h \
    panel_technika.h \
    panel_wyswietlania_rezerwacji.h \
    panel_zglaszania_awarii.h

FORMS += \
    mainwindow.ui \
    okno_dialogowe.ui \
    panel_dostep_do_sali.ui \
    panel_logowania.ui \
    panel_potwierdzania_przegladu.ui \
    panel_technika.ui \
    panel_wyswietlania_rezerwacji.ui \
    panel_zglaszania_awarii.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
