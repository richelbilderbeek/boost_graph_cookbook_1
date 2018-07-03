#include "count_vertices_with_text.h"
#include "count_vertices_with_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_text_vertex.h"
#include "create_empty_undirected_text_vertices_graph.h"

BOOST_AUTO_TEST_CASE(count_vertices_with_text_thorough)
{
  auto g = create_empty_undirected_text_vertices_graph();
  add_text_vertex("Rex", g);
  BOOST_CHECK_EQUAL(count_vertices_with_text("Rex", g), 1);
  BOOST_CHECK_EQUAL(count_vertices_with_text("Nebular", g), 0);
}
