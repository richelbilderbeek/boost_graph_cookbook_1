#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_directed_graph_from_dot.h"
#include "load_directed_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(load_directed_graph_from_dot_thorough)
{
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  const auto g = create_markov_chain();
  const std::string dot_filename{"load_directed_graph_from_dot_test_markov_chain.dot"};
  save_graph_to_dot(g, dot_filename);
  const auto h = load_directed_graph_from_dot(dot_filename);
  save_graph_to_dot(h, dot_filename);
  BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
  BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
}

BOOST_AUTO_TEST_CASE(load_directed_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_directed_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
