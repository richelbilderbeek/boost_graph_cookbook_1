#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "load_undirected_graph_from_dot.h"
#include "load_undirected_graph_from_dot_demo.impl"

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_k2_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(load_undirected_graph_from_dot_thorough)
{
  // Create the picture 'load_undirected_graph_from_dot_test_k2.svg'
  // Create graphs, save it to dot
  // Create another graph by loading it, then save it to .dot, convert that .dot
  // to .svg
  const auto g = create_k2_graph();
  const std::string dot_filename{
    "load_undirected_graph_from_dot_test_k2.dot"
  };
  save_graph_to_dot(g, dot_filename);
  const auto h = load_undirected_graph_from_dot(dot_filename);
  BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
  BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
}

BOOST_AUTO_TEST_CASE(load_undirected_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_graph_from_dot(dot_filename), std::invalid_argument);
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
