#include "build_router_network.h"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_directed_graph.h"



void build_router_network_test() noexcept
{
  using my_graph = boost::adjacency_list<>;
  using my_edge_descriptor = my_graph::edge_descriptor;
  using my_vertex_descriptor = my_graph::vertex_descriptor;
  my_graph g = create_empty_directed_graph();
  std::map<my_vertex_descriptor,std::string> router_names;
  std::map<my_edge_descriptor,int> delay_map;
  build_router_network(g,router_names,delay_map);
  assert(boost::num_edges(g) == 7);
  assert(boost::num_edges(g) == delay_map.size());
  assert(boost::num_vertices(g) == 5);
  assert(boost::num_vertices(g) == router_names.size());
  std::cout << __func__ << ": OK" << '\n';
}
