#include "create_router_network.h"

#include <iostream>

#include "build_router_network.h"
#include "create_empty_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

boost::adjacency_list<
  boost::listS,    // Store out-edges of each vertex in a std::list
  boost::vecS,     // Store vertices in a std::vector
  boost::directedS // The graph is directed
>
create_router_network() noexcept
{
  using my_graph = boost::adjacency_list<boost::listS,boost::vecS,boost::directedS>;
  using my_edge_descriptor = my_graph::edge_descriptor;
  using my_vertex_descriptor = my_graph::vertex_descriptor;
  my_graph g = create_empty_graph();
  std::map<my_vertex_descriptor,std::string> router_names;
  std::map<my_edge_descriptor,int> delay_map;
  build_router_network(g,router_names,delay_map);
  return g;
}

void test_create_router_network() noexcept
{
  const auto g = create_router_network();
  assert(get_n_edges(g) == 7);
  assert(get_n_vertices(g) == 5);
  std::cout << __func__ << ": OK" << '\n';
}


