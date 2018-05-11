#include "create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs.h"
#include "create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_demo.impl"

#include <boost/test/unit_test.hpp>

#include <boost/test/unit_test.hpp>
#include "create_custom_and_selectable_vertices_k2_graph.h"
#include "create_custom_and_selectable_vertices_k3_graph.h"
#include "create_custom_and_selectable_vertices_path_graph.h"
#include "create_custom_and_selectable_vertices_petersen_graph.h"
#include "has_vertex_with_my_vertex.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs_thorough)
{
  //K2
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(
      create_custom_and_selectable_vertices_k2_graph()
    );
    BOOST_CHECK(v.size() == 2);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
      const my_custom_vertex va("A","source",0.0,0.0);
      const my_custom_vertex vb("B","target",3.14,3.14);
      BOOST_CHECK(has_vertex_with_my_vertex(va, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vb, g));
    }
  }
  //K3
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(create_custom_and_selectable_vertices_k3_graph());
    BOOST_CHECK(v.size() == 3);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
      const my_custom_vertex va("Karen","red",1.1,2.2);
      const my_custom_vertex vb("Kristel","black",3.3,4.4);
      const my_custom_vertex vc("Kathleen","blond",5.5,6.6);
      BOOST_CHECK(has_vertex_with_my_vertex(va, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vb, g));
      BOOST_CHECK(has_vertex_with_my_vertex(vc, g));
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
    BOOST_CHECK(sz == static_cast<int>(v.size()));
  }
  //Petersen Graph
  {
    const auto v = create_all_direct_neighbour_custom_and_selectable_vertices_subgraphs(create_custom_and_selectable_vertices_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g: v)
    {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}

