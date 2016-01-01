#include "remove_edge_between_vertices_with_names.h"

#include "remove_edge_between_vertices_with_names_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_edges_and_vertices_k3_graph.h"



void remove_edge_between_vertices_with_names_test() noexcept
{
  {
    auto g = create_named_edges_and_vertices_k3_graph();
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    remove_edge_between_vertices_with_names("top","right",g);
    assert(boost::num_edges(g) == 2);
    assert(boost::num_vertices(g) == 3);
  }
  remove_edge_between_vertices_with_names_demo();
  
}
