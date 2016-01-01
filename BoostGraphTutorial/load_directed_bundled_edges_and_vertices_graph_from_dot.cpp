#include "load_directed_bundled_edges_and_vertices_graph_from_dot.h"

#include "load_directed_bundled_edges_and_vertices_graph_from_dot.impl"

#include "load_directed_bundled_edges_and_vertices_graph_from_dot_demo.impl"

#include <iostream>
#include <set>
#include "add_bundled_edge.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_bundled_edges_and_vertices_markov_chain.h"
#include "create_nasty_directed_bundled_edges_and_vertices_graph.h"
#include "get_sorted_bundled_edge_my_edges.h"
#include "helper.h"
#include "my_bundled_vertex.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"

void load_directed_bundled_edges_and_vertices_graph_from_dot_test() noexcept
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_bundled_edges_and_vertices_graph();
    const std::string filename{
      "load_directed_bundled_edges_and_vertices_graph_from_dot_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_my_bundled_edges(g) == get_my_bundled_edges(h));
  }
  //Basic tests: nasty graph
  {
    //See 'create_nasty_directed_bundled_edges_and_vertices_graph'
  }
  //Create the picture 'load_directed_bundled_edges_and_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_edges_and_vertices_markov_chain();
    const std::string base_filename{"create_bundled_edges_and_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_my_bundled_vertexes(g) == get_my_bundled_vertexes(h));
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
  load_directed_bundled_edges_and_vertices_graph_from_dot_demo();
  
}
