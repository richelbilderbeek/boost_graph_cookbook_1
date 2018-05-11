#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_edge_demo.impl"
#include "add_custom_and_selectable_edge.h"
#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_add_one_edge)
{
  auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 0);
  BOOST_CHECK_EQUAL(boost::num_edges(g), 0);
  const my_custom_edge edge("X");
  add_custom_and_selectable_edge(edge, true, g);
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 2);
  BOOST_CHECK_EQUAL(boost::num_edges(g), 1);
}

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_add_two_edges)
{
  auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_custom_edge edge_1("X");
  const my_custom_edge edge_2("Y");
  add_custom_and_selectable_edge(edge_1, true, g);
  add_custom_and_selectable_edge(edge_2, false, g);
  BOOST_CHECK(boost::num_vertices(g) == 4);
  BOOST_CHECK(boost::num_edges(g) == 2);
}

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_add_another_edge)
{
  using another_edge = std::vector<std::string>;
  using another_vertex = std::string;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_custom_type_t, another_vertex,
      boost::property<
        boost::vertex_is_selected_t, bool
      >
    >,
    boost::property<
      boost::edge_custom_type_t, another_edge,
      boost::property<
        boost::edge_is_selected_t, bool
      >
    >
  >;
  another_graph g;
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const another_edge edge = { "A", "B" } ;
  add_custom_and_selectable_edge(edge, true, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

