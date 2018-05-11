#include "create_all_direct_neighbour_subgraphs.h"
#include "create_all_direct_neighbour_subgraphs_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_petersen_graph.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_subgraphs_thorough)
{
  //K2
  {
    const auto v = create_all_direct_neighbour_subgraphs(create_k2_graph());
    BOOST_CHECK(v.size() == 2);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
    }
  }
  //K3
  {
    const auto v = create_all_direct_neighbour_subgraphs(create_k3_graph());
    BOOST_CHECK(v.size() == 3);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_subgraphs(create_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}
