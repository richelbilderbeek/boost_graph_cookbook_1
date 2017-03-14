INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/load_directed_graph_from_dot.h \
    $$PWD/load_undirected_graph_from_dot.h \
    $$PWD/save_graph_to_dot.h

SOURCES += \
    $$PWD/load_directed_graph_from_dot.cpp \
    $$PWD/load_undirected_graph_from_dot.cpp \
    $$PWD/save_graph_to_dot.cpp

OTHER_FILES += \
    $$PWD/load_directed_graph_from_dot.impl \
    $$PWD/load_undirected_graph_from_dot.impl \
    $$PWD/save_graph_to_dot.impl
