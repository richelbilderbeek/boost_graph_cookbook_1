#include "add_bundled_vertex.h"

#include "add_bundled_vertex_demo.impl"
#include "create_empty_undirected_bundled_vertices_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_add_bundled_vertex_add_one)
{
  auto g = create_empty_undirected_bundled_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_bundled_vertex vertex("X");
  add_bundled_vertex(vertex, g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
}

BOOST_AUTO_TEST_CASE(test_add_bundled_vertex_add_two)
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

BOOST_AUTO_TEST_CASE(test_add_bundled_vertex_for_another_vertex_type)
{
  using another_bundled_vertex = std::string;
  using another_graph = boost::adjacency_list<boost::vecS, boost::vecS,
    boost::undirectedS, another_bundled_vertex>;
  another_graph g;
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  add_bundled_vertex(another_bundled_vertex("From"), g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
