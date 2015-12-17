#include "create_custom_edges_and_vertices_k3_graph.h"

#include "create_custom_edges_and_vertices_k3_graph.impl"

#include <cassert>
#include <iostream>


#include "add_custom_edge.h"
#include "add_custom_vertex.h"

void create_custom_edges_and_vertices_k3_graph_test() noexcept
{
  auto g = create_custom_edges_and_vertices_k3_graph();
  assert(boost::num_edges(g) == 3);
  assert(boost::num_vertices(g) == 3);
  add_custom_vertex(my_vertex("v"), g);
  assert(boost::num_edges(g) == 3);
  assert(boost::num_vertices(g) == 4);
  add_custom_edge(my_edge("e"), g);
  assert(boost::num_edges(g) == 4);
  assert(boost::num_vertices(g) == 6);
  std::cout << __func__ << ": OK" << '\n';

}
