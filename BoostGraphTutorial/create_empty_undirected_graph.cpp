#include "create_empty_undirected_graph.h"

#include "create_empty_undirected_graph.impl"

#include <iostream>




#include "create_empty_undirected_graph_demo.impl"

void create_empty_undirected_graph_test() noexcept
{
  auto g = create_empty_undirected_graph();
  assert(boost::num_edges(g) == 0);
  assert(boost::num_vertices(g) == 0);

  //Sure, can
  add_vertex(g);

  create_empty_undirected_graph_demo();
  
}
