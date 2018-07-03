#include "remove_nth_vertex.h"
#include "remove_nth_vertex_demo.impl"

#include "create_k3_graph.h"
#include "create_petersen_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(remove_nth_vertex_detailed_on_k3)
{
  auto g = create_k3_graph();
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 3);
  BOOST_CHECK_THROW(remove_nth_vertex(3, g), std::invalid_argument);
  remove_nth_vertex(1, g);
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 2);
  BOOST_CHECK_THROW(remove_nth_vertex(2, g), std::invalid_argument);
  remove_nth_vertex(0, g);
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 1);
  BOOST_CHECK_THROW(remove_nth_vertex(1, g), std::invalid_argument);
  remove_nth_vertex(0, g);
  BOOST_CHECK_EQUAL(boost::num_vertices(g), 0);
  BOOST_CHECK_THROW(remove_nth_vertex(0, g), std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(remove_nth_vertex_rough_on_petersen_graph)
{
  auto g = create_petersen_graph();
  for (int i = 0; i != 10; ++i) {
    BOOST_CHECK_EQUAL(static_cast<int>(boost::num_vertices(g)), 10 - i);
    remove_nth_vertex(0, g);
  }
}
