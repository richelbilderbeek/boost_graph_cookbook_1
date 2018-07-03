#include "has_bundled_vertex_with_my_vertex.h"
#include "has_bundled_vertex_with_my_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_vertices_graph.h"
#include "get_my_bundled_vertex.h"

BOOST_AUTO_TEST_CASE(has_bundled_vertex_with_my_vertex_thorough)
{
  auto g = create_empty_undirected_bundled_vertices_graph();
  BOOST_CHECK(
    !has_bundled_vertex_with_my_vertex(my_bundled_vertex("Felix"), g));
  add_bundled_vertex(my_bundled_vertex("Felix"), g);
  BOOST_CHECK(has_bundled_vertex_with_my_vertex(my_bundled_vertex("Felix"), g));
}
