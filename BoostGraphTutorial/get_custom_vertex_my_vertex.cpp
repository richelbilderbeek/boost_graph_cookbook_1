#include "get_custom_vertex_my_vertex.h"

#include "get_custom_vertex_my_vertex_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_custom_vertex.h"
#include "find_first_custom_vertex_with_my_vertex.h"

void get_custom_vertex_my_vertex_test() noexcept
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex name{"Dex"};
  add_custom_vertex(name, g);
  const auto vd = find_first_custom_vertex_with_my_vertex(name, g);
  assert(get_custom_vertex_my_custom_vertex(vd,g) == name);

  get_custom_vertex_my_custom_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}
