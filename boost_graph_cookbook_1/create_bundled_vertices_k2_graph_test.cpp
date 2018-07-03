#include "create_bundled_vertices_k2_graph.h"
#include "create_bundled_vertices_k2_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"
#include "has_bundled_vertex_with_my_vertex.h"
#include "load_undirected_bundled_vertices_graph_from_dot.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(create_bundled_vertices_k2_graph_thorough)
{
  {
    const auto g = create_bundled_vertices_k2_graph();
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(has_bundled_vertex_with_my_vertex(
      my_bundled_vertex("Me", "Myself", 1.0, 2.0), g));
    BOOST_CHECK(has_bundled_vertex_with_my_vertex(
      my_bundled_vertex("My computer", "Not me", 3.0, 4.0), g));
  }
#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
  // Create the picture 'create_bundled_vertices_markov_chain.svg'
  // Create graphs, save it to dot
  // Create another graph by loading it, then save it to .dot, convert that .dot
  // to .svg
  {
    const auto g = create_bundled_vertices_k2_graph();
    const std::string base_filename{ "create_bundled_vertices_k2_graph" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_bundled_vertices_graph_to_dot(g, dot_filename);
    const auto h
      = load_undirected_bundled_vertices_graph_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto v = get_sorted_bundled_vertex_my_vertexes(g);
    const auto w = get_sorted_bundled_vertex_my_vertexes(h);
    BOOST_CHECK(v.size() == w.size());
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
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
}
