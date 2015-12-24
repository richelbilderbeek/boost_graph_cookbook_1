#include "create_named_vertices_k2_graph.h"

#include "create_named_vertices_k2_graph.impl"

#include "create_named_vertices_k2_graph_demo.impl"

#include <cassert>
#include <iostream>


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_named_vertices_k2_graph.h"
#include "create_k2_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

void create_named_vertices_k2_graph_test() noexcept
{
  { //Basic tests
    const auto g = create_named_vertices_k2_graph();
    const auto vip = get_vertex_iterators(g);
    assert(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    assert(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 1);

    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    const std::vector<std::string> expected_names{"A", "B"};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    assert(expected_names == vertex_names);
  }
  //Create the .dot and .svg of the 'create_named_vertices_markov_chain' chapter
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"create_named_vertices_k2_graph.dot"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  //Copy from named-vertices graph to graph without properties
  //CANNOT
  //{
  //  const auto h = create_named_vertices_k2_graph();
  //  auto g = create_k2_graph();
  //  g = h; //Lose information, is that possible?
  //}
  create_named_vertices_k2_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}

