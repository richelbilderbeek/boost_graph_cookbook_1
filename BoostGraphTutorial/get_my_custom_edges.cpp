#include "get_my_custom_edges.h"

#include "get_my_custom_edges_demo.impl"

#include <cassert>
#include <iostream>

#include "create_custom_edges_and_vertices_k3_graph.h"
#include "get_my_custom_vertexes.h"

void get_my_custom_edges_test() noexcept
{
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();

    const std::vector<my_custom_vertex> expected_my_custom_vertexes{
      my_custom_vertex("top","source",0.0,0.0),
      my_custom_vertex("right","target",3.14,0),
      my_custom_vertex("left","target",0,3.14)
    };
    const std::vector<my_custom_vertex> vertexes{
      get_my_custom_vertexes(g)
    };
    assert(expected_my_custom_vertexes == vertexes);

    const std::vector<my_custom_edge> expected_my_edges{
      my_custom_edge("AB","first",0.0,0.0),
      my_custom_edge("BC","second",3.14,3.14),
      my_custom_edge("CA","third",3.14,3.14)
    };
    const std::vector<my_custom_edge> edges{
      get_my_custom_edges(g)
    };
    assert(expected_my_edges == edges);
  }
  get_my_custom_edges_demo();
  std::cout << __func__ << ": OK" << '\n';
}
