#include "create_path_graph.h"

#include "create_empty_undirected_graph.h"

boost::adjacency_list<
  boost::vecS,
  boost::vecS,
  boost::undirectedS
>
create_path_graph(const int n_vertices) noexcept
{
  assert(n_vertices >= 2);
  auto g = create_empty_undirected_graph();

  auto vd_1 = boost::add_vertex(g);
  for (int i=1; i!=n_vertices; ++i)
  {
    auto vd_2 = boost::add_vertex(g);
    const auto aer = boost::add_edge(vd_1, vd_2, g);
    assert(aer.second);
    vd_1 = vd_2;
  }
  return g;
}

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
  //Create the .dot and .svg of the 'create_graph_graph' chapter
  {

    const auto g = create_path_graph(3);
    const std::string base_filename{"create_path_graph_3"};
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
  std::cout << __func__ << ": OK" << '\n';
}
