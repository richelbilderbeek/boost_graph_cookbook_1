#include "create_custom_vertices_markov_chain.h"
#include "create_custom_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include <boost/test/unit_test.hpp>

#include "create_custom_vertices_k2_graph.h"
#include "create_custom_vertices_markov_chain.h"
#include "get_edge_descriptors.h"
#include "get_edge_iterators.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_iterators.h"
#include "get_vertex_names.h"

#include "save_custom_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_custom_vertices_markov_chain_thorough)
{
  // Basic tests
  {
    const auto g = create_custom_vertices_markov_chain();
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 4);
    const auto vip = get_vertex_iterators(g);
    BOOST_CHECK(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    BOOST_CHECK(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    BOOST_CHECK(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 4);
    const std::vector<my_custom_vertex> vertex_my_custom_vertexes{
      get_my_custom_vertexes(g)
    };
    const std::vector<my_custom_vertex> expected_my_custom_vertexes{
      my_custom_vertex("Sunny", "Yellow thing", 1.0, 2.0),
      my_custom_vertex("Rainy", "Grey things", 3.0, 4.0)
    };
    BOOST_CHECK(expected_my_custom_vertexes == vertex_my_custom_vertexes);
  }
  // Create the .dot and .svg of the 'create_custom_vertices_markov_chain'
  // chapter
  {
    const auto g = create_custom_vertices_markov_chain();
    const std::string base_filename{ "create_custom_vertices_markov_chain" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_custom_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
