INCLUDEPATH += $$PWD

INCLUDEPATH += $$PWD

HEADERS += \
    $$PWD/convert_dot_to_svg.h \
    $$PWD/convert_svg_to_png.h \
    $$PWD/copy_file.h \
    $$PWD/file_to_vector.h \
    $$PWD/get_bits.h \
    $$PWD/get_type_name.h \
    $$PWD/graphviz_decode.h \
    $$PWD/graphviz_encode.h \
    $$PWD/has_dot.h \
    $$PWD/is_graphviz_friendly.h \
    $$PWD/is_regular_file.h \
    $$PWD/is_valid_dot_file.h \
    $$PWD/seperate_string.h \
    $$PWD/show_dot.h

SOURCES += \
    $$PWD/convert_dot_to_svg.cpp \
    $$PWD/convert_svg_to_png.cpp \
    $$PWD/copy_file.cpp \
    $$PWD/file_to_vector.cpp \
    $$PWD/get_bits.cpp \
    $$PWD/get_type_name.cpp \
    $$PWD/graphviz_decode.cpp \
    $$PWD/graphviz_encode.cpp \
    $$PWD/has_dot.cpp \
    $$PWD/is_graphviz_friendly.cpp \
    $$PWD/is_regular_file.cpp \
    $$PWD/is_valid_dot_file.cpp \
    $$PWD/seperate_string.cpp \
    $$PWD/show_dot.cpp

OTHER_FILES += \
    $$PWD/convert_dot_to_svg.impl \
    $$PWD/get_type_name.impl \
    $$PWD/graphviz_decode.impl \
    $$PWD/graphviz_encode.impl \
    $$PWD/is_regular_file.impl \
    $$PWD/is_graphviz_friendly.impl \
    $$PWD/is_valid_dot_file.impl
