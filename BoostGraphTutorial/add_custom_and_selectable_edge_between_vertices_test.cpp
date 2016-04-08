#include "add_custom_and_selectable_edge_between_vertices.h"
#include <boost/test/unit_test.hpp>
#include "add_custom_and_selectable_edge_between_vertices_demo.impl"
#include "add_custom_and_selectable_edge_between_vertices.h"
#include "add_custom_vertex.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_between_vertices_thorough)
{
  auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
  const auto from = add_custom_vertex(
    my_custom_vertex("Bert"), g
  );
  const auto to = add_custom_vertex(
    my_custom_vertex("Ernie"), g
  );
  add_custom_and_selectable_edge_between_vertices(
    my_custom_edge("Friends"), false, from, to, g
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
}

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_between_vertices_with_another_custom_edge)
{
  using another_edge = std::string;
  using another_vertex = std::string;

  using another_graph = boost::adjacency_list<
    boost::vecS,
    boost::vecS,
    boost::undirectedS,
    boost::property<
      boost::vertex_custom_type_t, another_vertex,
      boost::property<
        boost::vertex_is_selected_t, bool
      >
    >,
    boost::property<
      boost::edge_custom_type_t, another_edge,
      boost::property<
        boost::edge_is_selected_t, bool
      >
    >
  >;
  another_graph g;
  const auto from = add_custom_vertex(
    another_vertex("Bert"), g
  );
  const auto to = add_custom_vertex(
    another_vertex("Ernie"), g
  );
  add_custom_and_selectable_edge_between_vertices(
    another_edge("Friends"), false, from, to, g
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
}

