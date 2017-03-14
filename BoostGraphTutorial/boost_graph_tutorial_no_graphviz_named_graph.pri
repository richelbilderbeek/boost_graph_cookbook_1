INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/create_empty_directed_graph_with_graph_name.h \
    $$PWD/create_empty_undirected_graph_with_graph_name.h \
    $$PWD/create_k2_graph_with_graph_name.h \
    $$PWD/create_markov_chain_with_graph_name.h \
    $$PWD/get_graph_name.h \
    $$PWD/set_graph_name.h

SOURCES += \
    $$PWD/create_empty_directed_graph_with_graph_name.cpp \
    $$PWD/create_empty_undirected_graph_with_graph_name.cpp \
    $$PWD/create_k2_graph_with_graph_name.cpp \
    $$PWD/create_markov_chain_with_graph_name.cpp \
    $$PWD/get_graph_name.cpp \
    $$PWD/set_graph_name.cpp

OTHER_FILES += \
    $$PWD/create_empty_directed_graph_with_graph_name.impl \
    $$PWD/create_empty_undirected_graph_with_graph_name.impl \
    $$PWD/create_k2_graph_with_graph_name.impl \
    $$PWD/create_markov_chain_with_graph_name.impl \
    $$PWD/get_graph_name.impl \
    $$PWD/set_graph_name.impl
