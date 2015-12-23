#include "create_empty_directed_bundled_edges_and_vertices_graph.h"

#include "create_empty_directed_bundled_edges_and_vertices_graph.impl"
#include "create_empty_directed_bundled_edges_and_vertices_graph_demo.impl"

#include <cassert>
#include <iostream>

void create_empty_directed_bundled_edges_and_vertices_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_empty_directed_bundled_edges_and_vertices_graph();
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
  }
  create_empty_directed_bundled_edges_and_vertices_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
