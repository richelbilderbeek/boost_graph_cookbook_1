#include "remove_first_edge_with_text.h"
#include "remove_first_edge_with_text_demo.impl"

#include "create_empty_directed_text_edges_and_vertices_graph.h"
#include "create_text_edges_and_vertices_k3_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(remove_first_edge_with_text_thorough)
{
  auto g = create_text_edges_and_vertices_k3_graph();
  BOOST_CHECK(boost::num_edges(g) == 3);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  remove_first_edge_with_text("AB", g);
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
}

BOOST_AUTO_TEST_CASE(remove_first_edge_with_text_where_edge_does_not_exist)
{
  auto g = create_empty_directed_text_edges_and_vertices_graph();
  BOOST_CHECK_THROW(
    remove_first_edge_with_text("AB", g), std::invalid_argument);
}
