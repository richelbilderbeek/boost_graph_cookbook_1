#include "find_first_edge_with_text.h"
#include "find_first_edge_with_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_text_edges_and_vertices_k3_graph.h"
#include "create_empty_directed_text_edges_and_vertices_graph.h"
BOOST_AUTO_TEST_CASE(find_first_edge_with_text_k3)
{
  const auto g = create_text_edges_and_vertices_k3_graph();
  const auto ed = find_first_edge_with_text("AB", g);
  BOOST_CHECK(boost::source(ed,g) != boost::target(ed,g));
}

BOOST_AUTO_TEST_CASE(find_first_edge_with_text_where_text_is_absent)
{
  const auto g = create_empty_directed_text_edges_and_vertices_graph();
  BOOST_CHECK_THROW(
    find_first_edge_with_text("AB", g),
    std::invalid_argument
  );
}

