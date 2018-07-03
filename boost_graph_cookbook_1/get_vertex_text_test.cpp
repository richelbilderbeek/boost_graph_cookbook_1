#include "get_vertex_text.h"
#include "get_vertex_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/graph/properties.hpp>

#include "create_empty_undirected_text_vertices_graph.h"
#include "add_text_vertex.h"
#include "find_first_vertex_with_text.h"

BOOST_AUTO_TEST_CASE(get_vertex_text_thorough)
{
  auto g = create_empty_undirected_text_vertices_graph();
  const std::string text{"Dex"};
  add_text_vertex(text, g);
  const auto vd = find_first_vertex_with_text(text,g);
  BOOST_CHECK(get_vertex_text(vd,g) == text);
}
