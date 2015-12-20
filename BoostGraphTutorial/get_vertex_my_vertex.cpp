#include "get_vertex_my_vertex.h"

#include "get_vertex_my_vertex_demo.impl"

#include <cassert>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_custom_vertex.h"
#include "find_first_vertex_with_my_vertex.h"

void get_vertex_my_vertex_test() noexcept
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_vertex name{"Dex"};
  add_custom_vertex(name, g);
  const auto vd = find_first_vertex_with_my_vertex(name, g);
  assert(get_vertex_my_vertex(vd,g) == name);

  get_vertex_my_vertex_demo();
  std::cout << __func__ << ": OK" << '\n';
}
