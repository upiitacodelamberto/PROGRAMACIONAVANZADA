TARGET = MJ_Translator #what you want to call your exe

#add the name of your source files
SOURCES += \
    main.cpp
#HEADERS += headername.h # add the name of your header file

QT       += core gui   #for using qtcore and qtgui stuff

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets  #for qt5
