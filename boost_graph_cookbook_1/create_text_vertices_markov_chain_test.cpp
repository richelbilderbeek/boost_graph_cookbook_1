#include "create_text_vertices_markov_chain.h"
#include "create_text_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_text_vertex.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_text_vertices_markov_chain.h"
#include "get_sorted_text_vertex_my_vertexes.h"
#include "create_nasty_directed_text_vertices_graph.h"

BOOST_AUTO_TEST_CASE(create_text_vertices_markov_chain_use)
{
  const auto g = create_text_vertices_markov_chain();
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
  const std::vector<std::string> expected_names{"Good", "Not bad"};
  const std::vector<std::string> vertex_names = get_vertex_names(g);
  BOOST_CHECK(expected_names == vertex_names);
}
