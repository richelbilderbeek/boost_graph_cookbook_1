#include "load_undirected_graph_from_dot.h"

#include "load_undirected_graph_from_dot.impl"

#include "load_undirected_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>
#include "convert_dot_to_svg.h"

void load_undirected_graph_from_dot_test() noexcept
{
  //Create the picture 'load_undirected_graph_from_dot_test_k2.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_k2_graph();
    const std::string dot_filename{"load_undirected_graph_from_dot_test_k2.dot"};
    const std::string svg_filename{"load_undirected_graph_from_dot_test_k2.svg"};
    save_graph_to_dot(g, dot_filename);
    const auto h = load_undirected_graph_from_dot(dot_filename);
    save_graph_to_dot(h, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  load_undirected_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
