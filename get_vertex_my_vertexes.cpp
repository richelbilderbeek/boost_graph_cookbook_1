#include "get_vertex_my_vertexes.h"

#include <cassert>
#include <iostream>
#include "get_n_edges.h"
#include "get_n_vertices.h"
#include "create_custom_vertices_k2_graph.h"

void get_vertex_my_vertexes_test() noexcept
{
  const auto g = create_custom_vertices_k2_graph();
  const std::vector<my_vertex> expected_my_vertexes{
    my_vertex("A","source",0.0,0.0),
    my_vertex("B","target",3.14,3.14)
  };
  const std::vector<my_vertex> vertexes{
    get_vertex_my_vertexes(g)
  };
  assert(expected_my_vertexes == vertexes);
  std::cout << __func__ << ": OK" << '\n';
}
