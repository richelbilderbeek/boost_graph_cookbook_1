#include "has_vertex_with_name.h"
#include "has_vertex_with_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_named_vertex.h"
#include "create_empty_undirected_named_vertices_graph.h"

BOOST_AUTO_TEST_CASE(has_vertex_with_name_thorough)
{
  {
    auto g = create_empty_undirected_named_vertices_graph();
    BOOST_CHECK(!has_vertex_with_name("Felix", g));
    add_named_vertex("Felix", g);
    BOOST_CHECK(has_vertex_with_name("Felix", g));
  }
}
