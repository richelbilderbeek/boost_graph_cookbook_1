#include "create_path_graph.h"
#include "create_path_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

// Create the .dot and .svg of the 'create_path_graph' chapter
BOOST_AUTO_TEST_CASE(create_path_graph_dot_and_svg)
{
  for (const int n : { 3, 4, 5 })
  {
    const auto g = create_path_graph(n);
    const std::string base_filename{ "create_path_graph_" + std::to_string(n) };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
