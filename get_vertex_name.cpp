#include "get_vertex_name.h"

#include "get_vertex_name_demo.impl"

#include <cassert>
#include <boost/graph/properties.hpp>

#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"
#include "find_first_vertex_with_name.h"

void get_vertex_name_test() noexcept
{
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string name{"Dex"};
  add_named_vertex(name, g);
  const auto vd = find_first_vertex_with_name(name,g);
  assert(get_vertex_name(vd,g) == name);
  get_vertex_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
