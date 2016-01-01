#include "get_my_bundled_edge.h"

#include "get_my_bundled_edge_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "add_bundled_edge.h"
#include "find_first_bundled_edge_with_my_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

void get_my_bundled_edge_test() noexcept
{
  //Basic tests
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    const my_bundled_edge edge{"Dex","Diggy",1.0,2.0};
    add_bundled_edge(edge, g);
    const auto vd = find_first_bundled_edge_with_my_edge(edge,g);
    assert(get_my_bundled_edge(vd,g) == edge);
  }
  get_my_bundled_edge_demo();
  
}
