#include "add_bundled_vertex.h"

#include <boost/test/unit_test.hpp>
#include "add_bundled_vertex_demo.impl"
#include "create_empty_undirected_bundled_vertices_graph.h"

BOOST_AUTO_TEST_CASE(test_add_bundled_vertex_thorough)
{
  //Add 1
  {
    auto g = create_empty_undirected_bundled_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_bundled_vertex vertex("X");
    add_bundled_vertex(vertex, g);
    BOOST_CHECK(boost::num_vertices(g) == 1);
    BOOST_CHECK(boost::num_edges(g) == 0);
  }
  //Add 2
  {
    auto g = create_empty_undirected_bundled_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_bundled_vertex vertex_1("X");
    const my_bundled_vertex vertex_2("Y");
    add_bundled_vertex(vertex_1, g);
    add_bundled_vertex(vertex_2, g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 0);
  }
  
}
