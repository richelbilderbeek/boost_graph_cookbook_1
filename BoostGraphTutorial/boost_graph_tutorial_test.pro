QT -= core
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
CONFIG += debug_and_release
TEMPLATE = app

CONFIG(release, debug|release) {
  DEFINES += NDEBUG
}

QMAKE_CXX = g++-5
QMAKE_LINK = g++-5
QMAKE_CC = gcc-5
QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++14

include(boost_graph_tutorial.pri)
include(boost_graph_tutorial_test.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex \
  -lboost_unit_test_framework

SOURCES += main_test.cpp

#QMAKE_MAKEFLAGS += -j
#QMAKE_CXXFLAGS += -j4
#QMAKE_CXX = ccache g++
