#include "create_empty_named_vertices_graph.h"

#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"

void create_empty_named_vertices_graph_test() noexcept
{
  const auto g = create_empty_named_vertices_graph();
  assert(get_n_edges(g) == 0);
  assert(get_n_vertices(g) == 0);

  //Sure, can
  //add_vertex(g);

  std::cout << __func__ << ": OK" << '\n';
}
