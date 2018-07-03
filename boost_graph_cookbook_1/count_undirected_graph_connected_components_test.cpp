#include "count_undirected_graph_connected_components.h"
#include "count_undirected_graph_connected_components_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_edge.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_path_graph.h"

BOOST_AUTO_TEST_CASE(count_undirected_graph_connected_components_k2_graph)
{
  const auto g = create_k2_graph();
  BOOST_CHECK_EQUAL(count_undirected_graph_connected_components(g), 1);
}

BOOST_AUTO_TEST_CASE(
  count_undirected_graph_connected_components_two_unconnected_edges)
{
  auto g = create_empty_undirected_graph();
  add_edge(g);
  add_edge(g);
  BOOST_CHECK_EQUAL(count_undirected_graph_connected_components(g), 2);
}
