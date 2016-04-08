#include "load_directed_named_vertices_graph_from_dot.h"
#include "load_directed_named_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_named_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_named_vertices_graph_to_dot.h"
#include "file_to_vector.h"
#include "create_nasty_directed_named_vertices_graph.h"
#include "is_regular_file.h"
#include "get_sorted_vertex_names.h"

BOOST_AUTO_TEST_CASE(load_directed_named_vertices_graph_from_dot_thorough)
{
  //Basic
  {
    const auto g = create_named_vertices_markov_chain();
    const std::string dot_filename{"load_directed_named_vertices_graph_from_dot_test_markov_chain.dot"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_named_vertices_graph_from_dot(dot_filename);
    save_named_vertices_graph_to_dot(h, dot_filename);
    BOOST_CHECK(get_vertex_names(g) == get_vertex_names(h));
  }
  //Nasty
  {
    const auto g = create_nasty_directed_named_vertices_graph();
    const std::string dot_filename{"create_nasty_directed_named_vertices_graph.dot"};
    save_named_vertices_graph_to_dot(g, dot_filename);
    const auto h = load_directed_named_vertices_graph_from_dot(dot_filename);
    save_named_vertices_graph_to_dot(h, dot_filename);
    BOOST_CHECK(get_sorted_vertex_names(g) == get_sorted_vertex_names(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_directed_named_vertices_graph_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_directed_named_vertices_graph_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_directed_named_vertices_graph_from_dot(dot_filename),
    std::invalid_argument
  );
}
