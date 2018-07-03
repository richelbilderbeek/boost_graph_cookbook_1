#include "get_my_custom_vertex.h"
#include "get_my_custom_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_vertex.h"
#include "create_empty_undirected_custom_vertices_graph.h"
#include "find_first_custom_vertex_with_my_vertex.h"

BOOST_AUTO_TEST_CASE(get_my_custom_vertex_thorough)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  const my_custom_vertex name{ "Dex" };
  add_custom_vertex(name, g);
  const auto vd = find_first_custom_vertex_with_my_vertex(name, g);
  BOOST_CHECK(get_my_custom_vertex(vd, g) == name);
}
