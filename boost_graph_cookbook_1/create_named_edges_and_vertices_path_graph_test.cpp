#include "create_named_edges_and_vertices_path_graph.h"
#include "create_named_edges_and_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "load_undirected_named_edges_and_vertices_graph_from_dot.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "get_vertex_names.h"

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_empty_graph)
{
  const auto g = create_named_edges_and_vertices_path_graph( {}, {} );
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
}

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_one_vertex)
{
  const std::vector<std::string> vertex_names = {"X"};
  const std::vector<std::string> edge_names = {};
  const auto g = create_named_edges_and_vertices_path_graph(edge_names, vertex_names);
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(get_edge_names(g) == edge_names);
  BOOST_CHECK(get_vertex_names(g) == vertex_names);
}

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_one_edge)
{
  const std::vector<std::string> vertex_names = {"X", "Y"};
  const std::vector<std::string> edge_names = { "1" };
  const auto g = create_named_edges_and_vertices_path_graph(edge_names, vertex_names);
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(get_edge_names(g) == edge_names);
  BOOST_CHECK(get_vertex_names(g) == vertex_names);
}

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_one_vertex_too_few)
{
  const std::vector<std::string> vertex_names = {"X"}; //Too few
  const std::vector<std::string> edge_names = { "1" };
  BOOST_CHECK_THROW(
    create_named_edges_and_vertices_path_graph(edge_names, vertex_names),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_two_edges)
{
  const std::vector<std::string> vertex_names = {"X", "Y", "Z"};
  const std::vector<std::string> edge_names = { "1", "2" };
  const auto g = create_named_edges_and_vertices_path_graph(edge_names, vertex_names);
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  BOOST_CHECK(get_edge_names(g) == edge_names);
  BOOST_CHECK(get_vertex_names(g) == vertex_names);
}

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(create_named_edges_and_vertices_path_graph_create_pictures)
{
//Create the .dot and .svg of the 'create_named_edges_and_vertices_path_graph' chapter
//for (const int n: {3,4, 5} )
  const std::vector<std::string> vertex_names = {"A", "B", "C", "D"};
  const std::vector<std::string> edge_names = { "1", "2", "3" };
  const auto g = create_named_edges_and_vertices_path_graph(edge_names, vertex_names);
  const std::string base_filename{"create_named_edges_and_vertices_path_graph_4"};
  const std::string dot_filename{base_filename + ".dot"};
  const std::string svg_filename{base_filename + ".svg"};
  save_named_edges_and_vertices_graph_to_dot(g,dot_filename);
  BOOST_CHECK(is_regular_file(dot_filename));
  const auto h = load_undirected_named_edges_and_vertices_graph_from_dot(dot_filename);
  BOOST_CHECK(get_vertex_names(g) == get_vertex_names(h)); //Maybe sort first?

  convert_dot_to_svg(dot_filename,svg_filename);
  BOOST_CHECK(is_regular_file(svg_filename));
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
