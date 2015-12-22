#include "get_custom_edge_my_edge.h"

#include "get_custom_edge_my_edge_demo.impl"

#include <cassert>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

void get_custom_edge_my_edge_test() noexcept
{
  //Basic tests
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    const my_custom_edge edge{"Dex","Diggy",1.0,2.0};
    add_custom_edge(edge, g);
    const auto vd = find_first_custom_edge_with_my_edge(edge,g);
    assert(get_custom_edge_my_edge(vd,g) == edge);
  }
  get_custom_edge_my_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
