#include "create_empty_undirected_graph_with_graph_name.h"
#include "create_empty_undirected_graph_with_graph_name_demo.impl"

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_empty_undirected_graph_with_graph_name_thorough)
{
  {
    auto g = create_empty_undirected_graph_with_graph_name();
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);

  }
}
