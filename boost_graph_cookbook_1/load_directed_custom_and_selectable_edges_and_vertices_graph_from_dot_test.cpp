#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.h"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_custom_and_selectable_vertex.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_nasty_directed_custom_edges_and_vertices_graph.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "get_sorted_vertex_selectednesses.h"
#include "file_to_vector.h"
#include "install_vertex_custom_type.h"
#include "is_regular_file.h"
#include "my_custom_vertex.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"


BOOST_AUTO_TEST_CASE(load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_thorough)
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
  }
  //Basic tests: graph with harder texts
  {
    auto g = create_nasty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
    BOOST_CHECK(get_sorted_vertex_selectednesses(g) == get_sorted_vertex_selectednesses(h)
    );
  }
}

BOOST_AUTO_TEST_CASE(load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
