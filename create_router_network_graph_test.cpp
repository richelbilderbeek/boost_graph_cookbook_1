#include "create_router_network_graph.h"

#include <iostream>
#include <string>



#include "print_vertex_names.h"

void create_router_network_graph_test() noexcept
{
  const auto g = create_router_network_graph();
  assert(boost::num_edges(g) == 7);
  assert(boost::num_vertices(g) == 5);
  print_vertex_names(g);
  //Check the router names and delay times
  //assert(!"Green");
  std::cout << __func__ << ": TODO" << '\n';
}




