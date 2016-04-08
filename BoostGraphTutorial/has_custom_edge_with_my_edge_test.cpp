#include "has_custom_edge_with_my_edge.h"
#include "has_custom_edge_with_my_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_edge.h"
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(has_custom_edge_with_my_edge_thorough)
{
  auto g = create_empty_undirected_custom_edges_and_vertices_graph();
  BOOST_CHECK(!has_custom_edge_with_my_edge(my_custom_edge("Felix"),g));
  add_custom_edge(my_custom_edge("Felix"),g);
  BOOST_CHECK(has_custom_edge_with_my_edge(my_custom_edge("Felix"),g));
}
