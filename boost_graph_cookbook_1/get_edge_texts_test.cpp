#include "get_edge_texts.h"
#include "get_edge_texts_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_text_edge.h"
#include "create_k2_graph.h"
#include "create_empty_undirected_text_edges_and_vertices_graph.h"
#include "create_text_edges_and_vertices_k3_graph.h"

BOOST_AUTO_TEST_CASE(get_edge_texts_thorough)
{
  {
    auto g = create_empty_undirected_text_edges_and_vertices_graph();
    const std::string edge_text_1{"Eugene"};
    const std::string edge_text_2{"Another Eugene"};
    add_text_edge(edge_text_1, g);
    add_text_edge(edge_text_2, g);
    const std::vector<std::string> expected_texts{edge_text_1, edge_text_2};
    const std::vector<std::string> edge_texts{get_edge_texts(g)};
    BOOST_CHECK(expected_texts == edge_texts);
  }
  //Named K3 graph
  {
    const auto g = create_text_edges_and_vertices_k3_graph();
    const std::vector<std::string> expected_texts{"AB", "BC", "CA"};
    const std::vector<std::string> edge_texts{get_edge_texts(g)};
    BOOST_CHECK(expected_texts == edge_texts);
  }
}
