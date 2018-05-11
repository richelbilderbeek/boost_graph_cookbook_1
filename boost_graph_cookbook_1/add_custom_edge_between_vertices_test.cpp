#include "add_custom_edge_between_vertices.h"
#include "add_custom_edge_between_vertices_demo.impl"

#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge_between_vertices.h"
#include "add_custom_vertex.h"

BOOST_AUTO_TEST_CASE(test_add_custom_edge_between_vertices_thorough)
{
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    const auto from = add_custom_vertex(
      my_custom_vertex("Bert"), g
    );
    const auto to = add_custom_vertex(
      my_custom_vertex("Ernie"), g
    );
    add_custom_edge_between_vertices(
      my_custom_edge("Friends"), from, to, g
    );
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
}

BOOST_AUTO_TEST_CASE(test_add_custom_edge_between_vertices_for_another_edge)
{
  using another_edge = std::string;
  using another_vertex = std::string;
  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_custom_type_t, another_vertex
    >,
    boost::property<
      boost::edge_custom_type_t, another_edge
    >
  >;
  another_graph g;
  const auto from = add_custom_vertex(
    another_vertex("Bert"), g
  );
  const auto to = add_custom_vertex(
    another_vertex("Ernie"), g
  );
  add_custom_edge_between_vertices(
    another_edge("Friends"), from, to, g
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
}

