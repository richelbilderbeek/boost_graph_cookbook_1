#include "get_bundled_vertex_my_vertexes.h"

#include <cassert>
#include <iostream>

#include "create_bundled_vertices_k2_graph.h"

void get_bundled_vertex_my_vertexes_test() noexcept
{
  {
    const auto g = create_bundled_vertices_k2_graph();
    const std::vector<my_bundled_vertex> expected_my_vertexes{
      my_bundled_vertex("Me","Myself",1.0,2.0),
      my_bundled_vertex("My computer","Not me",3.0,4.0)
    };
    const std::vector<my_bundled_vertex> vertexes{
      get_bundled_vertex_my_vertexes(g)
    };
    assert(expected_my_vertexes == vertexes);
  }
  std::cout << __func__ << ": OK" << '\n';
}
