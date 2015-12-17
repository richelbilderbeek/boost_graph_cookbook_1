#include "clear_first_vertex_with_name.h"

#include "clear_first_vertex_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_vertices_k2_graph.h"


void clear_first_vertex_with_name_test() noexcept
{
  auto g = create_named_vertices_k2_graph();
  assert(boost::num_edges(g) == 1);
  clear_first_vertex_with_name("A",g);
  assert(boost::num_edges(g) == 0);
  clear_first_vertex_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
