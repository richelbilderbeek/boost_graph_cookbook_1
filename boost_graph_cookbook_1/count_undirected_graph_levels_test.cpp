#include "count_undirected_graph_levels.h"
#include "count_undirected_graph_levels_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_path_graph.h"
#include "create_empty_directed_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "add_edge.h"

BOOST_AUTO_TEST_CASE(test_count_undirected_graph_levels_thorough)
{
  auto g = create_empty_undirected_graph();
  const auto vd_a = boost::add_vertex(g);
  const auto vd_b = boost::add_vertex(g);
  const auto vd_c = boost::add_vertex(g);
  const auto vd_d = boost::add_vertex(g);
  BOOST_CHECK(count_undirected_graph_levels(vd_a, g) == 0);
  boost::add_edge(vd_a, vd_b, g);
  BOOST_CHECK(count_undirected_graph_levels(vd_a, g) == 1);
  boost::add_edge(vd_b, vd_c, g);
  BOOST_CHECK(count_undirected_graph_levels(vd_a, g) == 2);
  boost::add_edge(vd_c, vd_d, g);
  BOOST_CHECK(count_undirected_graph_levels(vd_a, g) == 3);
}
