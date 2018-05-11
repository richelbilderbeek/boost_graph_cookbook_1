#include "get_n_vertices.h"
#include "get_n_vertices_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "get_n_vertices.h"

BOOST_AUTO_TEST_CASE(get_n_vertices_thorough)
{
  //An empty undirected graph has no vertices
  {
    const auto g = create_empty_undirected_graph();
    BOOST_CHECK(get_n_vertices(g) == 0);
  }
  //An empty directed graph has no vertices
  {
    const auto g = create_empty_directed_graph();
    BOOST_CHECK(get_n_vertices(g) == 0);
  }
  //A K2 graph has 2 vertices
  {
    const auto g = create_k2_graph();
    BOOST_CHECK(get_n_vertices(g) == 2);
  }
}

