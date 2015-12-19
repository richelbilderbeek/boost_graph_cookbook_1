#include "create_k2_graph_with_graph_name.h"

#include "create_k2_graph_with_graph_name.impl"

#include "create_k2_graph_with_graph_name_demo.impl"

#include <cassert>
#include <iostream>
#include "copy_file.h"


#include "get_edges.h"
#include "get_vertices.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"

void create_k2_graph_with_graph_name_test() noexcept
{
  //Basic tests
  {
    const auto g = create_k2_graph_with_graph_name();
    const auto vip = get_vertices(g);
    assert(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    assert(vds.size() == 2);
    const auto eip = get_edges(g);
    assert(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    assert(eds.size() == 1);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(get_graph_name(g) == "K2");
  }
  //Create the .dot and .svg of the 'create_k2_graph_with_graph_name' chapter
  {

    const auto g = create_k2_graph_with_graph_name();
    const std::string base_filename{"create_k2_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_with_graph_name_to_dot(g,dot_filename);
    assert(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    assert(is_regular_file(svg_filename));
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
  create_k2_graph_with_graph_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
