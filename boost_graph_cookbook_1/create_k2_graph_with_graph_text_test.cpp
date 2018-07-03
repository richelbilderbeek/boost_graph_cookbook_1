#include "create_k2_graph_with_graph_text.h"
#include "create_k2_graph_with_graph_text_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"
#include "save_graph_with_graph_text_to_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(create_k2_graph_with_graph_text_thorough)
{
  //Basic tests
  {
    const auto g = create_k2_graph_with_graph_text();
    const auto vip = get_vertex_iterators(g);
    BOOST_CHECK(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    BOOST_CHECK(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    BOOST_CHECK(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 1);
    BOOST_CHECK(boost::num_edges(g) == 1);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(get_graph_text(g) == "K2");
  }
  //Create the .dot and .svg of the 'create_k2_graph_with_graph_text' chapter
  {

    const auto g = create_k2_graph_with_graph_text();
    const std::string base_filetext{"create_k2_graph_with_graph_text"};
    const std::string dot_filetext{base_filetext + ".dot"};
    const std::string svg_filetext{base_filetext + ".svg"};
    save_graph_with_graph_text_to_dot(g,dot_filetext);
    BOOST_CHECK(is_regular_file(dot_filetext));
    convert_dot_to_svg(dot_filetext,svg_filetext);
    BOOST_CHECK(is_regular_file(svg_filetext));
    copy_file(
      dot_filetext,
      "../boost_graph_cookbook_1/" + dot_filetext,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      svg_filetext,
      "../boost_graph_cookbook_1/" + svg_filetext,
      copy_file_mode::allow_overwrite
    );
    std::remove(dot_filetext.c_str());
    std::remove(svg_filetext.c_str());
  }
}
