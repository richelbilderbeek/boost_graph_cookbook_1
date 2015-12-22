#include "load_directed_bundled_vertices_graph_from_dot.h"

#include "load_directed_bundled_vertices_graph_from_dot.impl"

#include "load_directed_bundled_vertices_graph_from_dot_demo.impl"

#include "copy_file.h"
#include <iostream>

#include "create_bundled_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include "helper.h"
#include "my_bundled_vertex.h"


void load_directed_bundled_vertices_graph_from_dot_test() noexcept
{
  //Basic tests
  {
    //First get the demo working
  }
  //Create the picture 'load_directed_bundled_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_vertices_markov_chain();
    const std::string base_filename{"create_bundled_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = helper().file_to_vector(dot_filename);
    const auto h = load_directed_bundled_vertices_graph_from_dot(dot_filename);
    save_bundled_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = helper().file_to_vector(dot_filename);\
    if (old_text == new_text)
    {
      assert(old_text == new_text);
      convert_dot_to_svg(dot_filename, svg_filename);
      assert(boost::num_edges(g) == boost::num_edges(h));
      assert(boost::num_vertices(g) == boost::num_vertices(h));
      copy_file(
        svg_filename,
        "../BoostGraphTutorial/" + svg_filename,
        copy_file_mode::allow_overwrite
      );
      assert(!"Green");
    }
    else
    {
      std::cout << __func__ << ": TODO" << '\n';
    }
  }
  load_directed_bundled_vertices_graph_from_dot_demo();
  std::cout << __func__ << ": OK" << '\n';
}
