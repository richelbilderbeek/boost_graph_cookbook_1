#include "bfs_name_printer.h"
#include "build_router_network.h"
#include "create_empty_graph.h"
#include "create_k2_graph.h"
#include "create_named_vertices_k2_graph_test.h"
#include "create_named_edges_and_vertices_k3_graph_test.h"
#include "create_router_network_graph.h"
#include "create_router_network.h"
#include "get_n_edges_test.h"
#include "get_n_vertices_test.h"
#include "get_edge_names_test.h"
#include "get_vertex_names_test.h"
#include "is_self_loop.h"
#include "print_trans_delay.h"
#include "print_trans_delays.h"
#include "print_vertex_name.h"
#include "print_vertex_names.h"
#include "set_vertex_names_test.h"
#include <iostream>

int main()
{
  bfs_name_printer_test();
  build_router_network_test();
  create_empty_graph_test();
  create_k2_graph_test();
  create_named_edges_and_vertices_k3_graph_test();
  create_named_vertices_k2_graph_test();
  create_router_network_graph_test();
  create_router_network_test();
  get_edge_names_test();
  get_n_edges_test();
  get_n_vertices_test();
  get_vertex_names_test();
  is_self_loop_test();
  print_trans_delays_test();
  print_trans_delay_test();
  print_vertex_names_test();
  print_vertex_name_test();
  set_vertex_names_test();
  std::cout << "Done" << std::endl;
}
