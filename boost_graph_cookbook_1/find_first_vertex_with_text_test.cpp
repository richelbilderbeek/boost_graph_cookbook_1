#include "find_first_vertex_with_text.h"
#include "find_first_vertex_with_text_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_textd_vertices_k2_graph.h"
#include "get_vertex_text.h"

BOOST_AUTO_TEST_CASE(find_first_vertex_with_text_thorough)
{
  {
    const auto g = create_textd_vertices_k2_graph();
    const auto vd
      = find_first_vertex_with_text(
        "My computer", g
      );
    BOOST_CHECK(out_degree(vd,g) == 1); //not boost::out_degree
    BOOST_CHECK(in_degree(vd,g) == 1); //not boost::in_degree
    BOOST_CHECK(get_vertex_text(vd,g) == "My computer");
  }
}

