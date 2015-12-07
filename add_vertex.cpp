#include "add_vertex.h"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

void add_vertex_test() noexcept
{
  auto g = create_empty_directed_graph();
  assert(get_n_vertices(g) == 0);
  assert(get_n_edges(g) == 0);
  add_vertex(g);
  assert(get_n_vertices(g) == 1);
  assert(get_n_edges(g) == 0);
  std::cout << __func__ << ": OK" << '\n';
}
