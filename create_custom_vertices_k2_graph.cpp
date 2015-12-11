#include "create_custom_vertices_k2_graph.h"

#include "create_custom_vertices_k2_graph.impl"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "has_vertex_with_my_vertex.h"

void create_custom_vertices_k2_graph_test() noexcept
{
  const auto g = create_custom_vertices_k2_graph();
  assert(get_n_edges(g) == 1);
  assert(get_n_vertices(g) == 2);
  assert(has_vertex_with_my_vertex(my_vertex("from", "source" ,0.0, 0.0), g));
  assert(has_vertex_with_my_vertex(my_vertex("to", "target" ,3.14, 3.14), g));
  std::cout << __func__ << ": OK" << '\n';

}
