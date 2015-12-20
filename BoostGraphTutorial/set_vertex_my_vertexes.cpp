#include "set_vertex_my_vertexes.h"

#include <iostream>

#include "create_custom_vertices_k2_graph.h"
#include "get_vertex_my_vertexes.h"


void set_vertex_my_vertexes_test() noexcept
{
  //Named K2 graph
  {
    auto g = create_custom_vertices_k2_graph();
    const std::vector<my_vertex> my_vertexes{
      my_vertex("alpha"),
      my_vertex("beta")
    };
    assert(get_vertex_my_vertexes(g) != my_vertexes);
    set_vertex_my_vertexes(g,my_vertexes);
    assert(get_vertex_my_vertexes(g) == my_vertexes);
  }

  std::cout << __func__ << ": OK" << '\n';
}
