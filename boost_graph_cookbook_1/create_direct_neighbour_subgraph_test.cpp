#include "create_direct_neighbour_subgraph.h"
#include "create_direct_neighbour_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_petersen_graph.h"


BOOST_AUTO_TEST_CASE(create_direct_neighbour_subgraph_thorough)
{
  //K2
  {
    const auto g = create_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);

    }
  }
  //K3
  {
    const auto g = create_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);

    }
  }
  //Petersen Graph
  {
    const auto g = create_petersen_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 4);
      BOOST_CHECK(boost::num_edges(h) == 3);
    }
  }
}
