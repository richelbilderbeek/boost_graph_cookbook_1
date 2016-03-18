#include "get_vertex_iterators.h"
#include "get_vertex_iterators_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"

#include "create_named_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(get_vertex_iterators_thorough)
{
  //Empty undirected graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_undirected_graph();
    const auto vip_a = get_vertex_iterators(g);
    BOOST_CHECK(vip_a.first == vip_a.second);
  }
  //Empty directed graph: vertex iterators will both point beyond the last non-existent vertex
  {
    const auto g = create_empty_directed_graph();
    const auto vip_a = get_vertex_iterators(g);
    BOOST_CHECK(vip_a.first == vip_a.second);
  }
  //Undirected K2 graph
  {
    const auto g = create_k2_graph();
    const auto vip_a = get_vertex_iterators(g);
    BOOST_CHECK(vip_a.first != vip_a.second);
  }
}

