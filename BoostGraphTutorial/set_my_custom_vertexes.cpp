#include "set_my_custom_vertexes.h"

#include <iostream>

#include "create_custom_vertices_k2_graph.h"
#include "get_my_custom_vertexes.h"

void set_my_custom_vertexes_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_custom_vertices_k2_graph();
    const std::vector<my_custom_vertex> my_custom_vertexes{
      my_custom_vertex("alpha"),
      my_custom_vertex("beta")
    };
    assert(get_my_custom_vertexes(g) != my_custom_vertexes);
    set_my_custom_vertexes(g,my_custom_vertexes);
    assert(get_my_custom_vertexes(g) == my_custom_vertexes);
  }

  std::cout << __func__ << ": OK" << '\n';
}
