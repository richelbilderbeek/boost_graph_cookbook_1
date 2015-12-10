#include "get_vertices.h"

#include "get_vertices_demo.impl"

#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_vertices.h"
#include "create_named_edges_and_vertices_k3_graph.h"


void get_vertices_test() noexcept
{
  //Empty undirected graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto vip_a = get_vertices(g);
    assert(vip_a.first == vip_a.second);
  }
  //Empty directed graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto vip_a = get_vertices(g);
    assert(vip_a.first == vip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto vip_a = get_vertices(g);
    assert(vip_a.first != vip_a.second);
  }
  get_vertices_demo();
  std::cout << __func__ << ": OK" << '\n';

}

