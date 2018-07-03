#include "get_edge_names.h"
#include "get_edge_names_demo.impl"

#include "add_named_edge.h"
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(get_edge_names_thorough)
{
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    const std::string edge_name_1{ "Eugene" };
    const std::string edge_name_2{ "Another Eugene" };
    add_named_edge(edge_name_1, g);
    add_named_edge(edge_name_2, g);
    const std::vector<std::string> expected_names{ edge_name_1, edge_name_2 };
    const std::vector<std::string> edge_names{ get_edge_names(g) };
    BOOST_CHECK(expected_names == edge_names);
  }
  // Named K3 graph
  {
    const auto g = create_named_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_names{ "AB", "BC", "CA" };
    const std::vector<std::string> edge_names{ get_edge_names(g) };
    BOOST_CHECK(expected_names == edge_names);
  }
}
