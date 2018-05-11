#include "add_vertex.h"
#include "add_vertex_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_graph.h"
#include "create_empty_directed_graph.h"

BOOST_AUTO_TEST_CASE(add_vertex_undirected_graph)
{
  auto g = create_empty_undirected_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  add_vertex(g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
}

BOOST_AUTO_TEST_CASE(add_vertex_directed_graph)
{
  auto g = create_empty_directed_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  add_vertex(g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
