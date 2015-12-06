#include "add_edge.h"
#include "add_custom_vertex.h"
#include "add_named_edge.h"
#include "add_named_vertex.h"
#include "add_vertex.h"
#include "bfs_name_printer.h"
#include "build_router_network.h"
#include "create_custom_vertices_k2_graph.h"
#include "create_empty_graph.h"
#include "create_empty_named_edges_and_vertices_graph.h"
#include "create_empty_named_vertices_graph.h"
#include "create_empty_custom_vertices_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "create_router_network_graph.h"
#include "create_router_network.h"
#include "create_tutorial_chapters_graph.h"
#include "get_edge_names.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "get_vertex_names.h"
#include "get_vertex_my_vertexes.h"
#include "is_self_loop.h"
#include "print_trans_delay.h"
#include "print_trans_delays.h"
#include "print_vertex_name.h"
#include "print_vertex_names.h"
#include "save_graph_to_dot.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "save_named_vertices_graph_to_dot.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "set_vertex_names.h"
#include <iostream>

int main()
{
  add_custom_vertex_test();
  add_edge_test();
  add_named_edge_test();
  add_named_vertex_test();
  add_vertex_test();
  bfs_name_printer_test();
  get_vertex_my_vertexes_test();
  build_router_network_test();
  create_custom_vertices_k2_graph_test();
  create_empty_custom_vertices_graph_test();
  create_empty_graph_test();
  create_empty_named_edges_and_vertices_graph_test();
  create_empty_named_vertices_graph_test();
  create_k2_graph_test();
  create_named_edges_and_vertices_k3_graph_test();
  create_named_vertices_k2_graph_test();
  create_router_network_graph_test();
  create_router_network_test();
  create_tutorial_chapters_graph_test();
  get_edge_names_test();
  get_n_edges_test();
  get_n_vertices_test();
  get_vertex_names_test();
  is_self_loop_test();
  print_trans_delays_test();
  print_trans_delay_test();
  print_vertex_names_test();
  print_vertex_name_test();
  save_graph_to_dot_test();
  save_named_edges_and_vertices_graph_to_dot_test();
  save_named_vertices_graph_to_dot_test();
  save_custom_vertices_graph_to_dot_test();
  set_vertex_names_test();
  std::cout << "Done" << std::endl;
}
