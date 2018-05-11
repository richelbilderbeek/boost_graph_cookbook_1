include(any_test.pri)

DEFINES += BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

include(boost_graph_tutorial_no_graphviz.pri)
include(boost_graph_tutorial_test_no_graphviz.pri)

#LIBS += -lboost_regex
QMAKE_LFLAGS += -fuse-ld=gold

SOURCES += main_test.cpp

