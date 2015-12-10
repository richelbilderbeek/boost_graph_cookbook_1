#include "add_edge.h"

#include "add_edge_demo.impl"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "get_n_edges.h"
#include "get_n_vertices.h"

void add_edge_test() noexcept
{
  //Add edge to undirected graph
  {
    auto g = create_empty_undirected_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    add_edge(g);
    assert(get_n_vertices(g) == 2);
    assert(get_n_edges(g) == 1);
  }
  //Add edge to directed graph
  {
    auto g = create_empty_directed_graph();
    assert(get_n_vertices(g) == 0);
    assert(get_n_edges(g) == 0);
    add_edge(g);
    assert(get_n_vertices(g) == 2);
    assert(get_n_edges(g) == 1);
  }
  add_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
