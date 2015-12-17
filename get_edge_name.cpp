#include "get_edge_name.h"

#include "get_edge_name_demo.impl"

#include <cassert>
#include <iostream>
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "add_named_edge.h"
#include "find_first_edge_with_name.h"

void get_edge_name_test() noexcept
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string name{"Dex"};
  add_named_edge(name, g);
  const auto vd = find_first_edge_with_name(name,g);
  assert(get_edge_name(vd,g) == name);

  get_edge_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
