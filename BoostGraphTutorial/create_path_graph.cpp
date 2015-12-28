#include "create_path_graph.h"

#include "create_path_graph.impl"
#include "create_path_graph_demo.impl"

#include <cassert>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

void create_path_graph_test() noexcept
{
  //Basic tests
  {
    const auto g = create_path_graph(2);
    assert(boost::num_edges(g) == 1);
    assert(boost::num_vertices(g) == 2);
  }
  //Basic tests
  {
    const auto g = create_path_graph(3);
    assert(boost::num_edges(g) == 2);
    assert(boost::num_vertices(g) == 3);
  }
  //Basic tests
  {
    const auto g = create_path_graph(4);
    assert(boost::num_edges(g) == 3);
    assert(boost::num_vertices(g) == 4);
  }
  //Create the .dot and .svg of the 'create_path_graph' chapter
  for (const int n: {3,4, 5} )
  {

    const auto g = create_path_graph(n);
    const std::string base_filename{"create_path_graph_" + std::to_string(n)};
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
  create_path_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
