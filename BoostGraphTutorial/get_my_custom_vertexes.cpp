#include "get_my_custom_vertexes.h"

#include "get_my_custom_vertexes_demo.impl"

#include <cassert>
#include <iostream>

#include "create_custom_vertices_k2_graph.h"

void get_my_custom_vertexes_test() noexcept
{
  {
    const auto g = create_custom_vertices_k2_graph();
    const std::vector<my_custom_vertex> expected_my_custom_vertexes{
      my_custom_vertex("A","source",0.0,0.0),
      my_custom_vertex("B","target",3.14,3.14)
    };
    const std::vector<my_custom_vertex> vertexes{
      get_my_custom_vertexes(g)
    };
    assert(expected_my_custom_vertexes == vertexes);
  }
  get_my_custom_vertexes_demo();
  std::cout << __func__ << ": OK" << '\n';
}
