#include "create_tutorial_chapters_graph.h"
#include "create_tutorial_subchapters_graph.h"

#include "save_named_vertices_graph_to_dot.h"

#include <boost/test/unit_test.hpp>

#include <sstream>

#include "add_edge_between_named_vertices.h"
#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"

#include "copy_file.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "create_named_edges_and_vertices_k3_graph.h"
#include "create_named_vertices_k2_graph.h"
#include "is_valid_dot_file.h"

BOOST_AUTO_TEST_CASE(create_tutorial_subchapters_graph_thorough)
{
  {
    const auto g = create_tutorial_subchapters_graph();
    const std::string base_filename{ "create_tutorial_subchapters_graph" };
    const std::string dot_filename{ base_filename + ".dot" };
    const std::string svg_filename{ base_filename + ".svg" };
    save_named_vertices_graph_to_dot(g, dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(dot_filename, "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite);
    copy_file(svg_filename, "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite);
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
