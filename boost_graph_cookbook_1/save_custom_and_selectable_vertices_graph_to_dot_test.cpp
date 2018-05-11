#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "save_custom_and_selectable_vertices_graph_to_dot_demo.impl"

#include <sstream>
#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_custom_vertices_k2_graph.h"
#include "create_custom_and_selectable_vertices_k2_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "file_to_vector.h"
#include "load_directed_custom_and_selectable_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "create_nasty_directed_custom_and_selectable_vertices_graph.h"
#include "get_sorted_vertex_selectednesses.h"

BOOST_AUTO_TEST_CASE(save_custom_and_selectable_vertices_graph_to_dot_thorough)
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_and_selectable_vertices_graph();
    const std::string filename{
      "save_custom_and_selectable_vertices_graph_to_dot.dot"
    };
    save_custom_and_selectable_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
  }
  //Basic tests: graph with harder texts
  {
    auto g = create_nasty_directed_custom_and_selectable_vertices_graph();
    const std::string filename{
      "save_custom_and_selectable_vertices_graph_to_dot.dot"
    };
    save_custom_and_selectable_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_vertices_graph_from_dot(filename);
    BOOST_CHECK(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
    BOOST_CHECK(get_sorted_vertex_selectednesses(g) == get_sorted_vertex_selectednesses(h));
  }
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
