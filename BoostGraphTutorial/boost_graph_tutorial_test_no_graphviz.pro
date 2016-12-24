include(any_test.pri)

DEFINES += BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

include(boost_graph_tutorial.pri)
include(boost_graph_tutorial_test.pri)

#LIBS += -lboost_regex

SOURCES += main_test.cpp

