include(../RibiLibraries/ConsoleApplication.pri)
include(../RibiLibraries/Boost.pri)

SOURCES += main.cpp \
    bfs_name_printer.cpp


HEADERS += \
  build_router_network.h \
  is_self_loop.h \
  print_trans_delay.h \
  print_trans_delays.h \
  print_vertex_name.h \
  print_vertex_names.h \
    bfs_name_printer.h

SOURCES += \
  build_router_network.cpp \
  is_self_loop.cpp \
  print_trans_delay.cpp \
  print_trans_delays.cpp \
  print_vertex_name.cpp \
  print_vertex_names.cpp

