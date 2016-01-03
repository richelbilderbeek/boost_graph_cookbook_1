#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.h"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.impl"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_demo.impl"

#include <iostream>

#include "add_custom_and_selectable_vertex.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
//#include "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_nasty_directed_custom_edges_and_vertices_graph.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "get_sorted_vertex_selectednesses.h"
#include "helper.h"
#include "install_vertex_custom_type.h"
#include "my_custom_vertex.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"


void load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_test() noexcept
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    assert(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
  }
  //Basic tests: graph with harder texts
  /* TODO
  {
    auto g = create_nasty_directed_custom_and_selectable_edges_and_vertices_graph();
    const std::string filename{
      "create_nasty_directed_custom_and_selectable_edges_and_vertices_graph.dot"
    };
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(filename);
    assert(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
    assert(get_sorted_vertex_selectednesses(g) == get_sorted_vertex_selectednesses(h)
    );
  }
  */
  load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot_demo();
  
}
