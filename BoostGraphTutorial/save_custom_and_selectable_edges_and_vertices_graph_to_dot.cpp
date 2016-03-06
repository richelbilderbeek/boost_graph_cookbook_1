#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"

#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot_demo.impl"

#include <cassert>
#include <iostream>
#include <sstream>
#include "copy_file.h"
#include "create_custom_and_selectable_edges_and_vertices_k2_graph.h"
#include "show_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"
#include "helper.h"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "get_sorted_vertex_selectednesses.h"

void save_custom_and_selectable_edges_and_vertices_graph_to_dot_test() noexcept
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "save_custom_and_selectable_edges_and_vertices_graph_to_dot.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    assert(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
  }
  //Basic tests: graph with harder texts
  {
    auto g = create_nasty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "save_custom_and_selectable_edges_and_vertices_graph_to_dot.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    assert(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
    assert(get_sorted_vertex_selectednesses(g) == get_sorted_vertex_selectednesses(h));
  }
  save_custom_and_selectable_edges_and_vertices_graph_to_dot_demo();
}
