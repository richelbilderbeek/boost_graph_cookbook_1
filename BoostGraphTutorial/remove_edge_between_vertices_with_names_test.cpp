#include "remove_edge_between_vertices_with_names.h"
#include "remove_edge_between_vertices_with_names_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_named_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(remove_edge_between_vertices_with_names_thorough)
{
  {
    auto g = create_named_edges_and_vertices_k3_graph();
    BOOST_CHECK(boost::num_edges(g) == 3);
    BOOST_CHECK(boost::num_vertices(g) == 3);
    remove_edge_between_vertices_with_names("top","right",g);
    BOOST_CHECK(boost::num_edges(g) == 2);
    BOOST_CHECK(boost::num_vertices(g) == 3);
  }
}
