#include "find_first_edge_with_name.h"
#include "find_first_edge_with_name_demo.impl"

#include "create_empty_directed_named_edges_and_vertices_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include <boost/test/unit_test.hpp>
BOOST_AUTO_TEST_CASE(find_first_edge_with_name_k3)
{
  const auto g = create_named_edges_and_vertices_k3_graph();
  const auto ed = find_first_edge_with_name("AB", g);
  BOOST_CHECK(boost::source(ed, g) != boost::target(ed, g));
}

BOOST_AUTO_TEST_CASE(find_first_edge_with_name_where_name_is_absent)
{
  const auto g = create_empty_directed_named_edges_and_vertices_graph();
  BOOST_CHECK_THROW(find_first_edge_with_name("AB", g), std::invalid_argument);
}
