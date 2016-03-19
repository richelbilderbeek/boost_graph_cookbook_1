#include "get_edge_iterators.h"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"

#include "create_named_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(get_edge_iterators_thorough)
{
  //Empty undirected graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto eip_a = get_edge_iterators(g);
    BOOST_CHECK(eip_a.first == eip_a.second);
  }
  //Empty directed graph: edge iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto eip_a = get_edge_iterators(g);
    BOOST_CHECK(eip_a.first == eip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto eip_a = get_edge_iterators(g);
    BOOST_CHECK(eip_a.first != eip_a.second);
  }
  //Undirected K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto eip_a = get_edge_iterators(g);
    BOOST_CHECK(eip_a.first != eip_a.second);
  }
}

