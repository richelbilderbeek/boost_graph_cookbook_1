INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/add_named_and_selectable_vertex.h \
    $$PWD/create_empty_directed_named_and_selectable_vertices_graph.h \
    $$PWD/create_empty_undirected_named_and_selectable_vertices_graph.h

SOURCES += \
    $$PWD/add_named_and_selectable_vertex.cpp \
    $$PWD/create_empty_directed_named_and_selectable_vertices_graph.cpp \
    $$PWD/create_empty_undirected_named_and_selectable_vertices_graph.cpp

OTHER_FILES += \
    $$PWD/add_named_and_selectable_vertex.impl \
    $$PWD/create_empty_directed_named_and_selectable_vertices_graph.impl \
    $$PWD/create_empty_undirected_named_and_selectable_vertices_graph.impl
