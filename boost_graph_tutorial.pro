include(../RibiLibraries/ConsoleApplication.pri)
include(../RibiLibraries/Boost.pri)

include(boost_graph_tutorial.pri)

LIBS += \
  -lboost_graph \
  -lboost_regex

SOURCES += main.cpp
