#include "clear_first_vertex_with_name.h"
#include "clear_first_vertex_with_name_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_named_vertices_k2_graph.h"


BOOST_AUTO_TEST_CASE(clear_first_vertex_with_name_thorough)
{
  auto g = create_named_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_name("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
