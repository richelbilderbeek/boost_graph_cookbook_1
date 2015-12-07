#include "get_n_vertices.h"

#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_vertices.h"

void get_n_vertices_test() noexcept
{
  //An empty undirected graph has no vertices
  {
    const auto g = create_empty_undirected_graph();
    assert(get_n_vertices(g) == 0);
  }
  //An empty directed graph has no vertices
  {
    const auto g = create_empty_directed_graph();
    assert(get_n_vertices(g) == 0);
  }
  //A K2 graph has 2 vertices
  {
    const auto g = create_k2_graph();
    assert(get_n_vertices(g) == 2);
  }
  std::cout << __func__ << ": OK" << '\n';
}

