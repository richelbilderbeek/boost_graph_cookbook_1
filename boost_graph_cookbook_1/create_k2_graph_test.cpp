#include "create_k2_graph.h"
#include "create_k2_graph_demo.impl"

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_k2_graph_thorough)
{
  // Basic tests
  {
    const auto g = create_k2_graph();
    const auto vip = get_vertex_iterators(g);
    BOOST_CHECK(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    BOOST_CHECK(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    BOOST_CHECK(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 1);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
  }
  // Copy a graph
  {
    const auto g = create_k2_graph();
    const auto h(g);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  }
}
