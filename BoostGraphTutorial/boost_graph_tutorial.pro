win32 {
  # Windows only
  message("Console application, built for Windows")
  QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Weffc++
}

macx {
  # Mac only
  message("Console application, built for Mac")
  QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc+
  CONFIG +=c++11
}

unix:!macx{
  # Linux only
  message("Console application, built for Linux")
  message(Host name: $$QMAKE_HOST.name)

  QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror

  message(Host name: $$QMAKE_HOST.name)
  contains(QMAKE_HOST.name,fwn-biol-132-102) {
    message("C++1y: Host is university computer (my place)")
    QMAKE_CXXFLAGS += -std=c++1y
  }
  contains(QMAKE_HOST.name,fwn-biol-144-131) {
    message("C++1y: Host is university computer (G's place)")
    QMAKE_CXXFLAGS += -std=c++1y
  }
  contains(QMAKE_HOST.name,pg-login) {
    message("C++1y: Host is Peregrine cluster")
    QMAKE_CXXFLAGS += -std=c++1y
  }
  contains(QMAKE_HOST.name,maakplek-PC2) {
    message("C++1y: Host is Lubunt maakplek computer")
    QMAKE_CXXFLAGS += -std=c++1y
  }
  contains(QMAKE_HOST.name,maakplek-PC6-lubuntu) {
    message("C++17: Host is Lubunt maakplek computer")
    QMAKE_CXXFLAGS += -std=c++17
  }
  contains(QMAKE_HOST.name,lubuntu-laptop-rotterdam) {
    message("C++17: Host is Lubunt laptop from Rotterdam")
    QMAKE_CXXFLAGS += -std=c++17
  }
}

cross_compile {
  # Crosscompile only
  message("Console application, cross-compiling from Linux to Windows")
  QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra -Weffc++
}


# Go ahead and use Qt.Core: it is about as platform-independent as
# the STL and Boost
QT += core

# Go ahead and use Qt.Gui: it is about as platform-independent as
# the STL and Boost. It is needed for QImage
QT += gui

# Don't define widgets: it would defy the purpose of this console
# application to work non-GUI
#greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

#
#
# Type of compile
#
#

CONFIG(release, debug|release) {
  DEFINES += NDEBUG NTRACE_BILDERBIKKEL
}


### BOOST

win32 {
  # Windows only
  message("Boost, built for Windows")
  INCLUDEPATH += C:\boost_1_59_0
}

macx {
  # Mac only
  message("Boost, built for Mac")
  INCLUDEPATH += \
    ../../Libraries/boost_1_56_0
}

unix:!macx {
  # Linux only
  message("Boost, built for Linux")
}

cross_compile {
  # Crosscompile only
  message("Boost, built for cross-compiling from Linux to Windows")
}


include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp
