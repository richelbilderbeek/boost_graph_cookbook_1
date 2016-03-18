#include "add_edge.h"
#include "add_edge_demo.impl"


#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"

BOOST_AUTO_TEST_CASE(test_add_edge_thorough)
{
  //Add edge to undirected graph
  {
    auto g = create_empty_undirected_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    add_edge(g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
  //Add edge to directed graph
  {
    auto g = create_empty_directed_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    add_edge(g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
}
