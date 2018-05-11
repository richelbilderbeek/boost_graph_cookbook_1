#include "create_k2_graph.h"
#include "create_k2_graph_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_vertex_descriptors.h"
#include "get_edge_descriptors.h"
#include "save_graph_to_dot.h"
#include "convert_dot_to_svg.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(create_k2_graph_thorough)
{
  //Basic tests
  {
    const auto g = create_k2_graph();
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
  }
  #ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
  //Create the .dot and .svg of the 'create_k2_graph' chapter
  {

    const auto g = create_k2_graph();
    const std::string base_filename{"create_k2_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_graph_to_dot(g,dot_filename);
    BOOST_CHECK(is_regular_file(dot_filename));
    convert_dot_to_svg(dot_filename,svg_filename);
    BOOST_CHECK(is_regular_file(svg_filename));
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
  #endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
  //Copy a graph
  {
    const auto g = create_k2_graph();
    const auto h(g);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  }
}
