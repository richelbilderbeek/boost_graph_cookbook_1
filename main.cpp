#include "bfs_name_printer.h"
#include "build_router_network.h"
#include "create_empty_graph.h"
#include "create_router_network.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "is_self_loop.h"
#include "print_trans_delay.h"
#include "print_trans_delays.h"
#include "print_vertex_name.h"
#include "print_vertex_names.h"

#include <iostream>

int main()
{
  test_bfs_name_printer();
  test_build_router_network();
  test_create_empty_graph();
  test_create_router_network();
  test_get_n_edges();
  test_get_n_vertices();
  test_is_self_loop();
  test_print_trans_delay();
  test_print_trans_delays();
  test_print_vertex_name();
  test_print_vertex_names();
  std::cout << "Done" << std::endl;
}
