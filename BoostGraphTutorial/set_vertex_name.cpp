#include "set_vertex_name.h"

#include "set_vertex_name_demo.impl"

#include <cassert>
#include <iostream>

#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"
#include "find_first_vertex_with_name.h"

void set_vertex_name_test() noexcept
{
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string old_name{"Dex"};
  add_named_vertex(old_name, g);
  const auto vd = find_first_vertex_with_name(old_name, g);
  assert(get_vertex_name(vd, g) == old_name);
  const std::string new_name{"Diggy"};
  set_vertex_name(new_name, vd, g);
  assert(get_vertex_name(vd, g) == new_name);

  set_vertex_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
