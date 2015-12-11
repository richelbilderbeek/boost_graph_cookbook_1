#include "remove_edge_between_vertices_with_names.h"

#include "remove_edge_between_vertices_with_names_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_edges_and_vertices_k3_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

void remove_edge_between_vertices_with_names_test() noexcept
{
  {
    auto g = create_named_edges_and_vertices_k3_graph();
    assert(get_n_edges(g) == 3);
    assert(get_n_vertices(g) == 3);
    remove_edge_between_vertices_with_names("top","right",g);
    assert(get_n_edges(g) == 2);
    assert(get_n_vertices(g) == 3);
  }
  remove_edge_between_vertices_with_names_demo();
  std::cout << __func__ << ": OK" << '\n';
}
