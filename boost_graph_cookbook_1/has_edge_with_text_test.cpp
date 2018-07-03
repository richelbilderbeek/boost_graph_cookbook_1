#include "has_edge_with_text.h"
#include "has_edge_with_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "add_text_edge.h"
#include "create_empty_undirected_text_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(has_edge_with_text_thorough)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  BOOST_CHECK(!has_edge_with_text("Felix", g));
  add_text_edge("Felix", g);
  BOOST_CHECK(has_edge_with_text("Felix", g));
}
