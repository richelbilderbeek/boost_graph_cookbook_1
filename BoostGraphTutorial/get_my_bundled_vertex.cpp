#include "get_my_bundled_vertex.h"
#include "get_my_bundled_vertex_demo.impl"

#include <iostream>
#include <cassert>

#include "create_empty_undirected_bundled_vertices_graph.h"
#include "add_bundled_vertex.h"
#include "find_first_bundled_vertex_with_my_vertex.h"

void get_my_bundled_vertex_test() noexcept
{
  auto g = create_empty_undirected_bundled_vertices_graph();
  const my_bundled_vertex name{"Dex"};
  add_bundled_vertex(name, g);
  const auto vd = find_first_bundled_vertex_with_my_vertex(name, g);
  assert(get_my_bundled_vertex(vd, g) == name);

  get_my_bundled_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}
