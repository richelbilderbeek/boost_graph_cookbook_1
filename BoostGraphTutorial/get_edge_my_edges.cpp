#include "get_edge_my_edges.h"

#include <cassert>
#include <iostream>


#include "create_custom_edges_and_vertices_k3_graph.h"
#include "get_custom_vertex_my_vertexes.h"

void get_edge_my_edges_test() noexcept
{
  const auto g = create_custom_edges_and_vertices_k3_graph();

  const std::vector<my_custom_vertex> expected_my_custom_vertexes{
    my_custom_vertex("top","source",0.0,0.0),
    my_custom_vertex("right","target",3.14,0),
    my_custom_vertex("left","target",0,3.14)
  };
  const std::vector<my_custom_vertex> vertexes{
    get_custom_vertex_my_vertexes(g)
  };
  assert(expected_my_custom_vertexes == vertexes);

  const std::vector<my_edge> expected_my_edges{
    my_edge("AB","first",0.0,0.0),
    my_edge("BC","second",3.14,3.14),
    my_edge("CA","third",3.14,3.14)
  };
  const std::vector<my_edge> edges{
    get_edge_my_edges(g)
  };
  assert(expected_my_edges == edges);
  std::cout << __func__ << ": OK" << '\n';
}
