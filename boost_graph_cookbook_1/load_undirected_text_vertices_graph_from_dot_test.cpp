#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_undirected_text_vertices_graph_from_dot.h"
#include "load_undirected_text_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_text_vertices_k2_graph.h"
#include "file_to_vector.h"
#include "is_regular_file.h"
#include "save_text_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(load_undirected_text_vertices_graph_from_dot_thorough)
{
  //Basic test
  {
    const auto g = create_text_vertices_k2_graph();
    const std::string base_filetext{"create_text_vertices_k2_graph.dot"};
    const std::string dot_filetext{base_filetext + ".dot"};
    save_text_vertices_graph_to_dot(g, dot_filetext);
    const auto h = load_undirected_text_vertices_graph_from_dot(dot_filetext);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_vertex_texts(g) == get_vertex_texts(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_text_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filetext{
    "load_undirected_text_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filetext));
  BOOST_CHECK_THROW(
    load_undirected_text_vertices_graph_from_dot(dot_filetext),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
