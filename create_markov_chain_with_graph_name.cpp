#include "create_markov_chain_with_graph_name.h"

#include "create_markov_chain_with_graph_name.impl"

#include "create_markov_chain_with_graph_name_demo.impl"

#include <cassert>
#include <iostream>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "save_graph_with_graph_name_to_dot.h"

void create_markov_chain_with_graph_name_test() noexcept
{
  //Basic tests
  {
    const auto g = create_markov_chain_with_graph_name();
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 4);
    assert(get_graph_name(g) == "Two-state Markov chain");

  }
  //Create the .dot and .svg of the 'create_markov_chain' chapter
  {
    const auto g = create_markov_chain_with_graph_name();
    const std::string base_filename{"create_markov_chain_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_with_graph_name_to_dot(g, dot_filename);
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    const std::string svg_filename{base_filename + ".svg"};
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
  }
  create_markov_chain_with_graph_name_demo();
  std::cout << __func__ << ": OK" << '\n';
}
