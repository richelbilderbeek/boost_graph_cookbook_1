#include "create_empty_directed_graph.h"
#include "create_empty_directed_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "get_graph_name.h"


BOOST_AUTO_TEST_CASE(create_empty_directed_graph_thorough)
{

  auto g = create_empty_directed_graph();
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);

  //Sure, can
  add_vertex(g);
}
