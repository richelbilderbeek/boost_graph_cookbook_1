#include "create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs.h"
#include "create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs_demo.impl"

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_bundled_edges_and_vertices_k2_graph.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "create_bundled_edges_and_vertices_path_graph.h"
#include "create_bundled_edges_and_vertices_petersen_graph.h"
#include "has_bundled_edge_with_my_edge.h"
#include "has_bundled_vertex_with_my_vertex.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(
  create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs_thorough)
{
  // K2
  {
    const auto v
      = create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs(
        create_bundled_edges_and_vertices_k2_graph());
    BOOST_CHECK(v.size() == 2);
    for (const auto g : v) {
      BOOST_CHECK(boost::num_vertices(g) == 2);
      BOOST_CHECK(boost::num_edges(g) == 1);
    }
  }
  // K3
  {
    const auto v
      = create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs(
        create_bundled_edges_and_vertices_k3_graph());
    BOOST_CHECK(v.size() == 3);
    for (const auto g : v) {
      BOOST_CHECK(boost::num_vertices(g) == 3);
      BOOST_CHECK(boost::num_edges(g) == 3);
      const my_bundled_vertex va("Red", "Not green", 1.0, 2.0);
      const my_bundled_vertex vb("Light red", "Not dark", 3.0, 4.0);
      const my_bundled_vertex vc("Orange", "Orangy", 5.0, 6.0);
      const my_bundled_edge ea("Oxygen", "Air", 1.0, 2.0);
      const my_bundled_edge eb("Helium", "From tube", 3.0, 4.0);
      const my_bundled_edge ec("Stable temperature", "Here", 5.0, 6.0);
      BOOST_CHECK(has_bundled_vertex_with_my_vertex(va, g));
      BOOST_CHECK(has_bundled_vertex_with_my_vertex(vb, g));
      BOOST_CHECK(has_bundled_vertex_with_my_vertex(vc, g));
      BOOST_CHECK(has_bundled_edge_with_my_edge(ea, g));
      BOOST_CHECK(has_bundled_edge_with_my_edge(eb, g));
      BOOST_CHECK(has_bundled_edge_with_my_edge(ec, g));
    }
  }
  // Path
  {
    const auto v
      = create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs(
        create_bundled_edges_and_vertices_path_graph(
          { my_bundled_edge("H", "Letter in name", 1.1, 2.2),
            my_bundled_edge("Even favorite number", "4 and 8", 3.3, 4.4) },
          { my_bundled_vertex("Hanne", "red", 1.1, 2.2),
            my_bundled_vertex("Marthe", "black", 3.3, 4.4),
            my_bundled_vertex("Klaasje", "blond", 5.5, 6.6) }));
    const int sz{ 3 };
    BOOST_CHECK(sz == static_cast<int>(v.size()));
#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
    for (int i = 0; i != sz; ++i) {
      const auto g = v[i];
      const std::string base_filename{
        "create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs_"
        + std::to_string(i)
      };
      const std::string dot_filename{ base_filename + ".dot" };
      const std::string svg_filename{ base_filename + ".svg" };
      save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
      convert_dot_to_svg(dot_filename, svg_filename);
      copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
        copy_file_mode::allow_overwrite);
      copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
        copy_file_mode::allow_overwrite);
      std::remove(dot_filename.c_str());
      std::remove(svg_filename.c_str());
    }
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
  }
  // Petersen Graph
  {
    const auto v
      = create_all_direct_neighbour_bundled_edges_and_vertices_subgraphs(
        create_bundled_edges_and_vertices_petersen_graph());
    BOOST_CHECK(v.size() == 10);
    for (const auto g : v) {
      BOOST_CHECK(boost::num_vertices(g) == 4);
      BOOST_CHECK(boost::num_edges(g) == 3);
    }
  }
}
