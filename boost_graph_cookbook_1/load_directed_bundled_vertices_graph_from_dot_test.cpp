#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_directed_bundled_vertices_graph_from_dot.h"
#include "load_directed_bundled_vertices_graph_from_dot_demo.impl"

#include "convert_dot_to_svg.h"
#include "copy_file.h"
#include "create_bundled_vertices_markov_chain.h"
#include "create_nasty_directed_bundled_vertices_graph.h"
#include "file_to_vector.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"
#include "is_regular_file.h"
#include "my_bundled_vertex.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE(load_directed_bundled_vertices_graph_from_dot_thorough)
{
  // Basic tests: empty graph
  {
    const auto g = create_empty_directed_bundled_vertices_graph();
    const std::string filename{
      "load_directed_bundled_vertices_graph_from_dot_test.dot"
    };
    save_bundled_vertices_graph_to_dot(g, filename);
    const auto h = load_directed_bundled_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_my_bundled_vertexes(g) == get_my_bundled_vertexes(h));
  }
  // Basic tests: graph with harder texts
  {
    // See: create_nasty_directed_bundled_vertices_graph
  }
}

BOOST_AUTO_TEST_CASE(
  load_directed_bundled_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_bundled_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(load_directed_bundled_vertices_graph_from_dot(dot_filename),
    std::invalid_argument);
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
