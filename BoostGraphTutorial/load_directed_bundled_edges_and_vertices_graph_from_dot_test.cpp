#include "load_directed_bundled_edges_and_vertices_graph_from_dot.h"
#include "load_directed_bundled_edges_and_vertices_graph_from_dot_demo.impl"


#include <boost/test/unit_test.hpp>
#include <set>
#include "add_bundled_edge.h"
#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "create_bundled_edges_and_vertices_markov_chain.h"
#include "create_nasty_directed_bundled_edges_and_vertices_graph.h"
#include "get_my_bundled_vertexes.h"
#include "get_sorted_bundled_edge_my_edges.h"
#include "file_to_vector.h"
#include "my_bundled_vertex.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"

BOOST_AUTO_TEST_CASE(load_directed_bundled_edges_and_vertices_graph_from_dot_thorough)
{
  //Basic tests: empty graph
  {
    const auto g = create_empty_directed_bundled_edges_and_vertices_graph();
    const std::string filename{
      "load_directed_bundled_edges_and_vertices_graph_from_dot_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_my_bundled_edges(g) == get_my_bundled_edges(h));
  }
  //Basic tests: nasty graph
  {
    //See 'create_nasty_directed_bundled_edges_and_vertices_graph'
  }
  //Create the picture 'load_directed_bundled_edges_and_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_bundled_edges_and_vertices_markov_chain();
    const std::string base_filename{"create_bundled_edges_and_vertices_markov_chain"};
    const std::string dot_filename{base_filename + ".dot"};
    const std::string svg_filename{base_filename + ".svg"};
    save_bundled_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_my_bundled_vertexes(g) == get_my_bundled_vertexes(h));
    convert_dot_to_svg(dot_filename, svg_filename);
    copy_file(
      svg_filename,
      "../BoostGraphTutorial/" + svg_filename,
      copy_file_mode::allow_overwrite
    );
    copy_file(
      dot_filename,
      "../BoostGraphTutorial/" + dot_filename,
      copy_file_mode::allow_overwrite
    );
  }
  //Load incorrect .dot files: write an undirected graph
  {
    try
    {
      const auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
      //                          ^^
      const std::string filename{
        "create_empty_undirected_bundled_edges_and_vertices_graph.dot"
      };
      save_bundled_edges_and_vertices_graph_to_dot(g, filename);
      const auto h = load_directed_bundled_edges_and_vertices_graph_from_dot(filename);
      BOOST_CHECK(!"Should not get here");
    }
    catch (std::exception& e)
    {
      BOOST_CHECK(std::string(e.what())
        == "read_graphviz: Tried to read an undirected graph into a directed graph.");
    }
  }
}
