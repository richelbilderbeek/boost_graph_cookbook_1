#include "count_if_bundled_vertex.h"
#include "count_if_bundled_vertex_demo.impl"

#include "create_bundled_vertices_k2_graph.h"
#include "create_empty_directed_bundled_vertices_graph.h"
#include "has_bundled_vertex_with_my_vertex.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(count_if_bundled_vertex_thorough)
{
  const auto g = create_bundled_vertices_k2_graph();
  const int n = count_if_bundled_vertex(
    g, [](const my_bundled_vertex& v){ return v.get_y() < 2.5; } );
  BOOST_CHECK_EQUAL(1, n);
}
