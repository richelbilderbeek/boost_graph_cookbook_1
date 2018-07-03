#include "get_edge_text.h"
#include "get_edge_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_text_edges_and_vertices_graph.h"
#include "add_text_edge.h"
#include "find_first_edge_with_text.h"

BOOST_AUTO_TEST_CASE(get_edge_text_thorough)
{
  auto g = create_empty_undirected_text_edges_and_vertices_graph();
  const std::string text{"Dex"};
  add_text_edge(text, g);
  const auto vd = find_first_edge_with_text(text,g);
  BOOST_CHECK(get_edge_text(vd,g) == text);
}
