HEADERS += \
  bfs_name_printer.h \
  create_empty_graph.h \
  is_self_loop.h \
  get_n_vertices_test.h \
  print_trans_delay.h \
  print_trans_delays.h \
  print_vertex_name.h \
  print_vertex_names.h \
  get_n_edges.h \
  get_n_vertices.h \
    $$PWD/create_router_network.h \
    $$PWD/build_router_network.h \
    $$PWD/create_router_network_graph.h \
    create_k2_graph.h \
    get_n_edges_test.h \
    create_named_vertices_k2_graph.h \
    create_named_vertices_k2_graph_test.h \
    get_vertex_names.h \
    get_vertex_names_test.h \
    set_vertex_names.h \
    set_vertex_names_test.h \
    $$PWD/add_vertex.h \
    $$PWD/create_named_edges_and_vertices_k3_graph.h \
    $$PWD/create_named_edges_and_vertices_k3_graph_test.h \
    $$PWD/get_edge_names.h \
    $$PWD/get_edge_names_test.h \
    $$PWD/save_graph_to_dot.h \
    $$PWD/save_graph_to_dot_test.h \
    $$PWD/show_dot.h \
    $$PWD/save_named_vertices_graph_to_dot.h \
    $$PWD/save_named_vertices_graph_to_dot_test.h \
    $$PWD/save_named_edges_and_vertices_graph_to_dot_test.h



SOURCES += \
  bfs_name_printer.cpp \
  create_empty_graph.cpp \
  get_n_vertices_test.cpp \
    $$PWD/create_router_network.cpp \
    $$PWD/build_router_network.cpp \
    $$PWD/create_router_network_graph.cpp \
    create_empty_graph_test.cpp \
    create_router_network_graph_test.cpp \
    create_k2_graph.cpp \
    create_k2_graph_test.cpp \
    get_n_edges_test.cpp \
    create_named_vertices_k2_graph.cpp \
    create_named_vertices_k2_graph_test.cpp \
    get_vertex_names_test.cpp \
    print_vertex_names_test.cpp \
    print_vertex_name_test.cpp \
    print_trans_delay_test.cpp \
    print_trans_delays_test.cpp \
    is_self_loop_test.cpp \
    set_vertex_names_test.cpp \
    $$PWD/create_named_edges_and_vertices_k3_graph.cpp \
    $$PWD/create_named_edges_and_vertices_k3_graph_test.cpp \
    $$PWD/get_edge_names_test.cpp \
    $$PWD/save_graph_to_dot_test.cpp \
    $$PWD/show_dot.cpp \
    $$PWD/save_named_vertices_graph_to_dot_test.cpp \
    $$PWD/save_named_edges_and_vertices_graph_to_dot_test.cpp
