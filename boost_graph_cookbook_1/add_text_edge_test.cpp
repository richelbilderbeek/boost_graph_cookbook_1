#include "add_text_edge.h"
#include "add_text_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_text_edges_and_vertices_graph.h"

#include "get_edge_texts.h"

BOOST_AUTO_TEST_CASE(add_text_edge_add_one)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string edge_name{ "X" };
  add_text_edge(edge_name, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 1);
  const std::vector<std::string> edge_texts{ get_edge_texts(g) };
  const std::vector<std::string> expected_texts{ edge_name };
  BOOST_CHECK(edge_texts == expected_texts);
}

BOOST_AUTO_TEST_CASE(add_text_edge_add_two)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::string edge_name_1{ "A" };
  const std::string edge_name_2{ "B" };
  add_text_edge(edge_name_1, g);
  add_text_edge(edge_name_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 4);
  BOOST_CHECK(boost::num_edges(g) == 2);
  const std::vector<std::string> edge_texts{ get_edge_texts(g) };
  const std::vector<std::string> expected_texts{ edge_name_1, edge_name_2 };
  BOOST_CHECK(edge_texts == expected_texts);
}
