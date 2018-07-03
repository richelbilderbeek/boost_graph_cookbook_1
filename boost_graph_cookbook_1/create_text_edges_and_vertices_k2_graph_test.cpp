#include "create_text_edges_and_vertices_k2_graph.h"
#include "create_text_edges_and_vertices_k2_graph_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_text_edges_and_vertices_graph.h"
#include "get_edge_names.h"
#include "get_vertex_names.h"
#include "save_text_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

BOOST_AUTO_TEST_CASE(create_text_edges_and_vertices_k2_graph_thorough)
{
  //Basic functions
  {
    const auto g = create_text_edges_and_vertices_k2_graph();
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    const std::vector<std::string> expected_vertex_names{"x", "y"};
    const std::vector<std::string> vertex_names{get_vertex_names(g)};
    BOOST_CHECK(expected_vertex_names == vertex_names);
    const std::vector<std::string> expected_edge_names{"between"};
    const std::vector<std::string> edge_names{get_edge_names(g)};
    BOOST_CHECK(expected_edge_names == edge_names);
  }
  #ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
  //Create the create_text_edges_and_vertices_k2_graph .dot and .svg files
  {
    const auto g = create_text_edges_and_vertices_k2_graph();
    const std::string base_filename{"create_text_edges_and_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_text_edges_and_vertices_graph_to_dot(g,dot_filename);
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
  #endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
}
