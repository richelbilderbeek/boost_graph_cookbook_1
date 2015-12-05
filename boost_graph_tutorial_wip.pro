include(../RibiLibraries/ConsoleApplication.pri)
include(../RibiLibraries/Boost.pri)
include(../RibiLibraries/GeneralConsole.pri)

HEADERS += \
  save_named_vertices_graph_to_dot.h \
  save_named_vertices_graph_to_dot_test.h

SOURCES += \
  show_dot.cpp \
  create_named_vertices_k2_graph.cpp \
  save_named_vertices_graph_to_dot_test.cpp

SOURCES += main_wip.cpp
