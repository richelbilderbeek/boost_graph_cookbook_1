#include "clear_first_vertex_with_text.h"
#include "clear_first_vertex_with_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_text_vertex.h"
#include "create_text_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(clear_first_vertex_with_text_on_text_vertices_k2_graph)
{
  auto g = create_text_vertices_k2_graph();
  BOOST_CHECK(boost::num_edges(g) == 1);
  clear_first_vertex_with_text("My computer",g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
