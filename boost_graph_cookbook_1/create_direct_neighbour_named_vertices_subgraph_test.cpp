#include "create_direct_neighbour_named_vertices_subgraph.h"
#include "create_direct_neighbour_named_vertices_subgraph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>

#include "create_named_vertices_k2_graph.h"
#include "create_named_vertices_k3_graph.h"
#include "create_named_vertices_path_graph.h"
#include "create_named_vertices_petersen_graph.h"
#include "get_vertex_name.h"
#include "get_vertex_names.h"

BOOST_AUTO_TEST_CASE(create_direct_neighbour_named_vertices_subgraph_thorough)
{
  // K2
  {
    const auto g = create_named_vertices_k2_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h = create_direct_neighbour_named_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 2);
      BOOST_CHECK(boost::num_edges(h) == 1);
      const auto v = get_vertex_names(h);
      std::set<std::string> names(std::begin(v), std::end(v));
      BOOST_CHECK(names.count("Me") == 1);
      BOOST_CHECK(names.count("My computer") == 1);
    }
  }
  // K3
  {
    const auto g = create_named_vertices_k3_graph();
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {
      const auto h = create_direct_neighbour_named_vertices_subgraph(*i, g);
      BOOST_CHECK(boost::num_vertices(h) == 3);
      BOOST_CHECK(boost::num_edges(h) == 3);
      const auto v = get_vertex_names(h);
      std::set<std::string> names(std::begin(v), std::end(v));
      BOOST_CHECK(names.count("Karen") == 1);
      BOOST_CHECK(names.count("Kristel") == 1);
      BOOST_CHECK(names.count("Kathleen") == 1);
    }
  }
  // Path graph
  {
    const auto g = create_named_vertices_path_graph({ "A", "B", "C" });
    const auto vip = vertices(g);
    const auto j = vip.second;
    for (auto i = vip.first; i != j; ++i) {

      const auto h = create_direct_neighbour_named_vertices_subgraph(*i, g);
      if (get_vertex_name(*i, g) == "A") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_vertex_names(h);
        std::set<std::string> names(std::begin(v), std::end(v));
        BOOST_CHECK(names.count("A") == 1);
        BOOST_CHECK(names.count("B") == 1);
      }
      if (get_vertex_name(*i, g) == "B") {
        BOOST_CHECK(boost::num_vertices(h) == 3);
        BOOST_CHECK(boost::num_edges(h) == 2);
        const auto v = get_vertex_names(h);
        std::set<std::string> names(std::begin(v), std::end(v));
        BOOST_CHECK(names.count("A") == 1);
        BOOST_CHECK(names.count("B") == 1);
        BOOST_CHECK(names.count("C") == 1);
      }
      if (get_vertex_name(*i, g) == "C") {
        BOOST_CHECK(boost::num_vertices(h) == 2);
        BOOST_CHECK(boost::num_edges(h) == 1);
        const auto v = get_vertex_names(h);
        std::set<std::string> names(std::begin(v), std::end(v));
        BOOST_CHECK(names.count("B") == 1);
        BOOST_CHECK(names.count("C") == 1);
      }
    }
  }
}
