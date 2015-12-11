#include "set_edge_my_edge.h"

#include "set_edge_my_edge_demo.impl"

#include <cassert>

#include "create_empty_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_edge_with_my_edge.h"

void set_edge_my_edge_test() noexcept
{
  auto g = create_empty_custom_edges_and_vertices_graph();
  const std::string old_name{"Dex"};
  add_custom_edge(old_name, g);
  const auto vd = find_first_edge_with_my_edge(old_name, g);
  assert(get_edge_my_edge(vd, g) == old_name);
  const std::string new_name{"Diggy"};
  set_edge_my_edge(new_name, vd, g);
  assert(get_edge_my_edge(vd, g) == new_name);

  set_edge_my_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}
