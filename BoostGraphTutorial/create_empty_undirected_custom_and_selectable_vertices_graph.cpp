#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

#include "create_empty_undirected_custom_and_selectable_vertices_graph_demo.impl"

#include <iostream>

void create_empty_undirected_custom_and_selectable_vertices_graph_test() noexcept
{
  {
    const auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
  }
  create_empty_undirected_custom_and_selectable_vertices_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
