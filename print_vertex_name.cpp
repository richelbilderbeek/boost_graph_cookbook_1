#include "print_vertex_name.h"

#include <iostream>

#include "create_empty_named_vertices_graph.h"

void print_vertex_name_test() noexcept
{
  auto g = create_empty_named_vertices_graph();
  const auto vd = boost::add_vertex(g);
  const auto name_map = get(boost::vertex_name,g);
  name_map[vd] = "print_vertex_name_test";
  print_vertex_name(vd,name_map);
  std::cout << __func__ << ": OK" << std::endl;
}
