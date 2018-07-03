#include "create_all_direct_neighbour_text_edges_and_vertices_subgraphs.h"

#include <boost/test/unit_test.hpp>
#include "create_text_edges_and_vertices_k2_graph.h"
#include "create_text_edges_and_vertices_k3_graph.h"
#include "create_text_edges_and_vertices_petersen_graph.h"
#include "save_text_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "create_text_edges_and_vertices_path_graph.h"
#include "has_edge_with_name.h"
#include "has_vertex_with_name.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_text_edges_and_vertices_subgraphs_thorough_graphviz)
{
  //Path
  {
    const auto v = create_all_direct_neighbour_text_edges_and_vertices_subgraphs(
      create_text_edges_and_vertices_path_graph(
        {"1","2"}, {"A","B","C"}
      )
    );
    const int sz{3};
    BOOST_CHECK(sz == static_cast<int>(v.size()));
    for (int i=0; i!=sz; ++i)
    {
      const auto g = v[i];
      const std::string base_filename{
        "create_all_direct_neighbour_text_edges_and_vertices_subgraphs_"
        + std::to_string(i)
      };
      const std::string dot_filename{base_filename + ".dot"};
      const std::string svg_filename{base_filename + ".svg"};
      save_text_edges_and_vertices_graph_to_dot(g, dot_filename);
      convert_dot_to_svg(dot_filename, svg_filename);
      copy_file(
        dot_filename,
        "../boost_graph_cookbook_1/" + dot_filename,
        copy_file_mode::allow_overwrite
      );
      copy_file(
        svg_filename,
        "../boost_graph_cookbook_1/" + svg_filename,
        copy_file_mode::allow_overwrite
      );
      std::remove(dot_filename.c_str());
      std::remove(svg_filename.c_str());
    }
  }
}
