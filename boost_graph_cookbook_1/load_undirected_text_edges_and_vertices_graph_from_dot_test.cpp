#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_undirected_text_edges_and_vertices_graph_from_dot.h"
#include "load_undirected_text_edges_and_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_text_edges_and_vertices_k3_graph.h"
#include "convert_dot_to_svg.h"
#include "save_text_edges_and_vertices_graph_to_dot.h"
#include "file_to_vector.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(load_undirected_text_edges_and_vertices_graph_from_dot_thorough)
{
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_text_edges_and_vertices_k3_graph();
    const std::string dot_filename{"load_undirected_text_edges_and_vertices_graph_from_dot_test_markov_chain.dot"};
    save_text_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = file_to_vector(dot_filename);
    const auto h = load_undirected_text_edges_and_vertices_graph_from_dot(dot_filename);
    save_text_edges_and_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = file_to_vector(dot_filename);
    BOOST_CHECK(old_text == new_text);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_text_edges_and_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_text_edges_and_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_text_edges_and_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
