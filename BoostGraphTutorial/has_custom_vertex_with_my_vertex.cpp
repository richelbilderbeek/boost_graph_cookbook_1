#include "has_custom_vertex_with_my_vertex.h"

#include "has_custom_vertex_with_my_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "add_named_vertex.h"
#include "create_empty_undirected_custom_vertices_graph.h"
#include "get_my_custom_vertexes.h"

void has_custom_vertex_with_my_vertex_test() noexcept
{
  auto g = create_empty_undirected_custom_vertices_graph();
  assert(get_my_custom_vertexes(g).empty());
  assert(!has_custom_vertex_with_my_custom_vertex(my_custom_vertex("Felix"),g));
  add_custom_vertex(my_custom_vertex("Felix"),g);
  assert(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("Felix"),g));
  has_custom_vertex_with_my_custom_vertex_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
