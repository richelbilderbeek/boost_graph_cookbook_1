HEADERS += \
    $$PWD/create_bundled_edges_and_vertices_k3_graph.h \
    $$PWD/create_bundled_edges_and_vertices_markov_chain.h \
    $$PWD/create_empty_directed_bundled_edges_and_vertices_graph.h \
    $$PWD/create_empty_undirected_bundled_edges_and_vertices_graph.h \
    $$PWD/create_nasty_directed_bundled_edges_and_vertices_graph.h \
    $$PWD/create_nasty_undirected_bundled_edges_and_vertices_graph.h

SOURCES += \
    $$PWD/create_bundled_edges_and_vertices_k3_graph.cpp \
    $$PWD/create_bundled_edges_and_vertices_markov_chain.cpp \
    $$PWD/create_empty_directed_bundled_edges_and_vertices_graph.cpp \
    $$PWD/create_empty_undirected_bundled_edges_and_vertices_graph.cpp

OTHER_FILES += \
    $$PWD/create_bundled_edges_and_vertices_k3_graph.impl \
    $$PWD/create_bundled_edges_and_vertices_markov_chain.impl \
    $$PWD/create_empty_directed_bundled_edges_and_vertices_graph.impl \
    $$PWD/create_empty_undirected_bundled_edges_and_vertices_graph.impl \
    $$PWD/load_directed_bundled_edges_and_vertices_graph_from_dot.impl \
    $$PWD/load_undirected_bundled_edges_and_vertices_graph_from_dot.impl \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.impl
