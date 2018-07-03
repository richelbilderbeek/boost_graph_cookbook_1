#include "is_text_vertices_isomorphic.h"
#include "is_text_vertices_isomorphic_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "create_path_graph.h"
#include "create_text_vertices_path_graph.h"

BOOST_AUTO_TEST_CASE(is_text_vertices_isomorphic_thorough)
{
  {
    const auto g
      = create_text_vertices_path_graph({ "Alpha", "Beta", "Gamma" });
    const auto h
      = create_text_vertices_path_graph({ "Alpha", "Beta", "Gamma" });
    BOOST_CHECK(is_text_vertices_isomorphic(g, h));
  }
  {
    const auto g
      = create_text_vertices_path_graph({ "Alpha", "Beta", "Gamma" });
    const auto h
      = create_text_vertices_path_graph({ "Gamma", "Beta", "Alpha" });
    BOOST_CHECK(is_text_vertices_isomorphic(g, h));
  }
  {
    const auto g
      = create_text_vertices_path_graph({ "Alpha", "Beta", "Gamma" });
    const auto h
      = create_text_vertices_path_graph({ "Alpha", "Gamma", "Beta" });
    BOOST_CHECK(is_text_vertices_isomorphic(g, g));
    BOOST_CHECK(!is_text_vertices_isomorphic(g, h));
  }
}
