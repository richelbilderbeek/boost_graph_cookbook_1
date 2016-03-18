#include "has_custom_vertex_with_my_vertex.h"
#include "has_custom_vertex_with_my_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_custom_vertex.h"
#include "create_empty_undirected_custom_vertices_graph.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(has_custom_vertex_with_my_vertex_thorough)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  BOOST_CHECK(get_my_custom_vertexes(g).empty());
  BOOST_CHECK(!has_custom_vertex_with_my_custom_vertex(my_custom_vertex("Felix"),g));
  add_custom_vertex(my_custom_vertex("Felix"),g);
  BOOST_CHECK(has_custom_vertex_with_my_custom_vertex(my_custom_vertex("Felix"),g));
}
