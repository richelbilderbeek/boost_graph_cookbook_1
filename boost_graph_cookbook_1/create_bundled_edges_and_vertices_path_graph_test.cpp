#include "create_bundled_edges_and_vertices_path_graph.h"
#include "create_bundled_edges_and_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "get_my_bundled_vertexes.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(
  create_bundled_edges_and_vertices_path_graph_with_one_vertex_too_few)
{
  const std::vector<my_bundled_vertex> my_bundled_vertexes{
    my_bundled_vertex("Y") // Too few
  };
  const std::vector<my_bundled_edge> my_bundled_edges{ my_bundled_edge("1") };
  BOOST_CHECK_THROW(create_bundled_edges_and_vertices_path_graph(
                      my_bundled_edges, my_bundled_vertexes),
    std::invalid_argument);
}

BOOST_AUTO_TEST_CASE(create_bundled_edges_and_vertices_path_graph_empty_graph)
{
  const auto g = create_bundled_edges_and_vertices_path_graph({}, {});
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
}

BOOST_AUTO_TEST_CASE(create_bundled_edges_and_vertices_path_graph_one_vertex)
{
  const std::vector<my_bundled_vertex> my_bundled_vertexes{ my_bundled_vertex(
    "X") };
  const auto g
    = create_bundled_edges_and_vertices_path_graph({}, my_bundled_vertexes);
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(get_my_bundled_vertexes(g) == my_bundled_vertexes);
}

BOOST_AUTO_TEST_CASE(create_bundled_edges_and_vertices_path_graph_one_edge)
{
  const std::vector<my_bundled_vertex> my_bundled_vertexes{
    my_bundled_vertex("X"), my_bundled_vertex("Y")
  };
  const std::vector<my_bundled_edge> my_bundled_edges{ my_bundled_edge("1") };
  const auto g = create_bundled_edges_and_vertices_path_graph(
    my_bundled_edges, my_bundled_vertexes);
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(get_my_bundled_vertexes(g) == my_bundled_vertexes);
}

BOOST_AUTO_TEST_CASE(create_bundled_edges_and_vertices_path_graph_two_edges)
{
  const std::vector<my_bundled_vertex> my_bundled_vertexes{
    my_bundled_vertex("X"), my_bundled_vertex("Y"), my_bundled_vertex("Z")
  };
  const std::vector<my_bundled_edge> my_bundled_edges{ my_bundled_edge("1"),
    my_bundled_edge("2") };
  const auto g = create_bundled_edges_and_vertices_path_graph(
    my_bundled_edges, my_bundled_vertexes);
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  BOOST_CHECK(get_my_bundled_vertexes(g) == my_bundled_vertexes);
}

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(
  create_bundled_edges_and_vertices_path_graph_create_pictures)
{
  // Create the .dot and .svg of the
  // 'create_bundled_edges_and_vertices_path_graph' chapter for (const int n:
  // {3,4, 5} )
  const std::vector<my_bundled_vertex> my_bundled_vertexes{ my_bundled_vertex(
                                                              "A"),
    my_bundled_vertex("B"), my_bundled_vertex("C"), my_bundled_vertex("D") };
  const std::vector<my_bundled_edge> my_bundled_edges{ my_bundled_edge("1"),
    my_bundled_edge("2"), my_bundled_edge("3") };
  const auto g = create_bundled_edges_and_vertices_path_graph(
    my_bundled_edges, my_bundled_vertexes);
  const std::string base_filename{
    "create_bundled_edges_and_vertices_path_graph_4"
  };
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
