#include "get_vertex_name.h"
#include "get_vertex_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/graph/properties.hpp>

#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"
#include "find_first_vertex_with_name.h"

BOOST_AUTO_TEST_CASE(get_vertex_name_thorough)
{
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string name{ "Dex" };
  add_named_vertex(name, g);
  const auto vd = find_first_vertex_with_name(name, g);
  BOOST_CHECK(get_vertex_name(vd, g) == name);
}
