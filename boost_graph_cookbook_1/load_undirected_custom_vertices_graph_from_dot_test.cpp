#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ

#include "load_undirected_custom_vertices_graph_from_dot.h"
#include "load_undirected_custom_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_custom_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "file_to_vector.h"
#include "my_custom_vertex.h"
#include "install_vertex_custom_type.h"
#include "is_regular_file.h"
#include "create_custom_vertices_k2_graph.h"

BOOST_AUTO_TEST_CASE(load_undirected_custom_vertices_graph_from_dot_thorough)
{
  //Create the picture 'load_undirected_custom_vertices_graph_from_dot_test_k2_graph.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_custom_vertices_k2_graph();
    const std::string base_filename{"create_custom_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = file_to_vector(dot_filename);
    const auto h = load_undirected_custom_vertices_graph_from_dot(dot_filename);
    save_custom_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = file_to_vector(dot_filename);
    BOOST_CHECK(old_text == new_text);
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_custom_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_custom_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_custom_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
