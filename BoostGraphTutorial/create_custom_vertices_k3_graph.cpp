#include "create_custom_vertices_k3_graph.h"

#include "create_custom_vertices_k3_graph.impl"

#include "create_custom_vertices_k3_graph_demo.impl"

#include <cassert>
#include <iostream>
#include "has_custom_vertex_with_my_vertex.h"
#include "save_custom_vertices_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

void create_custom_vertices_k3_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_vertices_k3_graph();
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 3);
    const my_custom_vertex a("Karen","red",0.0,0.0);
    const my_custom_vertex b("Kristel","black",1.1,1.1);
    const my_custom_vertex c("Kathleen","blond",2.2,2.2);
    assert(has_custom_vertex_with_my_custom_vertex(a, g));
    assert(has_custom_vertex_with_my_custom_vertex(b, g));
    assert(has_custom_vertex_with_my_custom_vertex(c, g));
  }
  //Create the .dot and .svg of the 'create_custom_vertices_k3_graph' chapter
  {
    const auto g = create_custom_vertices_k3_graph();
    const std::string base_filename{"create_custom_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
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
  create_custom_vertices_k3_graph_demo();
  

}
