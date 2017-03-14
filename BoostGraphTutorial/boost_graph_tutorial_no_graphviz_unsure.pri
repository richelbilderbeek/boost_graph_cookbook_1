HEADERS += \
    $$PWD/create_tutorial_chapters_graph.h \
    $$PWD/create_tutorial_subchapters_graph.h

SOURCES += \
    $$PWD/graphviz_decode.cpp \
    $$PWD/graphviz_encode.cpp \
    $$PWD/is_graphviz_friendly.cpp

OTHER_FILES += \
    $$PWD/convert_dot_to_svg.impl \
    $$PWD/formed_reference_to_void.impl \
    $$PWD/graphviz_decode.impl \
    $$PWD/graphviz_encode.impl \
    $$PWD/is_graphviz_friendly.impl \
    $$PWD/property_not_found_node_id.impl
