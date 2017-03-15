#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "file_to_vector.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "get_my_custom_vertexes.h"
#include "get_vertex_selectednesses.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"
#include "load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot.h"
#include "create_custom_and_selectable_edges_and_vertices_markov_chain.h"
#include "load_directed_custom_edges_and_vertices_graph_from_dot.h"

BOOST_AUTO_TEST_CASE(create_custom_and_selectable_edges_and_vertices_markov_chain_thorough_graphviz)
{
  //Create the .dot and .svg of the 'create_custom_and_selectable_edges_and_vertices_markov_chain' chapter
  const auto g = create_custom_and_selectable_edges_and_vertices_markov_chain();
  const std::string base_filename{"create_custom_and_selectable_edges_and_vertices_markov_chain"};
  const std::string dot_filename{base_filename + ".dot"};
  const std::string svg_filename{base_filename + ".svg"};
  save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, dot_filename);
  const auto h = load_directed_custom_and_selectable_edges_and_vertices_graph_from_dot(dot_filename);
  BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
  BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  BOOST_CHECK(get_my_custom_vertexes(g) ==  get_my_custom_vertexes(h));
  BOOST_CHECK(get_vertex_selectednesses(g) == get_vertex_selectednesses(h));
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
  std::remove(dot_filename.c_str());
  std::remove(svg_filename.c_str());
}
