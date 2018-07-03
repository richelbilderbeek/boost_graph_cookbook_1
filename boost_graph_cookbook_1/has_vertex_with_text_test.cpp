#include "has_vertex_with_text.h"
#include "has_vertex_with_text_demo.impl"


#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "add_textd_vertex.h"
#include "create_empty_undirected_textd_vertices_graph.h"

BOOST_AUTO_TEST_CASE(has_vertex_with_text_thorough)
{
  {
    auto g = create_empty_undirected_textd_vertices_graph();
    BOOST_CHECK(!has_vertex_with_text("Felix",g));
    add_textd_vertex("Felix",g);
    BOOST_CHECK(has_vertex_with_text("Felix",g));
  }
}
