#include "set_my_bundled_vertexes.h"

#include <iostream>

#include "create_bundled_vertices_k2_graph.h"
#include "get_my_bundled_vertexes.h"

void set_my_bundled_vertexes_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_bundled_vertices_k2_graph();
    const std::vector<my_bundled_vertex> my_vertexes{
      my_bundled_vertex("alpha"),
      my_bundled_vertex("beta")
    };
    assert(get_my_bundled_vertexes(g) != my_vertexes);
    set_my_bundled_vertexes(g, my_vertexes);
    assert(get_my_bundled_vertexes(g) == my_vertexes);
  }

  std::cout << __func__ << ": OK" << '\n';
}
