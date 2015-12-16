#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

#include "create_empty_undirected_custom_edges_and_vertices_graph.impl"

#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"

void create_empty_undirected_custom_edges_and_vertices_graph_test() noexcept
{
  const auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  assert(get_n_edges(g) == 0);
  assert(get_n_vertices(g) == 0);
  std::cout << __func__ << ": OK" << '\n';
}
