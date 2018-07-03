#include "set_vertex_name.h"
#include "set_vertex_name_demo.impl"

#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"
#include "find_first_vertex_with_name.h"
#include "get_vertex_name.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(set_vertex_name_thorough)
{
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string old_name{ "Dex" };
  add_named_vertex(old_name, g);
  const auto vd = find_first_vertex_with_name(old_name, g);
  BOOST_CHECK(get_vertex_name(vd, g) == old_name);
  const std::string new_name{ "Diggy" };
  set_vertex_name(new_name, vd, g);
  BOOST_CHECK(get_vertex_name(vd, g) == new_name);
}
