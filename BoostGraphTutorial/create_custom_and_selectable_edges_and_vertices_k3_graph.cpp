#include "create_custom_and_selectable_edges_and_vertices_k3_graph.h"

#include "create_custom_and_selectable_edges_and_vertices_k3_graph.impl"

#include "create_custom_and_selectable_edges_and_vertices_k3_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "has_custom_vertex_with_my_vertex.h"
#include "has_custom_edge_with_my_edge.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

void create_custom_and_selectable_edges_and_vertices_k3_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_and_selectable_edges_and_vertices_k3_graph();
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    const my_custom_vertex va("Karen","red",1.1,2.2);
    const my_custom_vertex vb("Kristel","black",3.3,4.4);
    const my_custom_vertex vc("Kathleen","blond",5.5,6.6);
    const my_custom_edge ea("1");
    const my_custom_edge eb("2");
    const my_custom_edge ec("3");
    assert(has_custom_vertex_with_my_custom_vertex(va, g));
    assert(has_custom_vertex_with_my_custom_vertex(vb, g));
    assert(has_custom_vertex_with_my_custom_vertex(vc, g));
    assert(has_custom_edge_with_my_edge(ea, g));
    assert(has_custom_edge_with_my_edge(eb, g));
    assert(has_custom_edge_with_my_edge(ec, g));
  }
  //Create the .dot and .svg of the 'create_custom_and_selectable_edges_and_vertices_k3_graph' chapter
  {
    const auto g = create_custom_and_selectable_edges_and_vertices_k3_graph();
    const std::string base_filename{"create_custom_and_selectable_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_and_selectable_edges_and_vertices_graph_to_dot(g, dot_filename);
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
  create_custom_and_selectable_edges_and_vertices_k3_graph_demo();
  

}
