#include "get_n_edges.h"
#include "get_n_edges_demo.impl"

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_n_edges_thorough)
{
  // An empty undirected graph has no edges
  {
    const auto g = create_empty_undirected_graph();
    BOOST_CHECK(get_n_edges(g) == 0);
  }
  // An empty directed graph has no edges
  {
    const auto g = create_empty_directed_graph();
    BOOST_CHECK(get_n_edges(g) == 0);
  }
  // A K2 graph has 1 edge
  {
    const auto g = create_k2_graph();
    BOOST_CHECK(get_n_edges(g) == 1);
  }
}
