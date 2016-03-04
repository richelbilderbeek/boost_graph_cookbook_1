#include "create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs.h"

#include "create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_demo.impl"

#include <cassert>
#include <iostream>
#include "create_custom_and_selectable_vertices_k2_graph.h"
#include "create_custom_and_selectable_vertices_k3_graph.h"
#include "create_custom_and_selectable_vertices_path_graph.h"
#include "create_custom_and_selectable_vertices_petersen_graph.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

void create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_test() noexcept
{
  //K2
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(create_custom_and_selectable_vertices_k2_graph());
    assert(v.size() == 2);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 2);
      assert(boost::num_edges(g) == 1);
    }
  }
  //K3
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(create_custom_and_selectable_vertices_k3_graph());
    assert(v.size() == 3);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 3);
      assert(boost::num_edges(g) == 3);
    }
  }
  //Path
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(
      create_custom_and_selectable_vertices_path_graph(
        {
          my_custom_vertex("Hanne","red",1.1,2.2),
          my_custom_vertex("Marthe","black",3.3,4.4),
          my_custom_vertex("Klaasje","blond",5.5,6.6)
        }, { false, true, false }
      )
    );
    const int sz{3};
    assert(sz == static_cast<int>(v.size()));
    for (int i=0; i!=sz; ++i)
    {
      const auto g = v[i];
      const std::string base_filename{"create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_" + std::to_string(i)};
      const std::string dot_filename{base_filename + ".dot"};
      const std::string svg_filename{base_filename + ".svg"};
      save_custom_and_selectable_vertices_graph_to_dot(g, dot_filename);
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
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(create_custom_and_selectable_vertices_petersen_graph());
    assert(v.size() == 10);
    for (const auto g: v)
    {
      assert(boost::num_vertices(g) == 4);
      assert(boost::num_edges(g) == 3);
    }
  }
  create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_demo();
}
