#include "get_edge_between_vertices.h"
#include "get_edge_between_vertices_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_directed_graph.h"
#include "create_k2_graph.h"

BOOST_AUTO_TEST_CASE(get_edge_between_vertices_thorough)
{
  auto g = create_k2_graph();
  const auto vd_1 = *vertices(g).first;
  const auto vd_2 = *(++vertices(g).first);
  BOOST_CHECK(!has_edge_between_vertices(vd_1, vd_1, g));
  BOOST_CHECK(has_edge_between_vertices(vd_1, vd_2, g));
  BOOST_CHECK(has_edge_between_vertices(vd_2, vd_1, g));
  BOOST_CHECK(!has_edge_between_vertices(vd_2, vd_2, g));
  const auto ed = get_edge_between_vertices(vd_1, vd_2, g);
  boost::remove_edge(ed, g);
  BOOST_CHECK(boost::num_edges(g) == 0);
}

BOOST_AUTO_TEST_CASE(get_edge_between_vertices_when_no_edge_is_present)
{
  auto g = create_empty_directed_graph();
  const auto vd_1 = boost::add_vertex(g);
  const auto vd_2 = boost::add_vertex(g);
  BOOST_CHECK_THROW(
    get_edge_between_vertices(vd_1, vd_2, g), std::invalid_argument);
}
