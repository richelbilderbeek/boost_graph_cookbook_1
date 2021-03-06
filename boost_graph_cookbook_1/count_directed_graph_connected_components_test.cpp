#include "count_directed_graph_connected_components.h"
#include "count_directed_graph_connected_components_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_edge.h"
#include "create_empty_directed_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_path_graph.h"

BOOST_AUTO_TEST_CASE(count_directed_graph_connected_components_thorough)
{
  auto g = create_empty_directed_graph();
  BOOST_CHECK(count_directed_graph_connected_components(g) == 0);
  const auto vd_a = boost::add_vertex(g);
  const auto vd_b = boost::add_vertex(g);
  const auto vd_c = boost::add_vertex(g);
  boost::add_edge(vd_a, vd_b, g);
  boost::add_edge(vd_b, vd_c, g);
  boost::add_edge(vd_c, vd_a, g);
  BOOST_CHECK(count_directed_graph_connected_components(g) == 1);
  const auto vd_d = boost::add_vertex(g);
  const auto vd_e = boost::add_vertex(g);
  const auto vd_f = boost::add_vertex(g);
  boost::add_edge(vd_d, vd_e, g);
  boost::add_edge(vd_e, vd_f, g);
  boost::add_edge(vd_f, vd_d, g);
  BOOST_CHECK(count_directed_graph_connected_components(g) == 2);
}
