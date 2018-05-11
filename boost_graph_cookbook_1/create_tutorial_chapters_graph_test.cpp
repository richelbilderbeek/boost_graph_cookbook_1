#include "create_tutorial_chapters_graph.h"
#include <boost/test/unit_test.hpp>
#include <sstream>

#include "add_edge_between_named_vertices.h"
#include "add_named_vertex.h"
#include "convert_dot_to_svg.h"
#include "convert_svg_to_png.h"
#include "copy_file.h"
#include "create_empty_directed_named_vertices_graph.h"
#include "is_valid_dot_file.h"
#include "save_named_vertices_graph_to_dot.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_tutorial_chapters_graph_thorough)
{
  //Create the 'relation between chapters' figure
  {
    const auto g = create_tutorial_chapters_graph();
    const std::string base_filename{"create_tutorial_chapters_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_named_vertices_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }

  //Create the title figure
  {
    const auto g = create_tutorial_chapters_graph();
    const std::string base_filename{"title_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    const std::string png_filename{base_filename + ".png"};
    std::ofstream f(dot_filename);
    boost::write_graphviz(f,g);
    BOOST_CHECK(is_valid_dot_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    convert_svg_to_png(svg_filename,png_filename);
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      png_filename,
      "../boost_graph_cookbook_1/" + png_filename,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filename.c_str());
    std::remove(png_filename.c_str());
    std::remove(svg_filename.c_str());
  }
}
