#include "get_my_bundled_vertex.h"
#include "get_my_bundled_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_vertices_graph.h"
#include "find_first_bundled_vertex_with_my_vertex.h"

BOOST_AUTO_TEST_CASE(get_my_bundled_vertex_thorough)
{
  auto g = create_empty_undirected_bundled_vertices_graph();
  const my_bundled_vertex name{ "Dex" };
  add_bundled_vertex(name, g);
  const auto vd = find_first_bundled_vertex_with_my_vertex(name, g);
  BOOST_CHECK(get_my_bundled_vertex(vd, g) == name);
}
