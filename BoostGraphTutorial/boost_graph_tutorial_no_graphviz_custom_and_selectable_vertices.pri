# This .pri file includes all files that do not use Graphviz
INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs.h \
    $$PWD/create_custom_and_selectable_vertices_k2_graph.h \
    $$PWD/create_custom_and_selectable_vertices_k3_graph.h \
    $$PWD/create_custom_and_selectable_vertices_markov_chain.h \
    $$PWD/create_custom_and_selectable_vertices_path_graph.h \
    $$PWD/create_custom_and_selectable_vertices_petersen_graph.h \
    $$PWD/create_direct_neighbour_custom_and_selectable_vertices_subgraph.h \
    $$PWD/create_empty_directed_custom_and_selectable_vertices_graph.h \
    $$PWD/create_empty_undirected_custom_and_selectable_vertices_graph.h \
    $$PWD/create_nasty_directed_custom_and_selectable_vertices_graph.h \
    $$PWD/create_nasty_undirected_custom_and_selectable_vertices_graph.h \
    $$PWD/custom_and_selectable_vertices_writer.h \
    $$PWD/make_custom_and_selectable_vertices_writer.h

SOURCES += \
    $$PWD/create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs.cpp \
    $$PWD/create_custom_and_selectable_vertices_k2_graph.cpp \
    $$PWD/create_custom_and_selectable_vertices_k3_graph.cpp \
    $$PWD/create_custom_and_selectable_vertices_markov_chain.cpp \
    $$PWD/create_custom_and_selectable_vertices_path_graph.cpp \
    $$PWD/create_custom_and_selectable_vertices_petersen_graph.cpp \
    $$PWD/create_direct_neighbour_custom_and_selectable_vertices_subgraph.cpp \
    $$PWD/create_empty_directed_custom_and_selectable_vertices_graph.cpp \
    $$PWD/create_empty_undirected_custom_and_selectable_vertices_graph.cpp \
    $$PWD/create_nasty_directed_custom_and_selectable_vertices_graph.cpp \
    $$PWD/create_nasty_undirected_custom_and_selectable_vertices_graph.cpp \
    $$PWD/custom_and_selectable_vertices_writer.cpp \
    $$PWD/make_custom_and_selectable_vertices_writer.cpp

OTHER_FILES += \
    $$PWD/create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs.impl \
    $$PWD/create_custom_and_selectable_vertices_k2_graph.impl \
    $$PWD/create_custom_and_selectable_vertices_k3_graph.impl \
    $$PWD/create_custom_and_selectable_vertices_markov_chain.impl \
    $$PWD/create_custom_and_selectable_vertices_path_graph.impl \
    $$PWD/create_custom_and_selectable_vertices_petersen_graph.impl \
    $$PWD/create_direct_neighbour_custom_and_selectable_vertices_subgraph.impl \
    $$PWD/create_empty_directed_custom_and_selectable_vertices_graph.impl \
    $$PWD/create_empty_undirected_custom_and_selectable_vertices_graph.impl \
    $$PWD/custom_and_selectable_vertices_writer.impl \
    $$PWD/load_directed_custom_and_selectable_vertices_graph_from_dot.impl \
    $$PWD/load_undirected_custom_and_selectable_vertices_graph_from_dot.impl \
    $$PWD/make_custom_and_selectable_vertices_writer.impl \
    $$PWD/save_custom_and_selectable_vertices_graph_to_dot.impl
