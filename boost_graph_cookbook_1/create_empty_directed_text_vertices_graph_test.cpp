#include "create_empty_directed_text_vertices_graph.h"
#include "create_empty_directed_text_vertices_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "add_edge.h"
#include "add_text_vertex.h"

BOOST_AUTO_TEST_CASE(create_empty_directed_text_vertices_graph_thorough)
{
  //Basic testing
  {
    auto g = create_empty_directed_text_vertices_graph();
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
    add_text_vertex("A",g);
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 1);
    add_edge(g);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 3);
  }
}
