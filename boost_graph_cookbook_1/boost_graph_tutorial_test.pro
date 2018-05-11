
include(any_test.pri)

include(boost_graph_tutorial.pri)
include(boost_graph_tutorial_test.pri)

SOURCES += main_test.cpp
QMAKE_LFLAGS += -fuse-ld=gold

# Use Graphviz
LIBS += -lboost_graph
