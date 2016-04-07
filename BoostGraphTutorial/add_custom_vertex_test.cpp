#include "add_custom_vertex.h"
#include "add_custom_vertex_demo.impl"


#include <boost/test/unit_test.hpp>
#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_vertices_graph.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(test_add_custom_vertex_add_one)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_custom_vertex vertex("X");
  add_custom_vertex(vertex, g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<my_custom_vertex> vertices{get_my_custom_vertexes(g)};
  const std::vector<my_custom_vertex> expected_vertices{vertex};
  BOOST_CHECK(vertices == expected_vertices);
}

BOOST_AUTO_TEST_CASE(test_add_custom_vertex_add_two)
{
  auto g = create_empty_undirected_custom_vertices_graph();
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const my_custom_vertex vertex_1("X");
  const my_custom_vertex vertex_2("Y");
  add_custom_vertex(vertex_1, g);
  add_custom_vertex(vertex_2, g);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const std::vector<my_custom_vertex> vertices{get_my_custom_vertexes(g)};
  const std::vector<my_custom_vertex> expected_vertices{vertex_1, vertex_2};
  BOOST_CHECK(vertices == expected_vertices);
}

BOOST_AUTO_TEST_CASE(test_add_custom_vertex_add_another_type)
{
  using another_vertex = std::string;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_custom_type_t, another_vertex
    >
  >;
  another_graph g;
  BOOST_CHECK(boost::num_vertices(g) == 0);
  BOOST_CHECK(boost::num_edges(g) == 0);
  const another_vertex vertex("X");
  add_custom_vertex(vertex, g);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(boost::num_edges(g) == 0);
}
