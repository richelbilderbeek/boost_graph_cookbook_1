#include "get_n_edges.h"

#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"

void get_n_edges_test() noexcept
{
  //An empty undirected graph has no edges
  {
    const auto g = create_empty_undirected_graph();
    assert(get_n_edges(g) == 0);
  }
  //An empty directed graph has no edges
  {
    const auto g = create_empty_directed_graph();
    assert(get_n_edges(g) == 0);
  }
  //A K2 graph has 1 edge
  {
    const auto g = create_k2_graph();
    assert(get_n_edges(g) == 1);
  }
  //A K3 graph has 3 edges
  /*
  {
    const auto g = create_k3_graph();
    assert(get_n_edges(g) == 3);
  }
  */
  std::cout << __func__ << ": OK" << '\n';
}

