#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "save_graph_to_dot.h"
#include "save_graph_to_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include <sstream>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "file_to_vector.h"
#include "is_valid_dot_file.h"
#include "show_dot.h"

BOOST_AUTO_TEST_CASE(save_graph_to_dot_thorough)
{

  // create_empty_directed_graph
  {
    const auto g = create_empty_directed_graph();
    const std::string base_filename{
      "save_graph_to_dot_test_empty_directed_graph"
    };
    const std::string dot_filename{ base_filename + ".dot" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{ file_to_vector(dot_filename) };
    const std::vector<std::string> expected_text{ "digraph G {", "}" };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
  // create_empty_undirected_graph
  {
    const auto g = create_empty_undirected_graph();
    const std::string base_filename{
      "save_graph_to_dot_test_empty_undirected_graph"
    };
    const std::string dot_filename{ base_filename + ".dot" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{ file_to_vector(dot_filename) };
    const std::vector<std::string> expected_text{ "graph G {", "}" };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
  // create_k2_graph
  {
    const auto g = create_k2_graph();
    const std::string base_filename{ "save_graph_to_dot_test_k2_graph" };
    const std::string dot_filename{ base_filename + ".dot" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{ file_to_vector(dot_filename) };
    const std::vector<std::string> expected_text{ "graph G {", "0;", "1;",
      "0--1 ;", "}" };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
  // Show it does not store the vertex names
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{
      "save_graph_to_dot_test_named_vertices_k2_graph"
    };
    const std::string dot_filename{ base_filename + ".dot" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    const std::vector<std::string> text{ file_to_vector(dot_filename) };
    const std::vector<std::string> expected_text{ "graph G {", "0;", "1;",
      "0--1 ;", "}" };
    BOOST_CHECK(text == expected_text);
    std::remove(dot_filename.c_str());
  }
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
