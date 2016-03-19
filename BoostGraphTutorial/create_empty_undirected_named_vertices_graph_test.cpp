#include "create_empty_undirected_named_vertices_graph.h"
#include "create_empty_undirected_named_vertices_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"

BOOST_AUTO_TEST_CASE(create_empty_undirected_named_vertices_graph_thorough)
{
  const auto g = create_empty_undirected_named_vertices_graph();
  const auto vip = get_vertex_iterators(g);
  BOOST_CHECK(vip.first == vip.second);
  const auto vds = get_vertex_descriptors(g);
  BOOST_CHECK(vds.empty());
  const auto eip = get_edge_iterators(g);
  BOOST_CHECK(eip.first == eip.second);
  const auto eds = get_edge_descriptors(g);
  BOOST_CHECK(eds.empty());

  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);

  //Sure, can
  //add_vertex(g);
}
