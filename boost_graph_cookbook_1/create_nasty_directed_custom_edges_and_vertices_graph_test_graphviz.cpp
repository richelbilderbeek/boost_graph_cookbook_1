#include "create_nasty_directed_custom_edges_and_vertices_graph.h"

#include <boost/test/unit_test.hpp>

#include "add_custom_edge.h"
#include "create_empty_directed_custom_edges_and_vertices_graph.h"
#include "get_sorted_custom_edge_my_edges.h"
#include "load_directed_custom_edges_and_vertices_graph_from_dot.h"
#include "save_custom_edges_and_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(
  create_nasty_directed_custom_edges_and_vertices_graph_save_and_load)
{
  auto g = create_nasty_directed_custom_edges_and_vertices_graph();
  const std::string filename{
    "create_nasty_directed_custom_edges_and_vertices_graph_test.dot"
  };
  save_custom_edges_and_vertices_graph_to_dot(g, filename);
  const auto h
    = load_directed_custom_edges_and_vertices_graph_from_dot(filename);
  BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
  BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  // get_my_custom_edges returns the unsorted edge,
  // to compare the my_custom_edges before and after, its results must be sorted
  const auto a = get_sorted_custom_edge_my_edges(g);
  const auto b = get_sorted_custom_edge_my_edges(h);
  BOOST_CHECK(a == b);
}
