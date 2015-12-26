#include "create_bundled_vertices_markov_chain.h"

#include "create_bundled_vertices_markov_chain.impl"

#include "create_bundled_vertices_markov_chain_demo.impl"

#include <cassert>
#include <iostream>
#include "convert_dot_to_svg.h"
#include "copy_file.h"


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_bundled_vertices_markov_chain.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include "load_directed_bundled_vertices_graph_from_dot.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"

void create_bundled_vertices_markov_chain_test() noexcept
{
  //Basic tests
  {
    const auto g = create_bundled_vertices_markov_chain();
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
    const std::vector<my_bundled_vertex> vertex_my_vertexes{
      get_bundled_vertex_my_vertexes(g)
    };
    const std::vector<my_bundled_vertex> expected_my_vertexes{
      my_bundled_vertex("Sunny","Yellow thing",1.0,2.0),
      my_bundled_vertex("Rainy","Grey things",3.0,4.0)
    };
    assert(expected_my_vertexes == vertex_my_vertexes);
  }
  //Create the picture 'create_bundled_vertices_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_vertices_markov_chain();
    const std::string base_filename{"create_bundled_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_bundled_vertices_graph_from_dot(dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_sorted_bundled_vertex_my_vertexes(g)
      == get_sorted_bundled_vertex_my_vertexes(h));
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
  create_bundled_vertices_markov_chain_demo();
  std::cout << __func__ << ": OK" << '\n';
}
