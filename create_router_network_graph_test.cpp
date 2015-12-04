#include "create_router_network_graph.h"

#include <iostream>
#include <string>

#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "print_vertex_names.h"

void create_router_network_graph_test() noexcept
{
  const auto g = create_router_network_graph();
  assert(get_n_edges(g) == 7);
  assert(get_n_vertices(g) == 5);
  print_vertex_names(g);
  //Check the router names and delay times
  //assert(!"Green");
  std::cout << __func__ << ": TODO" << '\n';
}




