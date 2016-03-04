#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs.h"

#include "create_all_direct_neighbour_named_edges_and_vertices_subgraphs_demo.impl"

#include <cassert>
#include <iostream>
#include "create_named_edges_and_vertices_k2_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_edges_and_vertices_petersen_graph.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "create_named_edges_and_vertices_path_graph.h"

void create_all_direct_neighbour_named_edges_and_vertices_subgraphs_test() noexcept
{
  //K2
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_k2_graph());
    assert(v.size() == 2);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 2);
      assert(boost::num_edges(g) == 1);
    }
  }
  //K3
  {
    const auto v
      = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(
        create_named_edges_and_vertices_k3_graph()
      );
    assert(v.size() == 3);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 3);
      assert(boost::num_edges(g) == 3);
      const my_custom_vertex va("Karen","red",1.1,2.2);
      const my_custom_vertex vb("Kristel","black",3.3,4.4);
      const my_custom_vertex vc("Kathleen","blond",5.5,6.6);
      const my_custom_edge ea("1");
      const my_custom_edge eb("2");
      const my_custom_edge ec("3");
      assert(has_vertex_with_my_vertex(va, g));
      assert(has_vertex_with_my_vertex(vb, g));
      assert(has_vertex_with_my_vertex(vc, g));
      assert(has_edge_with_my_edge(ea, g));
      assert(has_edge_with_my_edge(eb, g));
      assert(has_edge_with_my_edge(ec, g));
    }
  }
  //Path
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(
      create_named_edges_and_vertices_path_graph(
        {"1","2"}, {"A","B","C"}
      )
    );
    const int sz{3};
    assert(sz == static_cast<int>(v.size()));
    for (int i=0; i!=sz; ++i)
    {
      const auto g = v[i];
      const std::string base_filename{"create_all_direct_neighbour_named_edges_and_vertices_subgraphs_" + std::to_string(i)};
      const std::string dot_filename{base_filename + ".dot"};
      const std::string svg_filename{base_filename + ".svg"};
      save_named_edges_and_vertices_graph_to_dot(g, dot_filename);
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
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_named_edges_and_vertices_subgraphs(create_named_edges_and_vertices_petersen_graph());
    assert(v.size() == 10);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 4);
      assert(boost::num_edges(g) == 3);
    }
  }
  create_all_direct_neighbour_named_edges_and_vertices_subgraphs_demo();
}
