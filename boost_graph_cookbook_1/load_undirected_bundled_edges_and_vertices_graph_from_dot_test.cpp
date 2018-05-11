#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ

#include "load_undirected_bundled_edges_and_vertices_graph_from_dot.h"
#include "load_undirected_bundled_edges_and_vertices_graph_from_dot_demo.impl"

#include <set>
#include <boost/test/unit_test.hpp>
#include "add_bundled_edge.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_bundled_edges_and_vertices_k3_graph.h"
#include "create_nasty_undirected_bundled_edges_and_vertices_graph.h"
#include "get_sorted_bundled_edge_my_edges.h"
#include "file_to_vector.h"
#include "my_bundled_vertex.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(load_undirected_bundled_edges_and_vertices_graph_from_dot_thorough)
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    const std::string filename{
      "load_undirected_bundled_edges_and_vertices_graph_from_dot_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_undirected_bundled_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_my_bundled_edges(g) == get_my_bundled_edges(h));
  }
  //Basic tests: nasty graph
  {
    //See 'create_nasty_undirected_bundled_edges_and_vertices_graph'
  }
  //Create the picture 'load_undirected_bundled_edges_and_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_edges_and_vertices_k3_graph();
    const std::string base_filename{"create_bundled_edges_and_vertices_k3_graph"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = file_to_vector(dot_filename);
    const auto h = load_undirected_bundled_edges_and_vertices_graph_from_dot(dot_filename);
    save_bundled_edges_and_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = file_to_vector(dot_filename);
    BOOST_CHECK(old_text == new_text);
    convert_dot_to_svg(dot_filename, svg_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    copy_file(
      svg_filename,
      "../boost_graph_cookbook_1/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      dot_filename,
      "../boost_graph_cookbook_1/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_bundled_edges_and_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_bundled_edges_and_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_bundled_edges_and_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
