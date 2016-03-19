#include "add_bundled_edge.h"

#include "add_bundled_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"

#include "add_bundled_vertex.h"
#include "get_my_bundled_edges.h"
#include "get_my_custom_edges.h"

BOOST_AUTO_TEST_CASE(test_add_bundled_edge_thorough)
{
  //Add 1
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_bundled_edge edge("X");
    const auto vd_from = add_bundled_vertex(my_bundled_vertex("From"), g);
    const auto vd_to = add_bundled_vertex(my_bundled_vertex("To"), g);
    add_bundled_edge(vd_from, vd_to, edge, g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 1);
    const std::vector<my_bundled_edge> edges{get_my_bundled_edges(g)};
    const std::vector<my_bundled_edge> expected_edges{edge};
    BOOST_CHECK(edges == expected_edges);
  }
  //Add 2
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const auto vd_a = add_bundled_vertex(my_bundled_vertex("A"), g);
    const auto vd_b = add_bundled_vertex(my_bundled_vertex("B"), g);
    const auto vd_c = add_bundled_vertex(my_bundled_vertex("C"), g);
    const my_bundled_edge edge_1("X");
    const my_bundled_edge edge_2("Y");
    add_bundled_edge(vd_a, vd_b, edge_1, g);
    add_bundled_edge(vd_b, vd_c, edge_2, g);
    BOOST_CHECK(boost::num_vertices(g) == 3);
    BOOST_CHECK(boost::num_edges(g) == 2);
    const std::vector<my_bundled_edge> edges{get_my_bundled_edges(g)};
    const std::vector<my_bundled_edge> expected_edges{edge_1, edge_2};
    BOOST_CHECK(edges == expected_edges);
  }
}
