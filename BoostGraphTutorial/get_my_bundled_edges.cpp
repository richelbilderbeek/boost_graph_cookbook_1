#include "get_my_bundled_edges.h"

#include "get_my_bundled_edges_demo.impl"

#include <cassert>
#include <iostream>

#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "get_my_bundled_vertexes.h"

void get_my_bundled_edges_test() noexcept
{
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();

    const std::vector<my_bundled_vertex> expected_my_bundled_vertexes{
      my_bundled_vertex("Red","Not green",1.0,2.0),
      my_bundled_vertex("Light red","Not dark",3.0,4.0),
      my_bundled_vertex("Orange","Orangy",5.0,6.0)
    };
    const std::vector<my_bundled_vertex> vertexes{
      get_my_bundled_vertexes(g)
    };
    assert(expected_my_bundled_vertexes == vertexes);

    const std::vector<my_bundled_edge> expected_my_edges{
      my_bundled_edge("Oxygen","Air",1.0,2.0),
      my_bundled_edge("Helium","From tube",3.0,4.0),
      my_bundled_edge("Stable temperature","Here",5.0,6.0)
    };
    const std::vector<my_bundled_edge> edges{
      get_my_bundled_edges(g)
    };
    assert(expected_my_edges == edges);
  }
  get_my_bundled_edges_demo();
  std::cout << __func__ << ": OK" << '\n';
}
