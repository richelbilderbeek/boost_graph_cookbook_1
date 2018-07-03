#include "get_edge_descriptors.h"
#include "get_edge_descriptors_demo.impl"

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_edge_descriptors_thorough)
{
  // Empty directed graph
  {
    const auto g = create_empty_directed_graph();
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.empty());
  }
  // Empty undirected graph
  {
    const auto g = create_empty_undirected_graph();
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.empty());
  }
  // Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 1);
  }
  // Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 3);
    // BOOST_CHECK(target(eds[0], g) == source(eds[1], g));
  }
}
