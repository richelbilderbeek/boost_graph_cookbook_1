#include "create_empty_undirected_graph.h"
#include "create_empty_undirected_graph.impl"
#include "create_empty_undirected_graph_demo.impl"

#include <boost/test/unit_test.hpp>





BOOST_AUTO_TEST_CASE(create_empty_undirected_graph_thorough)
{
  auto g = create_empty_undirected_graph();
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);

  //Sure, can
  add_vertex(g);
}
