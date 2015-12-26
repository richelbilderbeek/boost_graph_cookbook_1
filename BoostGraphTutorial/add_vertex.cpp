#include "add_vertex.h"

#include "add_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_graph.h"
#include "create_empty_directed_graph.h"




void add_vertex_test() noexcept
{
  //Add vertex to an undirected graph
  {
    auto g = create_empty_undirected_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    add_vertex(g);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
  }
  //Add vertex to a directed graph
  {
    auto g = create_empty_directed_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    add_vertex(g);
    assert(boost::num_vertices(g) == 1);
    assert(boost::num_edges(g) == 0);
  }
  add_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}
