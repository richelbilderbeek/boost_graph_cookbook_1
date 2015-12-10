#include "create_empty_undirected_graph.h"

#include "create_empty_undirected_graph.impl"

#include <iostream>

#include "get_n_edges.h"
#include "get_n_vertices.h"

#include "create_empty_undirected_graph_demo.impl"

void create_empty_undirected_graph_test() noexcept
{
  auto g = create_empty_undirected_graph();
  assert(get_n_edges(g) == 0);
  assert(get_n_vertices(g) == 0);

  //Sure, can
  add_vertex(g);

  create_empty_undirected_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
