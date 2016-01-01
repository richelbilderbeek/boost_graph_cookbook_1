#include "create_named_vertices_path_graph.h"

#include "create_named_vertices_path_graph.impl"
#include "create_named_vertices_path_graph_demo.impl"

#include <cassert>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include "get_vertex_names.h"

void create_named_vertices_path_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_named_vertices_path_graph( {} );
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
  }
  {
    const std::vector<std::string> names = {"X"};
    const auto g = create_named_vertices_path_graph(names);
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 1);
    assert(get_vertex_names(g) == names);
  }
  {
    const std::vector<std::string> names = {"X", "Y"};
    const auto g = create_named_vertices_path_graph(names);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(get_vertex_names(g) == names);
  }
  {
    const std::vector<std::string> names = {"X", "Y", "Z"};
    const auto g = create_named_vertices_path_graph(names);
    assert(boost::num_edges(g) == 2);
    assert(boost::num_vertices(g) == 3);
    assert(get_vertex_names(g) == names);
  }
  //Create the .dot and .svg of the 'create_named_vertices_path_graph' chapter
  //for (const int n: {3,4, 5} )
  {
    const std::vector<std::string> names = {"A", "B", "C", "D"};
    const auto g = create_named_vertices_path_graph(names);
    const std::string base_filename{"create_named_vertices_path_graph_4"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    assert(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    assert(is_regular_file(svg_filename));
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
  create_named_vertices_path_graph_demo();
  
}
