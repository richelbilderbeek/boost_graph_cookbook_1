QT -= core
QT -= gui
CONFIG   += console
CONFIG   -= app_bundle
# CONFIG += c++11
TEMPLATE = app

# Use a new version
QMAKE_CXX = g++-4.8
QMAKE_CC = gcc-4.8

QMAKE_CXXFLAGS += -Wall -Wextra -Weffc++ -Werror -std=c++11

include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp

#QMAKE_MAKEFLAGS += -j
#QMAKE_CXXFLAGS += -j4
#QMAKE_CXX = ccache g++
