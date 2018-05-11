#include "add_edge_between_named_vertices.h"
#include "add_edge_between_named_vertices_demo.impl"
#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(add_edge_between_named_vertices_once)
{
  auto g = create_empty_undirected_named_vertices_graph();
  const std::string name1{"Bert"};
  const std::string name2{"Ernie"};
  add_named_vertex(name1, g);
  add_named_vertex(name2, g);
  add_edge_between_named_vertices(name1, name2, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

BOOST_AUTO_TEST_CASE(add_edge_between_named_vertices_another_name_type)
{
  using another_name_type = int;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_name_t, another_name_type
    >
  >;
  another_graph g;
  add_named_vertex(42, g);
  add_named_vertex(314, g);
  add_edge_between_named_vertices(42, 314, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

