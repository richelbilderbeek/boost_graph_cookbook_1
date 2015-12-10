#include "get_edges.h"

#include "get_edges_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_edges.h"
#include "create_named_edges_and_vertices_k3_graph.h"

void get_edges_test() noexcept
{
  //Empty undirected graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto eip_a = get_edges(g);
    assert(eip_a.first == eip_a.second);
  }
  //Empty directed graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto eip_a = get_edges(g);
    assert(eip_a.first == eip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto eip_a = get_edges(g);
    assert(eip_a.first != eip_a.second);
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto eip_a = get_edges(g);
    assert(eip_a.first != eip_a.second);
  }
  get_edges_demo();
  std::cout << __func__ << ": OK" << '\n';
}

