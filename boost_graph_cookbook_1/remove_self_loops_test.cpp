#include "remove_self_loops.h"
#include "remove_self_loops_demo.impl"

#include "create_k3_graph.h"
#include "create_markov_chain.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(remove_self_loops_on_k3_graph_will_not_remove_vertices)
{
  auto g = create_k3_graph();
  BOOST_CHECK_EQUAL(boost::num_edges(g), 3);
  remove_self_loops(g);
  BOOST_CHECK_EQUAL(boost::num_edges(g), 3);
}

BOOST_AUTO_TEST_CASE(remove_self_loops_on_markov_change_will_remove_vertices)
{
  auto g = create_markov_chain();
  BOOST_CHECK_EQUAL(boost::num_edges(g), 4);
  remove_self_loops(g);
  BOOST_CHECK_EQUAL(boost::num_edges(g), 2);
}
