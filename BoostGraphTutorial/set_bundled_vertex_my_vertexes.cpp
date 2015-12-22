#include "set_bundled_vertex_my_vertexes.h"

#include <iostream>

#include "create_bundled_vertices_k2_graph.h"
#include "get_bundled_vertex_my_vertexes.h"

void set_bundled_vertex_my_vertexes_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_bundled_vertices_k2_graph();
    const std::vector<my_bundled_vertex> my_vertexes{
      my_bundled_vertex("alpha"),
      my_bundled_vertex("beta")
    };
    assert(get_bundled_vertex_my_vertexes(g) != my_vertexes);
    set_bundled_vertex_my_vertexes(g,my_vertexes);
    assert(get_bundled_vertex_my_vertexes(g) == my_vertexes);
  }

  std::cout << __func__ << ": OK" << '\n';
}
