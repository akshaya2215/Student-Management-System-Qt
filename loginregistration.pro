QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addstudent.cpp \
    main.cpp \
    mainwindow.cpp \
    management.cpp \
    searchstudent.cpp

HEADERS += \
    addstudent.h \
    mainwindow.h \
    management.h \
    searchstudent.h

FORMS += \
    addstudent.ui \
    mainwindow.ui \
    management.ui \
    searchstudent.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    .gitignore
