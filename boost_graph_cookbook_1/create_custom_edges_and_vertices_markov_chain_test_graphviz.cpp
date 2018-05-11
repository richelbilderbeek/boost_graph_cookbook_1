#include "create_custom_edges_and_vertices_markov_chain.h"

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"


#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_my_custom_vertexes.h"
#include "get_my_custom_edges.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_custom_edges_and_vertices_markov_chain.h"
#include "create_custom_edges_and_vertices_k3_graph.h"

#include "save_custom_edges_and_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_custom_edges_and_vertices_markov_chain_graphviz)
{
  //Create the .dot and .svg of the 'create_custom_edges_and_vertices_markov_chain' chapter
  const auto g = create_custom_edges_and_vertices_markov_chain();
  const std::string base_filename{"create_custom_edges_and_vertices_markov_chain"};
  const std::string dot_filename{base_filename + ".dot"};
  const std::string svg_filename{base_filename + ".svg"};
  save_custom_edges_and_vertices_graph_to_dot(g, dot_filename);
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
