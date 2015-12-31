#include "has_bundled_vertex_with_my_vertex.h"

#include "has_bundled_vertex_with_my_vertex_demo.impl"

#include <cassert>
#include <iostream>

#include "add_named_vertex.h"
#include "create_empty_undirected_bundled_vertices_graph.h"
#include "get_my_bundled_vertex.h"

void has_bundled_vertex_with_my_vertex_test() noexcept
{
  auto g = create_empty_undirected_bundled_vertices_graph();
  assert(!has_bundled_vertex_with_my_vertex(my_bundled_vertex("Felix"),g));
  add_bundled_vertex(my_bundled_vertex("Felix"),g);
  assert(has_bundled_vertex_with_my_vertex(my_bundled_vertex("Felix"),g));
  has_bundled_vertex_with_my_vertex_demo();
  std::cout << __func__ << ": OK" << std::endl;
}
