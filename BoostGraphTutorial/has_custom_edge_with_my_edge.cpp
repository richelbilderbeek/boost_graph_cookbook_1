#include "has_custom_edge_with_my_edge.h"

#include "has_custom_edge_with_my_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "add_custom_edge.h"
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

void has_custom_edge_with_my_edge_test() noexcept
{
  auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  assert(!has_custom_edge_with_my_edge(my_custom_edge("Felix"),g));
  add_custom_edge(my_custom_edge("Felix"),g);
  assert(has_custom_edge_with_my_edge(my_custom_edge("Felix"),g));

  has_custom_edge_with_my_edge_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
