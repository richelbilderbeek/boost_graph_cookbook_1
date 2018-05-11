#include "create_markov_chain_with_graph_name.h"
#include "create_markov_chain_with_graph_name_demo.impl"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_markov_chain_with_graph_name_basic)
{
  const auto g = create_markov_chain_with_graph_name();
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 4);
  BOOST_CHECK(get_graph_name(g) == "Two-state Markov chain");
}
