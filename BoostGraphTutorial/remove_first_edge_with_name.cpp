#include "remove_first_edge_with_name.h"

#include "remove_first_edge_with_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_named_edges_and_vertices_k3_graph.h"



void remove_first_edge_with_name_test() noexcept
{
  {
    auto g = create_named_edges_and_vertices_k3_graph();
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    remove_first_edge_with_name("AB",g);
    assert(boost::num_edges(g) == 2);
    assert(boost::num_vertices(g) == 3);
  }
  remove_first_edge_with_name_demo();
  
}


