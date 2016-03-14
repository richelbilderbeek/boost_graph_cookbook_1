QT -= core
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += debug_and_release
# CONFIG += c++11
TEMPLATE = app

CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++11

include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp

#QMAKE_MAKEFLAGS += -j
#QMAKE_CXXFLAGS += -j4
#QMAKE_CXX = ccache g++
