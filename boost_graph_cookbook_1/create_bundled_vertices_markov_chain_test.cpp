#include "create_bundled_vertices_markov_chain.h"
#include "create_bundled_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include <boost/test/unit_test.hpp>

#include "create_bundled_vertices_markov_chain.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_names.h"
#include "save_bundled_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_bundled_vertices_markov_chain_use)
{
  const auto g = create_bundled_vertices_markov_chain();
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 4);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 4);
  const auto vip = get_vertex_iterators(g);
  BOOST_CHECK(vip.first != vip.second);
  const auto vds = get_vertex_descriptors(g);
  BOOST_CHECK(vds.size() == 2);
  const auto eip = get_edge_iterators(g);
  BOOST_CHECK(eip.first != eip.second);
  const auto eds = get_edge_descriptors(g);
  BOOST_CHECK(eds.size() == 4);
  const std::vector<my_bundled_vertex> vertex_my_vertexes{
    get_my_bundled_vertexes(g)
  };
  const std::vector<my_bundled_vertex> expected_my_vertexes{
    my_bundled_vertex("Sunny", "Yellow", 1.0, 2.0),
    my_bundled_vertex("Not rainy", "Not grey", 3.0, 4.0)
  };
  BOOST_CHECK(expected_my_vertexes == vertex_my_vertexes);
}
