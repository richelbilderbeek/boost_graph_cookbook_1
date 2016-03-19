#include "create_empty_directed_bundled_vertices_graph.h"
//#include "create_empty_directed_bundled_vertices_graph.impl"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_empty_directed_bundled_vertices_graph_throrough)
{
  //Basic tests
  {
    const auto g = create_empty_directed_bundled_vertices_graph();
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);
  }
  
}
