#include "create_bundled_vertices_markov_chain.h"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include <boost/test/unit_test.hpp>

#include "create_bundled_vertices_markov_chain.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_names.h"
#include "load_directed_bundled_vertices_graph_from_dot.h"
#include "save_bundled_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_bundled_vertices_markov_chain_graphviz)
{
  // Create the picture 'create_bundled_vertices_markov_chain.svg'
  // Create graphs, save it to dot
  // Create another graph by loading it, then save it to .dot, convert that .dot
  // to .svg
  {
    const auto g = create_bundled_vertices_markov_chain();
    const std::string base_filename{ "create_bundled_vertices_markov_chain" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_bundled_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_bundled_vertices_graph_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_sorted_bundled_vertex_my_vertexes(g)
      == get_sorted_bundled_vertex_my_vertexes(h));
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
