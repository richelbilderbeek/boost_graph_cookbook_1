#include "create_empty_directed_text_edges_and_vertices_graph.h"
#include "create_empty_directed_text_edges_and_vertices_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "add_text_edge.h"

#include "get_edge_texts.h"
#include "get_vertex_texts.h"
#include "create_empty_directed_text_edges_and_vertices_graph.h"

BOOST_AUTO_TEST_CASE(create_empty_directed_text_edges_and_vertices_graph_thorough)
{
  {
    auto g = create_empty_directed_text_edges_and_vertices_graph();
    add_text_edge("Eugene", g);
    const std::vector<std::string> expected_vertex_texts{"",""};
    const std::vector<std::string> vertex_texts = get_vertex_texts(g);
    BOOST_CHECK(expected_vertex_texts == vertex_texts);
    const std::vector<std::string> expected_edge_texts{"Eugene"};
    const std::vector<std::string> edge_texts = get_edge_texts(g);
    BOOST_CHECK(expected_edge_texts == edge_texts);
  }

  {
    const auto g = create_empty_directed_text_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);
    const std::vector<std::string> expected_vertex_texts{};
    const std::vector<std::string> vertex_texts = get_vertex_texts(g);
    BOOST_CHECK(expected_vertex_texts == vertex_texts);
    const std::vector<std::string> expected_edge_texts{};
    const std::vector<std::string> edge_texts = get_edge_texts(g);
    BOOST_CHECK(expected_edge_texts == edge_texts);
  }
}
