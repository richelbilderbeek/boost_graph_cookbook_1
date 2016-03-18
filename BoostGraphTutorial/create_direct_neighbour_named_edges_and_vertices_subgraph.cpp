#include "create_direct_neighbour_named_edges_and_vertices_subgraph.h"
#include "create_direct_neighbour_named_edges_and_vertices_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_named_edges_and_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_edges_and_vertices_path_graph.h"
#include "get_edge_name.h"
#include "get_edge_names.h"
#include "get_vertex_name.h"
#include "get_vertex_names.h"

BOOST_AUTO_TEST_CASE(create_direct_neighbour_named_edges_and_vertices_subgraph_though)
{
  //K2
  {
    const auto g = create_named_edges_and_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_named_edges_and_vertices_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
      const auto vertex_names = get_vertex_names(h);
      std::set<std::string> vertex_names_set(std::begin(vertex_names),std::end(vertex_names));
      BOOST_CHECK(vertex_names_set.count("x") == 1);
      BOOST_CHECK(vertex_names_set.count("y") == 1);
      const auto edge_names = get_edge_names(h);
      std::set<std::string> edge_names_set(std::begin(edge_names),std::end(edge_names));
      BOOST_CHECK(edge_names_set.count("between") == 1);
    }
  }
  //K3
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {
      const auto h = create_direct_neighbour_named_edges_and_vertices_subgraph(
        *i,g
      );
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);
      const auto vertex_names = get_vertex_names(h);
      std::set<std::string> vertex_names_set(std::begin(vertex_names),std::end(vertex_names));
      BOOST_CHECK(vertex_names_set.count("top") == 1);
      BOOST_CHECK(vertex_names_set.count("right") == 1);
      BOOST_CHECK(vertex_names_set.count("left") == 1);
      const auto edge_names = get_edge_names(h);
      std::set<std::string> edge_names_set(std::begin(edge_names),std::end(edge_names));
      BOOST_CHECK(edge_names_set.count("AB") == 1);
      BOOST_CHECK(edge_names_set.count("BC") == 1);
      BOOST_CHECK(edge_names_set.count("CA") == 1);
    }
  }
  //Path graph
  {
    const auto g
      = create_named_edges_and_vertices_path_graph(
      { "1", "2" } ,
      { "A", "B", "C" }
    );
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i=vip.first; i!=j; ++i) {

      const auto h = create_direct_neighbour_named_edges_and_vertices_subgraph(
        *i,g
      );
      if (get_vertex_name(*i, g) == "A") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto vertex_names = get_vertex_names(h);
        std::set<std::string> vertex_names_set(std::begin(vertex_names),std::end(vertex_names));
        BOOST_CHECK(vertex_names_set.count("A") == 1);
        BOOST_CHECK(vertex_names_set.count("B") == 1);
        const auto edge_names = get_edge_names(h);
        std::set<std::string> edge_names_set(std::begin(edge_names),std::end(edge_names));
        BOOST_CHECK(edge_names_set.count("1") == 1);
      }
      if (get_vertex_name(*i, g) == "B") {
        BOOST_CHECK(boost::num_vertices(h) == 3);
        BOOST_CHECK(boost::num_edges(h) == 2);
        const auto vertex_names = get_vertex_names(h);
        std::set<std::string> vertex_names_set(std::begin(vertex_names),std::end(vertex_names));
        BOOST_CHECK(vertex_names_set.count("A") == 1);
        BOOST_CHECK(vertex_names_set.count("B") == 1);
        BOOST_CHECK(vertex_names_set.count("C") == 1);
        const auto edge_names = get_edge_names(h);
        std::set<std::string> edge_names_set(std::begin(edge_names),std::end(edge_names));
        BOOST_CHECK(edge_names_set.count("1") == 1);
        BOOST_CHECK(edge_names_set.count("2") == 1);
      }
      if (get_vertex_name(*i, g) == "C") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto vertex_names = get_vertex_names(h);
        std::set<std::string> vertex_names_set(std::begin(vertex_names),std::end(vertex_names));
        BOOST_CHECK(vertex_names_set.count("B") == 1);
        BOOST_CHECK(vertex_names_set.count("C") == 1);
        const auto edge_names = get_edge_names(h);
        std::set<std::string> edge_names_set(std::begin(edge_names),std::end(edge_names));
        BOOST_CHECK(edge_names_set.count("2") == 1);
      }
    }
  }
}
