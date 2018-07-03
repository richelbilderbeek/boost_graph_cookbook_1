#include "create_named_vertices_markov_chain.h"

#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_named_vertices_markov_chain.h"
#include "create_nasty_directed_named_vertices_graph.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_sorted_named_vertex_my_vertexes.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_names.h"
#include "load_directed_named_vertices_graph_from_dot.h"
#include "save_named_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_named_vertices_markov_chain_save_and_load)
{
  // Nasty graph
  {
    auto g = create_nasty_directed_named_vertices_graph();
    const std::string filename{
      "create_nasty_directed_named_vertices_graph_test.dot"
    };
    save_named_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_named_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_names(g);
    const auto b = get_sorted_vertex_names(h);
    BOOST_CHECK(a == b);
  }
  // Create the .dot and .svg of the 'create_named_vertices_markov_chain'
  // chapter
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string dot_filename{ "create_named_vertices_markov_chain.dot" };
    const std::string svg_filename{ "create_named_vertices_markov_chain.svg" };
    save_named_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
