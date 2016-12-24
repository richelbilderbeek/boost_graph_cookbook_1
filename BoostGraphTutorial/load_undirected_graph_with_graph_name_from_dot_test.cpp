#ifndef BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
#include "load_undirected_graph_with_graph_name_from_dot.h"
#include "load_undirected_graph_with_graph_name_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "save_graph_with_graph_name_to_dot.h"
#include "create_k2_graph_with_graph_name.h"
#include "convert_dot_to_svg.h"
#include "file_to_vector.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(load_undirected_graph_with_graph_name_from_dot_thorough)
{
  {
    const auto g = create_k2_graph_with_graph_name();
    const std::string base_filename{"create_k2_graph_with_graph_name"};
    const std::string dot_filename{base_filename + ".dot"};
    save_graph_with_graph_name_to_dot(g, dot_filename);
    const auto h = load_undirected_graph_with_graph_name_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_graph_name(g) == get_graph_name(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_graph_with_graph_name_from_dot_when_file_is_absent)
{
  const std::string dot_filename{
    "load_undirected_graph_with_graph_name_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filename));
  BOOST_CHECK_THROW(
    load_undirected_graph_with_graph_name_from_dot(dot_filename),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_TUTORIAL_NO_GRAPHVIZ
