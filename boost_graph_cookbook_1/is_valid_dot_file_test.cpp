#include "is_valid_dot_file.h"

#include "copy_file.h"
#include "create_empty_directed_graph.h"
#include "create_empty_undirected_graph.h"
#include "create_k2_graph.h"
#include "create_k3_graph.h"
#include "file_to_vector.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include <boost/test/unit_test.hpp>
#include <fstream>

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(is_valid_dot_file_empty_undirected_graph)
{
  // An empty undirected graph should be convertable to a valid .dot file
  const auto g = create_empty_undirected_graph();
  const std::string filename{
    "is_valid_dot_file_test_create_empty_undirected_graph.dot"
  };
  save_graph_to_dot(g, filename);
  BOOST_CHECK(is_valid_dot_file(filename));
  std::remove(filename.c_str());
}

BOOST_AUTO_TEST_CASE(is_valid_dot_file_empty_directed_graph)
{
  // An empty directed graph should be convertable to a valid .dot file
  const auto g = create_empty_directed_graph();
  const std::string filename{
    "is_valid_dot_file_test_create_empty_directed_graph.dot"
  };
  save_graph_to_dot(g, filename);
  BOOST_CHECK(is_valid_dot_file(filename));
  std::remove(filename.c_str());
}

BOOST_AUTO_TEST_CASE(is_valid_dot_file_k2_graph)
{
  // A K2 graph should be convertable to a valid .dot file
  const auto g = create_k2_graph();
  const std::string filename{ "is_valid_dot_file_test_create_k2_graph.dot" };
  save_graph_to_dot(g, filename);
  BOOST_CHECK(is_valid_dot_file(filename));
  std::remove(filename.c_str());
}

BOOST_AUTO_TEST_CASE(is_valid_dot_file_k3_graph)
{
  // A K2 graph should be convertable to a valid .dot file
  const auto g = create_k3_graph();
  const std::string filename{ "is_valid_dot_file_test_create_k2_graph.dot" };
  save_graph_to_dot(g, filename);
  BOOST_CHECK(is_valid_dot_file(filename));
  std::remove(filename.c_str());
}
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

BOOST_AUTO_TEST_CASE(is_valid_dot_file_20160319)
{
  {
    const std::string filename{ "test_20160319_1.dot" };
    {
      std::ofstream f(filename);
      f << "digraph G {\n"
        << "name=\"Two-state Markov chain\";\n"
        << "0;\n"
        << "1;\n"
        << "0->0 ;\n"
        << "0->1 ;\n"
        << "1->0 ;\n"
        << "1->1 ;\n"
        << "}\n" // Note: newline
        ;
    }
    BOOST_CHECK(is_valid_dot_file(filename));
    std::remove(filename.c_str());
  }
  {
    const std::string filename{ "test_20160319_2.dot" };
    {
      std::ofstream f(filename);
      f << "digraph G {\n"
        << "name=\"Two-state Markov chain\";\n"
        << "0;\n"
        << "1;\n"
        << "0->0 ;\n"
        << "0->1 ;\n"
        << "1->0 ;\n"
        << "1->1 ;\n"
        << "}" // No newline
        ;
    }
    BOOST_CHECK(is_valid_dot_file(filename));
    std::remove(filename.c_str());
  }
}
