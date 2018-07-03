#include "create_markov_chain.h"
#include "create_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "save_graph_to_dot.h"

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(create_markov_chain_thorough)
{
  // Create the .dot and .svg of the 'create_markov_chain' chapter
  {
    const auto g = create_markov_chain();
    const std::string base_filename{ "create_markov_chain" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_graph_to_dot(g, dot_filename);
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
