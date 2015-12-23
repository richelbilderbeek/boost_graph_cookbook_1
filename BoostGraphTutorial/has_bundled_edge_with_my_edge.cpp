#include "has_bundled_edge_with_my_edge.h"

#include "has_bundled_edge_with_my_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "add_bundled_edge.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

void has_bundled_edge_with_my_edge_test() noexcept
{
  auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
  assert(!has_bundled_edge_with_my_edge(my_bundled_edge("Felix"),g));
  add_bundled_edge(my_bundled_edge("Felix"),g);
  assert(has_bundled_edge_with_my_edge(my_bundled_edge("Felix"),g));

  has_bundled_edge_with_my_edge_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
