#include "has_edge_with_name.h"

#include "has_edge_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "add_named_edge.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"

void has_edge_with_name_test() noexcept
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  assert(!has_edge_with_name("Felix",g));
  add_named_edge("Felix",g);
  assert(has_edge_with_name("Felix",g));

  has_edge_with_name_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
