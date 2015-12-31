message(Host name: $$QMAKE_HOST.name)
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror

# Determine which C++
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

QT -= core
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
TEMPLATE = app

### BOOST

win32 {
  # Windows only (untested)
  message("Boost, built for Windows")
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

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += stack_overflow_question.cpp
