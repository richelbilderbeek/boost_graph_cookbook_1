#include "create_markov_chain_graph.h"

#include "create_markov_chain_graph.impl"

#include "create_markov_chain_graph_demo.impl"

#include <cassert>
#include <iostream>

#include "fileio.h"
#include "convert_dot_to_svg.h"
#include "save_graph_to_dot.h"

void create_markov_chain_graph_test() noexcept
{
  {
    const auto g = create_markov_chain_graph();
    const std::string dot_filename{"create_markov_chain_graph.dot"};
    const std::string svg_filename{"create_markov_chain_graph.svg"};
    save_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    ribi::FileIo().CopyFile(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
    ribi::FileIo().CopyFile(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      ribi::fileio::CopyMode::allow_overwrite
    );
  }
  create_markov_chain_graph_demo();
  std::cout << __func__ << ": OK" << '\n';
}
