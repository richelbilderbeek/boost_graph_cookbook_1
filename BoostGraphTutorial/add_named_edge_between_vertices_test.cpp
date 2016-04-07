#include "add_named_edge_between_vertices.h"
#include "add_named_edge_between_vertices_demo.impl"

#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "add_named_edge_between_vertices.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(add_named_edge_between_vertices_add_one)
{
  auto g = create_empty_undirected_named_edges_and_vertices_graph();
  const auto from = add_named_vertex("Bert", g);
  const auto to = add_named_vertex("Ernie", g);
  add_named_edge_between_vertices("Friends", from, to, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

BOOST_AUTO_TEST_CASE(add_named_edge_between_vertices_add_another)
{
  using another_edge_name = int;
  using another_vertex_name = int;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<boost::vertex_name_t,another_vertex_name>,
    boost::property<boost::edge_name_t,another_edge_name>
  >;

  another_graph g;
  another_vertex_name vertex_name1{42};
  another_vertex_name vertex_name2{314};
  another_edge_name edge_name{123};
  const auto from = add_named_vertex(vertex_name1, g);
  const auto to = add_named_vertex(vertex_name2, g);
  add_named_edge_between_vertices(edge_name, from, to, g);
  BOOST_CHECK(boost::num_edges(g) == 1);
}

