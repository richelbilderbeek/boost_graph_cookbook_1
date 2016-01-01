#include "set_my_custom_edge.h"

#include "set_my_custom_edge_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

void set_my_custom_edge_test() noexcept
{
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    const my_custom_edge old_name{"Dex"};
    add_custom_edge(old_name, g);
    const auto vd = find_first_custom_edge_with_my_edge(old_name, g);
    assert(get_my_custom_edge(vd, g) == old_name);
    const my_custom_edge new_name{"Diggy"};
    set_my_custom_edge(new_name, vd, g);
    assert(get_my_custom_edge(vd, g) == new_name);
  }
  set_my_custom_edge_demo();
  
}
