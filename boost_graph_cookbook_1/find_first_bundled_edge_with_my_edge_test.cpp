#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_bundled_edges_and_vertices_graph.h"
#include "find_first_bundled_edge_with_my_edge.h"
#include "find_first_bundled_edge_with_my_edge_demo.impl"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(find_first_bundled_edges_and_edge_with_my_edge_thorough)
{
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();
    const auto ed = find_first_bundled_edge_with_my_edge(
      my_bundled_edge("Oxygen", "Air", 1.0, 2.0), g);
    BOOST_CHECK(boost::source(ed, g) != boost::target(ed, g));
  }
}

BOOST_AUTO_TEST_CASE(find_first_bundled_edge_with_my_edge_when_edge_is_absent)
{
  const auto g = create_empty_directed_bundled_edges_and_vertices_graph();
  const my_bundled_edge v;
  assert(!has_bundled_edge_with_my_edge(v, g));
  BOOST_CHECK_THROW(
    find_first_bundled_edge_with_my_edge(v, g), std::invalid_argument);
}
