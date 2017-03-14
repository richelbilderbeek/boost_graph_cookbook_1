INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/bundled_edges_writer.h \
    $$PWD/load_directed_bundled_edges_and_vertices_graph_from_dot.h \
    $$PWD/load_undirected_bundled_edges_and_vertices_graph_from_dot.h \
    $$PWD/make_bundled_edges_writer.h \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.h

SOURCES += \
    $$PWD/load_directed_bundled_edges_and_vertices_graph_from_dot.cpp \
    $$PWD/load_undirected_bundled_edges_and_vertices_graph_from_dot.cpp \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.cpp


OTHER_FILES +=  \
    $$PWD/bundled_edges_writer.impl \
    $$PWD/load_directed_bundled_edges_and_vertices_graph_from_dot.impl \
    $$PWD/load_undirected_bundled_edges_and_vertices_graph_from_dot.impl \
    $$PWD/make_bundled_edges_writer.impl \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.impl
