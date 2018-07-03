#include "create_text_edges_and_vertices_markov_chain.h"
#include "create_text_edges_and_vertices_markov_chain_demo.impl"

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_text_edges_and_vertices_graph.h"
#include "get_edge_texts.h"
#include "get_vertex_texts.h"
#include "save_text_edges_and_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_text_edges_and_vertices_markov_chain_thorough)
{
  // Basic functions
  {
    const auto g = create_text_edges_and_vertices_markov_chain();
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    const std::vector<std::string> expected_vertex_texts{ "Happy",
      "Not unhappy" };
    const std::vector<std::string> vertex_texts{ get_vertex_texts(g) };
    BOOST_CHECK(expected_vertex_texts == vertex_texts);
    const std::vector<std::string> expected_edge_texts{ "Fruit", "No chocolate",
      "Chocolate", "Other candy" };
    const std::vector<std::string> edge_texts{ get_edge_texts(g) };
    BOOST_CHECK(expected_edge_texts == edge_texts);
  }
  // Create the create_text_edges_and_vertices_markov_chain .dot and .svg files
  {
    const auto g = create_text_edges_and_vertices_markov_chain();
    const std::string base_filetext{
      "create_text_edges_and_vertices_markov_chain"
    };
    const std::string dot_filetext{ base_filetext + ".dot" };
    const std::string svg_filetext{ base_filetext + ".svg" };
    save_text_edges_and_vertices_graph_to_dot(g, dot_filetext);
    convert_dot_to_svg(dot_filetext, svg_filetext);
    copy_file(dot_filetext, "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filetext, "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filetext.c_str());
    std::remove(svg_filetext.c_str());
  }
}
