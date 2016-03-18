#include "count_undirected_graph_connected_components.h"
#include "count_undirected_graph_connected_components_demo.impl"


#include <boost/test/unit_test.hpp>

#include "create_path_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "add_edge.h"

BOOST_AUTO_TEST_CASE(count_undirected_graph_connected_components_thorough)
{
  //Basic tests: K2 == path graph of 2 vertices
  {
    const auto g = create_k2_graph();
    BOOST_CHECK(count_undirected_graph_connected_components(g) == 1);
  }
  //Basic tests: adding two isolated edges results in two connected components
  {
    auto g = create_empty_undirected_graph();
    add_edge(g);
    add_edge(g);
    BOOST_CHECK(count_undirected_graph_connected_components(g) == 2);
  }
}
