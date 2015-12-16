#include "load_undirected_named_vertices_graph_from_dot.h"

#include "load_undirected_named_vertices_graph_from_dot.impl"

#include "load_undirected_named_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_named_vertices_k2_graph.h"
#include "convert_dot_to_svg.h"
#include "save_named_vertices_graph_to_dot.h"
#include "fileio.h"

void load_undirected_named_vertices_graph_from_dot_test() noexcept
{
  //Create the picture 'load_undirected_named_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string dot_filename{"load_undirected_named_vertices_graph_from_dot_test_markov_chain.dot"};
    const std::string svg_filename{"load_undirected_named_vertices_graph_from_dot_test_markov_chain.svg"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = ribi::FileIo().FileToVector(dot_filename);
    const auto h = load_undirected_named_vertices_graph_from_dot(dot_filename);
    save_named_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = ribi::FileIo().FileToVector(dot_filename);
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
  load_undirected_named_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
