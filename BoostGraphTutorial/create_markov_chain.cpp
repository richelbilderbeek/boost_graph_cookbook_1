#include "create_markov_chain.h"

#include "create_markov_chain.impl"

#include "create_markov_chain_demo.impl"

#include <cassert>
#include <iostream>

#include "copy_file.h"
#include "convert_dot_to_svg.h"
#include "save_graph_to_dot.h"

void create_markov_chain_test() noexcept
{
  //Create the .dot and .svg of the 'create_markov_chain' chapter
  {
    const auto g = create_markov_chain();
    const std::string base_filename{"create_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g, dot_filename);
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
  create_markov_chain_demo();
  
}
