#include "create_custom_vertices_path_graph.h"
#include "create_custom_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "get_my_custom_vertexes.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_custom_vertices_path_graph_thorough)
{
  // Basic tests
  {
    const auto g = create_custom_vertices_path_graph({});
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 0);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes{ my_custom_vertex(
      "X") };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    BOOST_CHECK(boost::num_edges(g) == 0);
    BOOST_CHECK(boost::num_vertices(g) == 1);
    BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes{
      my_custom_vertex("X"), my_custom_vertex("Y")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes{
      my_custom_vertex("X"), my_custom_vertex("Y"), my_custom_vertex("Z")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    BOOST_CHECK(boost::num_edges(g) == 2);
    BOOST_CHECK(boost::num_vertices(g) == 3);
    BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
  // Create the .dot and .svg of the 'create_custom_vertices_path_graph' chapter
  // for (const int n: {3,4, 5} )
  {
    const std::vector<my_custom_vertex> my_custom_vertexes{ my_custom_vertex(
                                                              "A"),
      my_custom_vertex("B"), my_custom_vertex("C"), my_custom_vertex("D") };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    const std::string base_filename{ "create_custom_vertices_path_graph_4" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
}
