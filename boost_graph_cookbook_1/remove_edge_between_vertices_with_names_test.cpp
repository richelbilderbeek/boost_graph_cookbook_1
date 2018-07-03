#include "remove_edge_between_vertices_with_names.h"
#include "remove_edge_between_vertices_with_names_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_named_edge.h"
#include "add_named_vertex.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(remove_edge_between_vertices_with_names_thorough)
{
  auto g = create_named_edges_and_vertices_k3_graph();
  BOOST_CHECK(boost::num_edges(g) == 3);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  remove_edge_between_vertices_with_names("top", "right", g);
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_names_where_first_vertex_does_not_exist)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  const std::string c{ "C" };
  const auto vda = add_named_vertex(a, g);
  const auto vdb = add_named_vertex(b, g);
  boost::edge(vda, vdb, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_names(c, b, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_names_where_second_vertex_does_not_exist)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  const std::string c{ "C" };
  const auto vda = add_named_vertex(a, g);
  const auto vdb = add_named_vertex(b, g);
  boost::edge(vda, vdb, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_names(a, c, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(
  remove_edge_between_vertices_with_names_where_there_is_no_edge)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const std::string a{ "A" };
  const std::string b{ "B" };
  add_named_vertex(a, g);
  add_named_vertex(b, g);
  BOOST_CHECK_THROW(
    remove_edge_between_vertices_with_names(a, b, g), std::invalid_argument);
}
