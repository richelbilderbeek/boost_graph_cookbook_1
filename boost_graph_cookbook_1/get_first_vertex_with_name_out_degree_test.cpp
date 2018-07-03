#include "get_first_vertex_with_name_out_degree.h"
#include "get_first_vertex_with_name_out_degree_demo.impl"

#include "create_named_vertices_k2_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_first_vertex_with_name_out_degree_thorough)
{
  {
    const auto g = create_named_vertices_k2_graph();
    BOOST_CHECK(get_first_vertex_with_name_out_degree("Me", g) == 1);
    BOOST_CHECK(get_first_vertex_with_name_out_degree("My computer", g) == 1);
  }
}
