#include "create_empty_directed_text_edges_and_vertices_graph.h"
#include "create_empty_directed_text_edges_and_vertices_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "add_text_edge.h"

#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "create_empty_directed_text_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(create_empty_directed_text_edges_and_vertices_graph_thorough)
{
  {
    auto g = create_empty_directed_text_edges_and_vertices_graph();
    add_text_edge("Eugene", g);
    const std::vector<std::string> expected_vertex_names{"",""};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    BOOST_CHECK(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{"Eugene"};
    const std::vector<std::string> edge_names = get_edge_names(g);
    BOOST_CHECK(expected_edge_names == edge_names);
  }

  {
    const auto g = create_empty_directed_text_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);
    const std::vector<std::string> expected_vertex_names{};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    BOOST_CHECK(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{};
    const std::vector<std::string> edge_names = get_edge_names(g);
    BOOST_CHECK(expected_edge_names == edge_names);
  }
}
