#include "create_nasty_directed_custom_and_selectable_vertices_graph.h"

#include "create_custom_and_selectable_vertices_markov_chain.impl"

#include "create_custom_and_selectable_vertices_markov_chain_demo.impl"

#include <cassert>
#include <iostream>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "helper.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "get_my_custom_vertexes.h"
#include "create_custom_and_selectable_vertices_markov_chain.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "load_directed_custom_and_selectable_vertices_graph_from_dot.h"
#include "create_custom_and_selectable_vertices_markov_chain.h"
#include "load_directed_custom_vertices_graph_from_dot.h"

void create_custom_and_selectable_vertices_markov_chain_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_and_selectable_vertices_markov_chain();
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
    //Can get the my_custom_vertex objects
    const std::vector<my_custom_vertex> vertex_my_custom_vertexes{
      get_my_custom_vertexes(g)
    };
    const std::vector<my_custom_vertex> expected_my_custom_vertexes{
      my_custom_vertex("Sunny","Yellow thing",1.0,2.0),
      my_custom_vertex("Rainy","Grey things",3.0,4.0)
    };
    assert(expected_my_custom_vertexes == vertex_my_custom_vertexes);
    //Can get the selectednesses
    const std::vector<bool> expected_selectednesses{
      true, false
    };
    const std::vector<bool> vertex_selectednesses{
      get_vertex_selectednesses(g)
    };
    assert(expected_selectednesses == vertex_selectednesses);

  }
  //Create the .dot and .svg of the 'create_custom_and_selectable_vertices_markov_chain' chapter
  {
    const auto g = create_custom_and_selectable_vertices_markov_chain();
    const std::string base_filename{"create_custom_and_selectable_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_and_selectable_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_custom_and_selectable_vertices_graph_from_dot(dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_my_custom_vertexes(g) ==  get_my_custom_vertexes(h));
    assert(get_vertex_selectednesses(g) == get_vertex_selectednesses(h));
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
  create_custom_and_selectable_vertices_markov_chain_demo();
  std::cout << __func__ << ": OK" << '\n';
}
