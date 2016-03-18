#include "create_petersen_graph.h"
#include "create_petersen_graph.impl"
#include "create_petersen_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_graph.h"
#include "is_regular_file.h"
#include "save_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(create_petersen_graph_thorough)
{
  //Basic tests
  {
    const auto g = create_petersen_graph();
    BOOST_CHECK(boost::num_edges(g) == 15);
    BOOST_CHECK(boost::num_vertices(g) == 10);
  }
  //Create the .dot and .svg of the 'create_k3_graph' chapter
  {

    const auto g = create_petersen_graph();
    const std::string base_filename{"create_petersen_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
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
  
}
