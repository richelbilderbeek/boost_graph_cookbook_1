#include "load_undirected_named_vertices_graph_from_dot.h"
#include "load_undirected_named_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_named_vertices_k2_graph.h"
#include "convert_dot_to_svg.h"
#include "save_named_vertices_graph_to_dot.h"
#include "file_to_vector.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(load_undirected_named_vertices_graph_from_dot_thorough)
{
  //Basic test
  {
    const auto g = create_named_vertices_k2_graph();
    const std::string base_filename{"create_named_vertices_k2_graph.dot"};
    const std::string dot_filename{base_filename + ".dot"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_undirected_named_vertices_graph_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_vertex_names(g) == get_vertex_names(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_named_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_named_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_named_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}
