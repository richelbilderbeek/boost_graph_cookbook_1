#include "create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs.h"

#include <boost/test/unit_test.hpp>

#include "create_custom_and_selectable_edges_and_vertices_path_graph.h"
#include "save_custom_and_selectable_edges_and_vertices_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

BOOST_AUTO_TEST_CASE(create_all_direct_neighbour_custom_and_selectable_edges_and_vertices_subgraphs_path_graph_save)
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
  assert(sz == static_cast<int>(v.size()));
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
