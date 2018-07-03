#include "create_direct_neighbour_text_edges_and_vertices_subgraph.h"
#include "create_direct_neighbour_text_edges_and_vertices_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_text_edges_and_vertices_k2_graph.h"
#include "create_text_edges_and_vertices_k3_graph.h"
#include "create_text_edges_and_vertices_path_graph.h"
#include "get_edge_text.h"
#include "get_edge_texts.h"
#include "get_vertex_text.h"
#include "get_vertex_texts.h"

BOOST_AUTO_TEST_CASE(
  create_direct_neighbour_text_edges_and_vertices_subgraph_though)
{
  // K2
  {
    const auto g = create_text_edges_and_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h
        = create_direct_neighbour_text_edges_and_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
      const auto vertex_texts = get_vertex_texts(h);
      std::set<std::string> vertex_texts_set(
        std::begin(vertex_texts), std::end(vertex_texts));
      BOOST_CHECK(vertex_texts_set.count("x") == 1);
      BOOST_CHECK(vertex_texts_set.count("y") == 1);
      const auto edge_texts = get_edge_texts(h);
      std::set<std::string> edge_texts_set(
        std::begin(edge_texts), std::end(edge_texts));
      BOOST_CHECK(edge_texts_set.count("between") == 1);
    }
  }
  // K3
  {
    const auto g = create_text_edges_and_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h
        = create_direct_neighbour_text_edges_and_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);
      const auto vertex_texts = get_vertex_texts(h);
      std::set<std::string> vertex_texts_set(
        std::begin(vertex_texts), std::end(vertex_texts));
      BOOST_CHECK(vertex_texts_set.count("top") == 1);
      BOOST_CHECK(vertex_texts_set.count("right") == 1);
      BOOST_CHECK(vertex_texts_set.count("left") == 1);
      const auto edge_texts = get_edge_texts(h);
      std::set<std::string> edge_texts_set(
        std::begin(edge_texts), std::end(edge_texts));
      BOOST_CHECK(edge_texts_set.count("AB") == 1);
      BOOST_CHECK(edge_texts_set.count("BC") == 1);
      BOOST_CHECK(edge_texts_set.count("CA") == 1);
    }
  }
  // Path graph
  {
    const auto g = create_text_edges_and_vertices_path_graph(
      { "1", "2" }, { "A", "B", "C" });
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {

      const auto h
        = create_direct_neighbour_text_edges_and_vertices_subgraph(*i, g);
      if (get_vertex_text(*i, g) == "A") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto vertex_texts = get_vertex_texts(h);
        std::set<std::string> vertex_texts_set(
          std::begin(vertex_texts), std::end(vertex_texts));
        BOOST_CHECK(vertex_texts_set.count("A") == 1);
        BOOST_CHECK(vertex_texts_set.count("B") == 1);
        const auto edge_texts = get_edge_texts(h);
        std::set<std::string> edge_texts_set(
          std::begin(edge_texts), std::end(edge_texts));
        BOOST_CHECK(edge_texts_set.count("1") == 1);
      }
      if (get_vertex_text(*i, g) == "B") {
        BOOST_CHECK(boost::num_vertices(h) == 3);
        BOOST_CHECK(boost::num_edges(h) == 2);
        const auto vertex_texts = get_vertex_texts(h);
        std::set<std::string> vertex_texts_set(
          std::begin(vertex_texts), std::end(vertex_texts));
        BOOST_CHECK(vertex_texts_set.count("A") == 1);
        BOOST_CHECK(vertex_texts_set.count("B") == 1);
        BOOST_CHECK(vertex_texts_set.count("C") == 1);
        const auto edge_texts = get_edge_texts(h);
        std::set<std::string> edge_texts_set(
          std::begin(edge_texts), std::end(edge_texts));
        BOOST_CHECK(edge_texts_set.count("1") == 1);
        BOOST_CHECK(edge_texts_set.count("2") == 1);
      }
      if (get_vertex_text(*i, g) == "C") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto vertex_texts = get_vertex_texts(h);
        std::set<std::string> vertex_texts_set(
          std::begin(vertex_texts), std::end(vertex_texts));
        BOOST_CHECK(vertex_texts_set.count("B") == 1);
        BOOST_CHECK(vertex_texts_set.count("C") == 1);
        const auto edge_texts = get_edge_texts(h);
        std::set<std::string> edge_texts_set(
          std::begin(edge_texts), std::end(edge_texts));
        BOOST_CHECK(edge_texts_set.count("2") == 1);
      }
    }
  }
}
