#include "add_custom_edge.h"
#include "add_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

#include "get_my_custom_edges.h"

BOOST_AUTO_TEST_CASE(test_add_custom_edge_add_one)
{
  auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_custom_edge edge("X");
  add_custom_edge(edge, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 1);
  const std::vector<my_custom_edge> edges{ get_my_custom_edges(g) };
  const std::vector<my_custom_edge> expected_edges{ edge };
  BOOST_CHECK(edges == expected_edges);
}

BOOST_AUTO_TEST_CASE(test_add_custom_edge_add_two)
{
  auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_custom_edge edge_1("X");
  const my_custom_edge edge_2("Y");
  add_custom_edge(edge_1, g);
  add_custom_edge(edge_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 4);
  BOOST_CHECK(boost::num_edges(g) == 2);
  const std::vector<my_custom_edge> edges{ get_my_custom_edges(g) };
  const std::vector<my_custom_edge> expected_edges{ edge_1, edge_2 };
  BOOST_CHECK(edges == expected_edges);
}

BOOST_AUTO_TEST_CASE(test_add_custom_edge_add_another_edge)
{
  using another_edge = std::string;
  using another_vertex = std::string;
  using another_graph
    = boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS,
      boost::property<boost::vertex_custom_type_t, another_vertex>,
      boost::property<boost::edge_custom_type_t, another_edge>>;
  another_graph g;
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const another_edge edge_1("X");
  const another_edge edge_2("Y");
  add_custom_edge(edge_1, g);
  add_custom_edge(edge_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 4);
  BOOST_CHECK(boost::num_edges(g) == 2);
}
