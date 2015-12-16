include(../RibiLibraries/ConsoleApplication.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

#include(../RibiClasses/CppContainer/CppContainer.pri)
include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp
