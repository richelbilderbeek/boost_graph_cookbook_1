#include "create_direct_neighbour_custom_edges_and_vertices_subgraph.h"
#include "create_direct_neighbour_custom_edges_and_vertices_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_custom_edges_and_vertices_k2_graph.h"
#include "create_custom_edges_and_vertices_k3_graph.h"
#include "create_custom_edges_and_vertices_path_graph.h"
#include "create_custom_edges_and_vertices_petersen_graph.h"
#include "get_my_custom_edges.h"
#include "get_my_custom_vertex.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(
  create_direct_neighbour_custom_edges_and_vertices_subgraph_thorough)
{
  // K2
  {
    const auto g = create_custom_edges_and_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h
        = create_direct_neighbour_custom_edges_and_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v), std::end(v));
      const my_custom_vertex a("A", "source", 0.0, 0.0);
      const my_custom_vertex b("B", "target", 3.14, 3.14);
      BOOST_CHECK(vertexes.count(a) == 1);
      BOOST_CHECK(vertexes.count(b) == 1);
    }
  }
  // K3
  {
    const auto g = create_custom_edges_and_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h
        = create_direct_neighbour_custom_edges_and_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);
      const auto v = get_my_custom_vertexes(h);
      std::set<my_custom_vertex> vertexes(std::begin(v), std::end(v));
      const auto e = get_my_custom_edges(h);
      std::set<my_custom_edge> edges(std::begin(e), std::end(e));
      const my_custom_vertex va("top", "source", 0.0, 0.0);
      const my_custom_vertex vb("right", "target", 3.14, 0);
      const my_custom_vertex vc("left", "target", 0, 3.14);
      const my_custom_edge ea("AB", "first", 0.0, 0.0);
      const my_custom_edge eb("BC", "second", 3.14, 3.14);
      const my_custom_edge ec("CA", "third", 3.14, 3.14);
      BOOST_CHECK(vertexes.count(va) == 1);
      BOOST_CHECK(vertexes.count(vb) == 1);
      BOOST_CHECK(vertexes.count(vc) == 1);
      BOOST_CHECK(edges.count(ea) == 1);
      BOOST_CHECK(edges.count(eb) == 1);
      BOOST_CHECK(edges.count(ec) == 1);
    }
  }
  // Path graph
  {
    const my_custom_vertex a("A", "first", 1.1, 2.2);
    const my_custom_vertex b("B", "second", 3.3, 4.4);
    const my_custom_vertex c("C", "third", 5.5, 6.6);
    const my_custom_edge d("1", "first", 7.7, 8.8);
    const my_custom_edge e("2", "second", 9.9, 0.0);
    std::vector<my_custom_edge> my_edges = { d, e };
    std::vector<my_custom_vertex> my_vertices = { a, b, c };
    const auto g
      = create_custom_edges_and_vertices_path_graph(my_edges, my_vertices);
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {

      const auto h
        = create_direct_neighbour_custom_edges_and_vertices_subgraph(*i, g);

      if (get_my_custom_vertex(*i, g) == a) {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v), std::end(v));
        BOOST_CHECK(vertexes.count(a) == 1);
        BOOST_CHECK(vertexes.count(b) == 1);
      }
      if (get_my_custom_vertex(*i, g) == b) {
        BOOST_CHECK(boost::num_vertices(h) == 3);
        BOOST_CHECK(boost::num_edges(h) == 2);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v), std::end(v));
        BOOST_CHECK(vertexes.count(a) == 1);
        BOOST_CHECK(vertexes.count(b) == 1);
        BOOST_CHECK(vertexes.count(c) == 1);
      }
      if (get_my_custom_vertex(*i, g) == c) {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_my_custom_vertexes(h);
        std::set<my_custom_vertex> vertexes(std::begin(v), std::end(v));
        BOOST_CHECK(vertexes.count(b) == 1);
        BOOST_CHECK(vertexes.count(c) == 1);
      }
    }
  }
}
