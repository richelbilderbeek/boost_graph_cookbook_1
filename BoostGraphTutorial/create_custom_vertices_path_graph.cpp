#include "create_custom_vertices_path_graph.h"

#include "create_custom_vertices_path_graph.impl"
#include "create_custom_vertices_path_graph_demo.impl"

#include <cassert>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"
#include "get_my_custom_vertexes.h"

void create_custom_vertices_path_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_custom_vertices_path_graph( {} );
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 0);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes {
      my_custom_vertex("X")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    assert(boost::num_edges(g) == 0);
    assert(boost::num_vertices(g) == 1);
    assert(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes {
      my_custom_vertex("X"),
      my_custom_vertex("Y")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
    assert(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
  {
    const std::vector<my_custom_vertex> my_custom_vertexes {
      my_custom_vertex("X"),
      my_custom_vertex("Y"),
      my_custom_vertex("Z")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    assert(boost::num_edges(g) == 2);
    assert(boost::num_vertices(g) == 3);
    assert(get_my_custom_vertexes(g) == my_custom_vertexes);
  }
  //Create the .dot and .svg of the 'create_custom_vertices_path_graph' chapter
  //for (const int n: {3,4, 5} )
  {
    const std::vector<my_custom_vertex> my_custom_vertexes {
      my_custom_vertex("A"),
      my_custom_vertex("B"),
      my_custom_vertex("C"),
      my_custom_vertex("D")
    };
    const auto g = create_custom_vertices_path_graph(my_custom_vertexes);
    const std::string base_filename{"create_custom_vertices_path_graph_4"};
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
  create_custom_vertices_path_graph_demo();
  
}
