message(Host name: $$QMAKE_HOST.name)
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror

# Determine which C++
message(Host name: $$QMAKE_HOST.name)
contains(QMAKE_HOST.name,druten) {
  message("C++17: Host is Lubuntu desktop from Druten")
  QMAKE_CXXFLAGS += -std=c++17
}
!contains(QMAKE_HOST.name,druten) {
  message("C++11: Host is Lubuntu desktop from Druten")
  QMAKE_CXXFLAGS += -std=c++11
}

QT -= core
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

### BOOST

win32 {
  # Windows only (untested)
  message("Boost, built for Windows")f
  INCLUDEPATH += C:\boost_1_59_0
}

macx {
  # Mac only (untested)
  message("Boost, built for Mac")
  INCLUDEPATH += \
    ../../Libraries/boost_1_56_0
}

unix:!macx {
  # Linux only
  message("Boost, built for Linux")
  # Always linked to?
}

include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp

#QMAKE_MAKEFLAGS += -j
#QMAKE_CXXFLAGS += -j4
#QMAKE_CXX = ccache g++
