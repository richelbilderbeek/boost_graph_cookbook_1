#include "find_first_custom_edge_with_my_edge.h"
#include "find_first_custom_edge_with_my_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_custom_edges_and_vertices_graph.h"
#include "has_custom_edge_with_my_edge.h"

BOOST_AUTO_TEST_CASE(find_first_custom_edge_with_my_edge_thorough)
{
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto ed = find_first_custom_edge_with_my_edge(
      my_custom_edge("AB","first",0.0,0.0),
      g
    );
    BOOST_CHECK(boost::source(ed,g) != boost::target(ed,g));
  }
}


BOOST_AUTO_TEST_CASE(find_first_custom_edge_with_my_edge_when_edge_is_absent)
{
  const auto g = create_empty_directed_custom_edges_and_vertices_graph();
  const my_custom_edge v;
  assert(!has_custom_edge_with_my_edge(v, g));
  BOOST_CHECK_THROW(
    find_first_custom_edge_with_my_edge(v, g),
    std::invalid_argument
  );
}

