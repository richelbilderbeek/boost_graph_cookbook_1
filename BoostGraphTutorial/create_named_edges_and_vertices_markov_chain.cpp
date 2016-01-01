#include "create_named_edges_and_vertices_markov_chain.h"

#include "create_named_edges_and_vertices_markov_chain.impl"

#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "create_named_edges_and_vertices_markov_chain_demo.impl"
#include <cassert>
#include <iostream>
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

void create_named_edges_and_vertices_markov_chain_test() noexcept
{
  //Basic functions
  {
    const auto g = create_named_edges_and_vertices_markov_chain();
    assert(boost::num_edges(g) == 4);
    assert(boost::num_vertices(g) == 2);
    const std::vector<std::string> expected_vertex_names{"Happy","Not unhappy"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    assert(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{
      "Fruit","No chocolate","Chocolate","Other candy"
    };
    const std::vector<std::string> edge_names{get_edge_names(g)};
    assert(expected_edge_names == edge_names);
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
  }
  create_named_edges_and_vertices_markov_chain_demo();
  
}
