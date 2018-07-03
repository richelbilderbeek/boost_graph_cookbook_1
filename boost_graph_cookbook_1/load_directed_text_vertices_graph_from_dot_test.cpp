#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "load_directed_text_vertices_graph_from_dot.h"
#include "load_directed_text_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_nasty_directed_text_vertices_graph.h"
#include "create_text_vertices_markov_chain.h"
#include "file_to_vector.h"
#include "get_sorted_vertex_texts.h"
#include "is_regular_file.h"
#include "save_text_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(load_directed_text_vertices_graph_from_dot_thorough)
{
  //Basic
  {
    const auto g = create_text_vertices_markov_chain();
    const std::string dot_filetext{"load_directed_text_vertices_graph_from_dot_test_markov_chain.dot"};
    save_text_vertices_graph_to_dot(g, dot_filetext);
    const auto h = load_directed_text_vertices_graph_from_dot(dot_filetext);
    save_text_vertices_graph_to_dot(h, dot_filetext);
    BOOST_CHECK(get_vertex_texts(g) == get_vertex_texts(h));
  }
  //Nasty
  {
    const auto g = create_nasty_directed_text_vertices_graph();
    const std::string dot_filetext{"create_nasty_directed_text_vertices_graph.dot"};
    save_text_vertices_graph_to_dot(g, dot_filetext);
    const auto h = load_directed_text_vertices_graph_from_dot(dot_filetext);
    save_text_vertices_graph_to_dot(h, dot_filetext);
    BOOST_CHECK(get_sorted_vertex_texts(g) == get_sorted_vertex_texts(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_directed_text_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filetext{
    "load_directed_text_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filetext));
  BOOST_CHECK_THROW(
    load_directed_text_vertices_graph_from_dot(dot_filetext),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
