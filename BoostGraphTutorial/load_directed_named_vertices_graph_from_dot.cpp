#include "load_directed_named_vertices_graph_from_dot.h"

#include "load_directed_named_vertices_graph_from_dot.impl"

#include "load_directed_named_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_named_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_named_vertices_graph_to_dot.h"
#include "helper.h"
#include "create_nasty_directed_named_vertices_graph.h"
#include "get_sorted_vertex_names.h"
void load_directed_named_vertices_graph_from_dot_test() noexcept
{
  //Basic
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string dot_filename{"load_directed_named_vertices_graph_from_dot_test_markov_chain.dot"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_named_vertices_graph_from_dot(dot_filename);
    save_named_vertices_graph_to_dot(h, dot_filename);
    assert(get_vertex_names(g) == get_vertex_names(h));
  }
  //Nasty
  {
    const auto g = create_nasty_directed_named_vertices_graph();
    const std::string dot_filename{"create_nasty_directed_named_vertices_graph.dot"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_named_vertices_graph_from_dot(dot_filename);
    save_named_vertices_graph_to_dot(h, dot_filename);
    assert(get_sorted_vertex_names(g) == get_sorted_vertex_names(h));
  }
  load_directed_named_vertices_graph_from_dot_demo();
  
}
