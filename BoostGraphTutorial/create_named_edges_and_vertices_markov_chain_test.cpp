#include "create_named_edges_and_vertices_markov_chain.h"
#include "create_named_edges_and_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_markov_chain_thorough)
{
  //Basic functions
  {
    const auto g = create_named_edges_and_vertices_markov_chain();
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    const std::vector<std::string> expected_vertex_names{"Happy","Not unhappy"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    BOOST_CHECK(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{
      "Fruit","No chocolate","Chocolate","Other candy"
    };
    const std::vector<std::string> edge_names{get_edge_names(g)};
    BOOST_CHECK(expected_edge_names == edge_names);
  }
  //Create the create_named_edges_and_vertices_markov_chain .dot and .svg files
  {
    const auto g = create_named_edges_and_vertices_markov_chain();
    const std::string base_filename{"create_named_edges_and_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
