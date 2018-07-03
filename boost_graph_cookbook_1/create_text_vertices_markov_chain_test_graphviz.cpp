#include "create_text_vertices_markov_chain.h"

#include "add_text_vertex.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_nasty_directed_text_vertices_graph.h"
#include "create_text_vertices_markov_chain.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_sorted_vertex_texts.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_texts.h"
#include "load_directed_text_vertices_graph_from_dot.h"
#include "save_text_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_text_vertices_markov_chain_save_and_load)
{
  // Nasty graph
  {
    auto g = create_nasty_directed_text_vertices_graph();
    const std::string filetext{
      "create_nasty_directed_text_vertices_graph_test.dot"
    };
    save_text_vertices_graph_to_dot(g, filetext);
    const auto h = load_directed_text_vertices_graph_from_dot(filetext);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_texts(g);
    const auto b = get_sorted_vertex_texts(h);
    BOOST_CHECK(a == b);
  }
  // Create the .dot and .svg of the 'create_text_vertices_markov_chain' chapter
  {
    const auto g = create_text_vertices_markov_chain();
    const std::string dot_filetext{ "create_text_vertices_markov_chain.dot" };
    const std::string svg_filetext{ "create_text_vertices_markov_chain.svg" };
    save_text_vertices_graph_to_dot(g, dot_filetext);
    convert_dot_to_svg(dot_filetext, svg_filetext);
    copy_file(dot_filetext, "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filetext, "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filetext.c_str());
    std::remove(svg_filetext.c_str());
  }
}
