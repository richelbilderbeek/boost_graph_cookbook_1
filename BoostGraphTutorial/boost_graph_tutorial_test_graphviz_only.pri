INCLUDEPATH += $$PWD

HEADERS +=

SOURCES += \
    $$PWD/bundled_edges_writer_test.cpp \
    $$PWD/create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs_test_graphviz.cpp \
    $$PWD/create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_test_graphviz.cpp \
    $$PWD/convert_dot_to_svg_test.cpp \
    $$PWD/make_bundled_edges_writer_test.cpp \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot_test.cpp

# .impl files are the clean tutorial code snippets,
# without header guards and other housekeeping
OTHER_FILES += \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot_demo.impl
