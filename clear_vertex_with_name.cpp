#include "clear_vertex_with_name.h"

#include "clear_vertex_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"
#include "get_n_edges.h"

void clear_vertex_with_name_test() noexcept
{
  auto g = create_named_vertices_k2_graph();
  assert(get_n_edges(g) == 1);
  clear_vertex_with_name("from",g);
  assert(get_n_edges(g) == 0);
  clear_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
