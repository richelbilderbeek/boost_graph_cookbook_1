#include "remove_edge_between_vertices_with_texts.h"
#include "remove_edge_between_vertices_with_texts_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_text_edge.h"
#include "add_text_vertex.h"
#include "create_empty_undirected_text_edges_and_vertices_graph.h"
#include "create_text_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(remove_edge_between_vertices_with_texts_thorough)
{
  auto g = create_text_edges_and_vertices_k3_graph();
  BOOST_CHECK(boost::num_edges(g) == 3);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  remove_edge_between_vertices_with_texts("top", "right", g);
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_texts_where_first_vertex_does_not_exist)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  const std::string c{ "C" };
  const auto vda = add_text_vertex(a, g);
  const auto vdb = add_text_vertex(b, g);
  boost::edge(vda, vdb, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_texts(c, b, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_texts_where_second_vertex_does_not_exist)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  const std::string c{ "C" };
  const auto vda = add_text_vertex(a, g);
  const auto vdb = add_text_vertex(b, g);
  boost::edge(vda, vdb, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_texts(a, c, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_texts_where_there_is_no_edge)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  add_text_vertex(a, g);
  add_text_vertex(b, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_texts(a, b, g), std::invalid_argument);
}
