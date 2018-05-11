#include "create_custom_and_selectable_edges_and_vertices_path_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include "get_my_custom_vertexes.h"

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_reject_one_edge)
{
  const std::vector<my_custom_vertex> vs =
  {
    my_custom_vertex("Y") //One too few
  };
  const std::vector<my_custom_edge> es =
  {
    my_custom_edge("1")
  };
  const std::vector<bool> ess = { false };
  const std::vector<bool> vss = { false };
  BOOST_CHECK_THROW(
    create_custom_and_selectable_edges_and_vertices_path_graph(es, ess, vs, vss),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_reject_less_edge_selectedness_than_edges)
{
  const std::vector<my_custom_vertex> vs =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const std::vector<my_custom_edge> es =
  {
    my_custom_edge("1")
  };
  const std::vector<bool> ess = {}; //One too few
  const std::vector<bool> vss = { false, true };
  BOOST_CHECK_THROW(
    create_custom_and_selectable_edges_and_vertices_path_graph(es, ess, vs, vss),
    std::invalid_argument
  );
}

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_reject_less_vertex_selectedness_than_vertices)
{
  const std::vector<my_custom_vertex> vs =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const std::vector<my_custom_edge> es =
  {
    my_custom_edge("1")
  };
  const std::vector<bool> ess = { true };
  const std::vector<bool> vss = { false }; //One too few
  BOOST_CHECK_THROW(
    create_custom_and_selectable_edges_and_vertices_path_graph(es, ess, vs, vss),
    std::invalid_argument
  );
}


BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_without_vertices)
{
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph( {}, {}, {}, {} );
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 0);
}

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_with_one_vertex)
{
  const std::vector<my_custom_vertex> my_custom_vertexes =
    {
      my_custom_vertex("X")
    };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    {}, {}, my_custom_vertexes, { true }
   );
  BOOST_CHECK(boost::num_edges(g) == 0);
  BOOST_CHECK(boost::num_vertices(g) == 1);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
}

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_with_one_edge)
{
  const std::vector<my_custom_vertex> my_custom_vertexes =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y")
  };
  const std::vector<my_custom_edge> my_custom_and_selectable_edges =
  {
    my_custom_edge("1")
  };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    my_custom_and_selectable_edges,
    { false },
    my_custom_vertexes,
    { false, true }
  );
  BOOST_CHECK(boost::num_edges(g) == 1);
  BOOST_CHECK(boost::num_vertices(g) == 2);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);

}

BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_with_two_edges)
{
  const std::vector<my_custom_vertex> my_custom_vertexes =
  {
    my_custom_vertex("X"),
    my_custom_vertex("Y"),
    my_custom_vertex("Z")
  };
  const std::vector<my_custom_edge> my_custom_and_selectable_edges =
  {
    my_custom_edge("1"),
    my_custom_edge("2")
  };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    my_custom_and_selectable_edges,
    { false, false },
    my_custom_vertexes,
    { false, true, false }
  );
  BOOST_CHECK(boost::num_edges(g) == 2);
  BOOST_CHECK(boost::num_vertices(g) == 3);
  BOOST_CHECK(get_my_custom_vertexes(g) == my_custom_vertexes);
}


#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(test_create_custom_and_selectable_edges_and_vertices_path_graph_create_pictures)
{
  //Create the .dot and .svg of the 'create_custom_and_selectable_edges_and_vertices_path_graph' chapter
  //for (const int n: {3,4, 5} )
  const std::vector<my_custom_vertex> my_custom_vertexes {
    my_custom_vertex("A"),
    my_custom_vertex("B"),
    my_custom_vertex("C"),
    my_custom_vertex("D")
  };
  const std::vector<my_custom_edge> my_custom_and_selectable_edges {
    my_custom_edge("1"),
    my_custom_edge("2"),
    my_custom_edge("3")
  };
  const auto g = create_custom_and_selectable_edges_and_vertices_path_graph(
    my_custom_and_selectable_edges,
    { false, false, false },
    my_custom_vertexes,
    { false, true, false, false }
  );
  const std::string base_filename{"create_custom_and_selectable_edges_and_vertices_path_graph_4"};
  const std::string dot_filename{base_filename + ".dot"};
  const std::string svg_filename{base_filename + ".svg"};
  save_graph_to_dot(g,dot_filename);
  BOOST_CHECK(is_regular_file(dot_filename));
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
#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
