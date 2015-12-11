#include "remove_first_edge_with_name.h"

#include "remove_first_edge_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_edges_and_vertices_k3_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

void remove_first_edge_with_name_test() noexcept
{
  {
    auto g = create_named_edges_and_vertices_k3_graph();
    assert(get_n_edges(g) == 3);
    assert(get_n_vertices(g) == 3);
    remove_first_edge_with_name("AB",g);
    assert(get_n_edges(g) == 2);
    assert(get_n_vertices(g) == 3);
  }
  remove_first_edge_with_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}


