#include "load_directed_bundled_vertices_graph_from_dot.h"
#include "load_directed_bundled_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_bundled_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_bundled_vertices_graph_to_dot.h"
#include "file_to_vector.h"
#include "my_bundled_vertex.h"
#include "create_nasty_directed_bundled_vertices_graph.h"
#include "get_sorted_bundled_vertex_my_vertexes.h"

BOOST_AUTO_TEST_CASE(load_directed_bundled_vertices_graph_from_dot_thorough)
{
  //Basic tests: empty graph
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
  //Basic tests: graph with harder texts
  {
    //See: create_nasty_directed_bundled_vertices_graph
  }
}
