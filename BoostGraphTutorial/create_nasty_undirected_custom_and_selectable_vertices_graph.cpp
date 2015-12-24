#include "create_nasty_undirected_custom_and_selectable_vertices_graph.h"

#include <cassert>
#include "add_custom_and_selectable_vertex.h"
#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"
#include "save_custom_and_selectable_vertices_graph_to_dot.h"
#include "load_undirected_custom_and_selectable_vertices_graph_from_dot.h"
#include "get_sorted_custom_vertex_my_vertexes.h"
#include "get_sorted_vertex_selectednesses.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"

void create_nasty_undirected_custom_and_selectable_vertices_graph_test() noexcept
{
  //Create the .dot and .svg of the 'create_nasty_undirected_custom_and_selectable_vertices_graph' chapter
  {
    const auto g = create_nasty_undirected_custom_and_selectable_vertices_graph();
    const std::string base_filename{"create_nasty_undirected_custom_and_selectable_vertices_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_custom_and_selectable_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_undirected_custom_and_selectable_vertices_graph_from_dot(dot_filename);
    assert(boost::num_edges(g) == boost::num_edges(h));
    assert(boost::num_vertices(g) == boost::num_vertices(h));
    assert(get_sorted_custom_vertex_my_vertexes(g)
      ==  get_sorted_custom_vertex_my_vertexes(h)
    );
    assert(get_sorted_vertex_selectednesses(g)
      == get_sorted_vertex_selectednesses(h)
    );
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
  std::cout << __func__ << ": OK" << '\n';
}
