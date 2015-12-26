#include "add_edge.h"

#include "add_edge_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"



void add_edge_test() noexcept
{
  //Add edge to undirected graph
  {
    auto g = create_empty_undirected_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    add_edge(g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
  }
  //Add edge to directed graph
  {
    auto g = create_empty_directed_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    add_edge(g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
  }
  add_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
