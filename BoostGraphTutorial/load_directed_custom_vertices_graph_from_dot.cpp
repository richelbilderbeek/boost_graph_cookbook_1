#include "load_directed_custom_vertices_graph_from_dot.h"

#include "load_directed_custom_vertices_graph_from_dot.impl"

#include "load_directed_custom_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "add_custom_vertex.h"
#include "create_empty_directed_custom_vertices_graph.h"
#include "create_nasty_directed_custom_vertices_graph.h"
#include "create_custom_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "helper.h"
#include "my_custom_vertex.h"
#include "install_vertex_custom_type.h"
#include "get_sorted_custom_vertex_my_vertexes.h"


void load_directed_custom_vertices_graph_from_dot_test() noexcept
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_custom_vertices_graph();
    const std::string filename{
      "load_directed_custom_vertices_graph_from_dot_test.dot"
    };
    save_custom_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_my_custom_vertexes(g) == get_my_custom_vertexes(h));
  }
  //Basic tests: graph with harder texts
  {
    auto g = create_nasty_directed_custom_vertices_graph();
    const std::string filename{
      "load_directed_custom_vertices_graph_from_dot_test.dot"
    };
    save_custom_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_sorted_custom_vertex_my_vertexes(g) == get_sorted_custom_vertex_my_vertexes(h));
  }
  load_directed_custom_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
