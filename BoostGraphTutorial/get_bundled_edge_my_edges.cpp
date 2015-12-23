#include "get_bundled_edge_my_edges.h"

#include "get_bundled_edge_my_edges_demo.impl"

#include <cassert>
#include <iostream>

#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "get_bundled_vertex_my_vertexes.h"

void get_bundled_edge_my_edges_test() noexcept
{
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();

    const std::vector<my_bundled_vertex> expected_my_bundled_vertexes{
      my_bundled_vertex("top","source",0.0,0.0),
      my_bundled_vertex("right","target",3.14,0),
      my_bundled_vertex("left","target",0,3.14)
    };
    const std::vector<my_bundled_vertex> vertexes{
      get_bundled_vertex_my_vertexes(g)
    };
    assert(expected_my_bundled_vertexes == vertexes);

    const std::vector<my_bundled_edge> expected_my_edges{
      my_bundled_edge("AB","first",0.0,0.0),
      my_bundled_edge("BC","second",3.14,3.14),
      my_bundled_edge("CA","third",3.14,3.14)
    };
    const std::vector<my_bundled_edge> edges{
      get_bundled_edge_my_edges(g)
    };
    assert(expected_my_edges == edges);
  }
  get_bundled_edge_my_edges_demo();
  std::cout << __func__ << ": OK" << '\n';
}
