#include "create_bundled_vertices_k2_graph.h"

#include "create_bundled_vertices_k2_graph.impl"

#include "create_bundled_vertices_k2_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "has_bundled_vertex_with_my_vertex.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include "load_directed_bundled_vertices_graph_from_dot.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

void create_bundled_vertices_k2_graph_test() noexcept
{
  {
    const auto g = create_bundled_vertices_k2_graph();
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(has_bundled_vertex_with_my_vertex(my_bundled_vertex("A", "source" ,0.0, 0.0), g));
    assert(has_bundled_vertex_with_my_vertex(my_bundled_vertex("B", "target" ,3.14, 3.14), g));
  }
  //Create the picture 'create_bundled_vertices_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_vertices_k2_graph();
    const std::string base_filename{"create_bundled_vertices_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_vertices_graph_to_dot(g, dot_filename);
    try
    {
      const auto h = load_directed_bundled_vertices_graph_from_dot(dot_filename);
      assert(boost::num_edges(g) == boost::num_edges(h));
      assert(boost::num_vertices(g) == boost::num_vertices(h));
      assert(get_sorted_bundled_vertex_my_vertexes(g)
        == get_sorted_bundled_vertex_my_vertexes(h));
      assert(!"Fixed #16");
      convert_dot_to_svg(dot_filename, svg_filename);
      copy_file(
        svg_filename,
        "../BoostGraphTutorial/" + svg_filename,
        copy_file_mode::allow_overwrite
      );
      copy_file(
        dot_filename,
        "../BoostGraphTutorial/" + dot_filename,
        copy_file_mode::allow_overwrite
      );
    }
    catch (std::exception&)
    {
      std::cout << __func__ << ": TODO" << '\n';
    }
  }
  create_bundled_vertices_k2_graph_demo();
  std::cout << __func__ << ": OK" << '\n';

}
