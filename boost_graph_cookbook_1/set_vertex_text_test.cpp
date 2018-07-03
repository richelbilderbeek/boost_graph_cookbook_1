#include "set_vertex_text.h"
#include "set_vertex_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_text_vertices_graph.h"
#include "add_text_vertex.h"
#include "find_first_vertex_with_text.h"
#include "get_vertex_text.h"

BOOST_AUTO_TEST_CASE(set_vertex_text_thorough)
{
  auto g = create_empty_undirected_text_vertices_graph();
  const std::string old_text{"Dex"};
  add_text_vertex(old_text, g);
  const auto vd = find_first_vertex_with_text(old_text, g);
  BOOST_CHECK(get_vertex_text(vd, g) == old_text);
  const std::string new_text{"Diggy"};
  set_vertex_text(new_text, vd, g);
  BOOST_CHECK(get_vertex_text(vd, g) == new_text);

  
}
