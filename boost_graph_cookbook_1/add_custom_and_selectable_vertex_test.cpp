#include "add_custom_and_selectable_vertex.h"
#include "add_custom_and_selectable_vertex_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_vertex_thorough)
{
  // Add 1
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_custom_vertex vertex("X");
    add_custom_and_selectable_vertex(vertex, true, g);
    BOOST_CHECK(boost::num_vertices(g) == 1);
    BOOST_CHECK(boost::num_edges(g) == 0);
  }
  // Add 2
  {
    auto g = create_empty_undirected_custom_and_selectable_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_custom_vertex vertex_1("X");
    const my_custom_vertex vertex_2("Y");
    add_custom_and_selectable_vertex(vertex_1, true, g);
    add_custom_and_selectable_vertex(vertex_2, false, g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 0);
  }
}
