INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/bundled_edges_writer.h \
    $$PWD/convert_dot_to_svg.h \
    $$PWD/make_bundled_edges_writer.h \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.h

SOURCES += \
    $$PWD/convert_dot_to_svg.cpp \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.cpp

# .impl files are the clean tutorial code snippets,
# without header guards and other housekeeping
OTHER_FILES += \
    $$PWD/bundled_edges_writer.impl \
    $$PWD/convert_dot_to_svg.impl \
    $$PWD/make_bundled_edges_writer.impl \
    $$PWD/save_bundled_edges_and_vertices_graph_to_dot.impl
