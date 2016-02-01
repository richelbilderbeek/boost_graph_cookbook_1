#include "create_named_vertices_k3_graph.h"

#include "create_named_vertices_k3_graph.impl"

#include "create_named_vertices_k3_graph_demo.impl"

#include <cassert>
#include <iostream>


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_named_vertices_k3_graph.h"
#include "create_k3_graph.h"
#include "save_named_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "load_undirected_named_vertices_graph_from_dot.h"

void create_named_vertices_k3_graph_test() noexcept
{
  { //Basic tests
    const auto g = create_named_vertices_k3_graph();
    const auto vip = get_vertex_iterators(g);
    assert(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 3);
    const auto eip = get_edge_iterators(g);
    assert(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 3);

    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    const std::vector<std::string> expected_names{"Karen", "Kristel","Kathleen"};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    assert(expected_names == vertex_names);
  }
  //Create the .dot and .svg of the 'create_named_vertices_markov_chain' chapter
  {
    const auto g = create_named_vertices_k3_graph();
    const std::string base_filename{"create_named_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_undirected_named_vertices_graph_from_dot(dot_filename);
    assert(get_vertex_names(g) == get_vertex_names(h)); //Maybe sort first?


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
  create_named_vertices_k3_graph_demo();
}

