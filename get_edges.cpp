#include "get_edge_iterators.h"

#include "get_edge_iterators_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"

#include "create_named_edges_and_vertices_k3_graph.h"

void get_edge_iterators_test() noexcept
{
  //Empty undirected graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto eip_a = get_edge_iterators(g);
    assert(eip_a.first == eip_a.second);
  }
  //Empty directed graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto eip_a = get_edge_iterators(g);
    assert(eip_a.first == eip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto eip_a = get_edge_iterators(g);
    assert(eip_a.first != eip_a.second);
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto eip_a = get_edge_iterators(g);
    assert(eip_a.first != eip_a.second);
  }
  get_edge_iterators_demo();
  std::cout << __func__ << ": OK" << '\n';
}

