#include "get_edge_my_edge.h"

#include "get_edge_my_edge_demo.impl"

#include <cassert>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_edge_with_my_edge.h"

void get_edge_my_edge_test() noexcept
{
  auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  const std::string name{"Dex"};
  add_custom_edge(name, g);
  const auto vd = find_first_edge_with_my_edge(name,g);
  assert(get_edge_my_edge(vd,g) == name);

  get_edge_my_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
