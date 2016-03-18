#include "has_vertex_with_my_vertex.h"
#include "has_vertex_with_my_vertex_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "add_custom_vertex.h"
#include "create_empty_undirected_custom_vertices_graph.h"

BOOST_AUTO_TEST_CASE(has_vertex_with_my_vertex_thorough)
{
  {
    auto g
      = create_empty_undirected_custom_vertices_graph();
    const my_custom_vertex v("Felix");
    BOOST_CHECK(!has_vertex_with_my_vertex(v,g));
    add_custom_vertex(v,g);
    BOOST_CHECK(has_vertex_with_my_vertex(v,g));
  }
}
