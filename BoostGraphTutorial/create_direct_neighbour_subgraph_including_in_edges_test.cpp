#include "create_direct_neighbour_subgraph_including_in_edges.h"
#include "create_direct_neighbour_subgraph_including_in_edges_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_directed_graph.h"
#include "create_direct_neighbour_subgraph.h"


BOOST_AUTO_TEST_CASE(create_direct_neighbour_subgraph_including_in_edges_thorough)
{
  // a -> b
  {
    auto g = create_empty_directed_graph();
    auto vd_a = boost::add_vertex(g);
    auto vd_b = boost::add_vertex(g);
    boost::add_edge(vd_a, vd_b, g);
    // a is connected to b
    {
      const auto h = create_direct_neighbour_subgraph_including_in_edges(vd_a, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
    }
    // b is connected to a by in edge, create_direct_neighbour_subgraph does not include a
    {
      const auto h = create_direct_neighbour_subgraph(vd_a, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
    }
    // b is connected to a
    {
      const auto h = create_direct_neighbour_subgraph_including_in_edges(vd_a, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
    }
  }
}
