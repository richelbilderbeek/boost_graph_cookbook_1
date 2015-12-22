#include "load_directed_custom_vertices_graph_from_dot.h"

#include "load_directed_custom_vertices_graph_from_dot.impl"

#include "load_directed_custom_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_custom_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "helper.h"
#include "add_custom_vertex.h"
#include "my_vertex.h"
#include "install_vertex_custom_type.h"


void load_directed_custom_vertices_graph_from_dot_test() noexcept
{
  //Do some basic tests
  {
    const auto g
      = create_custom_vertices_markov_chain();
    const std::string filename{
      "load_directed_custom_vertices_graph_from_dot_test.dot"
    };
    save_custom_vertices_graph_to_dot(g, filename);
    const auto h
      = load_directed_custom_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_custom_vertex_my_vertexes(g) == get_custom_vertex_my_vertexes(h));
    assert(get_custom_vertex_my_vertexes(g) == get_custom_vertex_my_vertexes(h));
  }
  //File I/O: vertices with spaces should also work
  {
    auto g  = create_empty_directed_custom_vertices_graph();
    add_custom_vertex(my_custom_vertex("A B","C D",1.0,2.0));
    add_custom_vertex(my_custom_vertex("E_F","G_H",3.0,4.0));
    const std::string filename{
      "load_directed_custom_vertices_graph_from_dot_test.dot"
    };
    save_custom_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_custom_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_custom_vertex_my_vertexes(g) == get_custom_vertex_my_vertexes(h));
  }
  assert(1==2);
  //Create the picture 'load_directed_custom_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_custom_vertices_markov_chain();
    const std::string base_filename{"create_custom_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = helper().file_to_vector(dot_filename);
    const auto h = load_directed_custom_vertices_graph_from_dot(dot_filename);
    save_custom_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = helper().file_to_vector(dot_filename);
    assert(old_text == new_text);
    convert_dot_to_svg(dot_filename, svg_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  load_directed_custom_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
