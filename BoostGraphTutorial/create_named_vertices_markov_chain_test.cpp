#include "create_named_vertices_markov_chain.h"
#include "create_named_vertices_markov_chain_demo.impl"

#include <boost/test/unit_test.hpp>
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "add_named_vertex.h"
#include "get_edge_iterators.h"
#include "get_vertex_iterators.h"
#include "get_edge_descriptors.h"
#include "get_vertex_descriptors.h"
#include "get_vertex_names.h"
#include "create_named_vertices_markov_chain.h"
#include "save_named_vertices_graph_to_dot.h"
#include "load_directed_named_vertices_graph_from_dot.h"
#include "get_sorted_named_vertex_my_vertexes.h"
#include "create_nasty_directed_named_vertices_graph.h"

BOOST_AUTO_TEST_CASE(create_named_vertices_markov_chain_thorough)
{
  //Basic tests
  {
    const auto g = create_named_vertices_markov_chain();
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 4);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 4);
    const auto vip = get_vertex_iterators(g);
    BOOST_CHECK(vip.first != vip.second);
    const auto vds = get_vertex_descriptors(g);
    BOOST_CHECK(vds.size() == 2);
    const auto eip = get_edge_iterators(g);
    BOOST_CHECK(eip.first != eip.second);
    const auto eds = get_edge_descriptors(g);
    BOOST_CHECK(eds.size() == 4);
    const std::vector<std::string> expected_names{"Good", "Not bad"};
    const std::vector<std::string> vertex_names = get_vertex_names(g);
    BOOST_CHECK(expected_names == vertex_names);
  }
  #ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
  //Nasty graph
  {
    auto g = create_nasty_directed_named_vertices_graph();
    const std::string filename{
      "create_nasty_directed_named_vertices_graph_test.dot"
    };
    save_named_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_named_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_vertex_names(g);
    const auto b = get_sorted_vertex_names(h);
    BOOST_CHECK(a == b);
  }
  //Create the .dot and .svg of the 'create_named_vertices_markov_chain' chapter
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string dot_filename{"create_named_vertices_markov_chain.dot"};
    const std::string svg_filename{"create_named_vertices_markov_chain.svg"};
    save_named_vertices_graph_to_dot(g, dot_filename);
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
    std::remove(dot_filename.c_str());
    std::remove(svg_filename.c_str());
  }
  #endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
}
