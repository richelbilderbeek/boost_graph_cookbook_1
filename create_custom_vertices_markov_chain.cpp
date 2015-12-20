#include "create_custom_vertices_markov_chain.h"

#include "create_custom_vertices_markov_chain.impl"

#include "create_custom_vertices_markov_chain_demo.impl"

#include <cassert>
#include <iostream>
#include "convert_dot_to_svg.h"
#include "copy_file.h"


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_custom_vertices_markov_chain.h"
#include "create_custom_vertices_k2_graph.h"

#include "save_custom_vertices_graph_to_dot.h"

void create_custom_vertices_markov_chain_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_vertices_markov_chain();
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 4);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 4);
    const auto vip = get_vertex_iterators(g);
    assert(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    assert(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 4);
    const std::vector<my_vertex> vertex_my_vertexes{
      get_vertex_my_vertexes(g)
    };
    const std::vector<my_vertex> expected_my_vertexes{
      my_vertex("Sunny","You can see the yellow thing",1.0,2.0),
      my_vertex("Rainy","Many grey fluffy things",3.0,4.0)
    };
    assert(expected_my_vertexes == vertex_my_vertexes);
  }
  //Create the .dot and .svg of the 'create_custom_vertices_markov_chain' chapter
  {
    const auto g = create_custom_vertices_markov_chain();
    const std::string dot_filename{"create_custom_vertices_markov_chain.dot"};
    const std::string svg_filename{"create_custom_vertices_markov_chain.svg"};
    save_custom_vertices_graph_to_dot(g, dot_filename);
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
  //Create the .dot and .svg of the 'create_custom_vertices_k2_graph' chapter
  {
    const auto g = create_custom_vertices_k2_graph();
    const std::string dot_filename{"create_custom_vertices_k2_graph.dot"};
    const std::string svg_filename{"create_custom_vertices_k2_graph.svg"};
    save_custom_vertices_graph_to_dot(g, dot_filename);
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
  create_custom_vertices_markov_chain_demo();
  std::cout << __func__ << ": OK" << '\n';
}
