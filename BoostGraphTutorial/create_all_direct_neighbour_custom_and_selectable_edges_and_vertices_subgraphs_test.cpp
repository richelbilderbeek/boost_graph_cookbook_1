#include "create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs.h"
#include "create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs_demo.impl"


#include <boost/test/unit_test.hpp>

#include "create_custom_and_selectable_edges_and_vertices_k2_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_k3_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_path_graph.h"
#include "create_custom_and_selectable_edges_and_vertices_petersen_graph.h"
#include "has_edge_with_my_edge.h"
#include "has_vertex_with_my_vertex.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs_thorough)
{
  //K2
  {
    const auto v
      = create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs(
        create_custom_and_selectable_edges_and_vertices_k2_graph()
      );
    BOOST_CHECK(v.size() == 2);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
      const my_custom_vertex va("A","source",0.0,0.0);
      const my_custom_vertex vb("B","target",3.14,3.14);
      const my_custom_edge ea("between");
      BOOST_CHECK(has_vertex_with_my_vertex(va, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vb, g));
      BOOST_CHECK(has_edge_with_my_edge(ea, g));
    }
  }
  //K3
  {
    const auto v
      = create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs(
        create_custom_and_selectable_edges_and_vertices_k3_graph()
      );
    BOOST_CHECK(v.size() == 3);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
      const my_custom_vertex va("Karen","red",1.1,2.2);
      const my_custom_vertex vb("Kristel","black",3.3,4.4);
      const my_custom_vertex vc("Kathleen","blond",5.5,6.6);
      const my_custom_edge ea("1");
      const my_custom_edge eb("2");
      const my_custom_edge ec("3");
      BOOST_CHECK(has_vertex_with_my_vertex(va, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vb, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vc, g));
      BOOST_CHECK(has_edge_with_my_edge(ea, g));
      BOOST_CHECK(has_edge_with_my_edge(eb, g));
      BOOST_CHECK(has_edge_with_my_edge(ec, g));
    }
  }
  //Path
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs(
      create_custom_and_selectable_edges_and_vertices_path_graph(
        {
          my_custom_edge("Belgium","Country of birth",1.1,2.2),
          my_custom_edge("France","Favorite country for holidays",3.3,4.4)
        }, { false, false },
        {
          my_custom_vertex("Hanne","red",1.1,2.2),
          my_custom_vertex("Marthe","black",3.3,4.4),
          my_custom_vertex("Klaasje","blond",5.5,6.6)
        }, { false, true, false }
      )
    );
    const int sz{3};
    BOOST_CHECK(sz == static_cast<int>(v.size()));
    for (int i=0; i!=sz; ++i)
    {
      const auto g = v[i];
      const std::string base_filename{"create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs_" + std::to_string(i)};
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
      std::remove(dot_filename.c_str());
      std::remove(svg_filename.c_str());
    }
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs(create_custom_and_selectable_edges_and_vertices_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}
