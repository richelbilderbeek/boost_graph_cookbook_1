HEADERS += \
  add_vertex.h \
  bfs_name_printer.h \
  build_router_network.h \
  convert_dot_to_svg.h \
  create_empty_graph.h \
  create_k2_graph.h \
  create_named_edges_and_vertices_k3_graph.h \
  create_named_vertices_k2_graph.h \
  create_router_network_graph.h \
  create_router_network.h \
  get_edge_names.h \
  get_n_edges.h \
  get_n_vertices.h \
  get_vertex_names.h \
  is_self_loop.h \
  print_trans_delay.h \
  print_trans_delays.h \
  print_vertex_name.h \
  print_vertex_names.h \
  save_graph_to_dot.h \
  save_named_edges_and_vertices_graph_to_dot.h \
  save_named_vertices_graph_to_dot.h \
  set_vertex_names.h \
  show_dot.h \
  create_tutorial_chapters_graph.h \
  add_edge.h \
  create_empty_named_vertices_graph.h \
    $$PWD/add_named_vertex.h \
    $$PWD/create_empty_named_edges_and_vertices_graph.h \
    $$PWD/add_named_edge.h

SOURCES += \
  bfs_name_printer.cpp \
  build_router_network.cpp \
  convert_dot_to_svg.cpp \
  create_empty_graph.cpp \
  create_empty_graph_test.cpp \
  create_k2_graph.cpp \
  create_k2_graph_test.cpp \
  create_named_edges_and_vertices_k3_graph.cpp \
  create_named_edges_and_vertices_k3_graph_test.cpp \
  create_named_vertices_k2_graph.cpp \
  create_named_vertices_k2_graph_test.cpp \
  create_router_network.cpp \
  create_router_network_graph.cpp \
  create_router_network_graph_test.cpp \
  get_n_edges_test.cpp \
  get_n_vertices_test.cpp \
  get_vertex_names_test.cpp \
  is_self_loop_test.cpp \
  print_trans_delays_test.cpp \
  print_trans_delay_test.cpp \
  print_vertex_names_test.cpp \
  print_vertex_name_test.cpp \
  save_graph_to_dot_test.cpp \
  save_named_edges_and_vertices_graph_to_dot_test.cpp \
  save_named_vertices_graph_to_dot_test.cpp \
  set_vertex_names_test.cpp \
  show_dot.cpp \
  add_vertex.cpp \
  create_tutorial_chapters_graph.cpp \
  add_edge.cpp \
  create_empty_named_vertices_graph.cpp \
  create_empty_named_vertices_graph_test.cpp \
    $$PWD/add_named_vertex.cpp \
    $$PWD/create_empty_named_edges_and_vertices_graph.cpp \
    $$PWD/add_named_edge.cpp \
    $$PWD/get_edge_names.cpp

# .impl files are the clean tutorial code snippets,
# without header guards and
# other housekeeping
DISTFILES += \
  add_vertex.impl \
  add_edge.impl \
  create_empty_named_vertices_graph.impl \
    $$PWD/add_named_vertex.impl \
    $$PWD/create_empty_named_edges_and_vertices_graph.impl \
    $$PWD/add_named_edge.impl
