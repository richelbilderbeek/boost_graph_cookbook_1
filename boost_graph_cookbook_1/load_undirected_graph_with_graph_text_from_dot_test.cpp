#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
#include "load_undirected_graph_with_graph_text_from_dot.h"
#include "load_undirected_graph_with_graph_text_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "save_graph_with_graph_text_to_dot.h"
#include "create_k2_graph_with_graph_text.h"
#include "convert_dot_to_svg.h"
#include "file_to_vector.h"
#include "is_regular_file.h"

BOOST_AUTO_TEST_CASE(load_undirected_graph_with_graph_text_from_dot_thorough)
{
  {
    const auto g = create_k2_graph_with_graph_text();
    const std::string base_filetext{"create_k2_graph_with_graph_text"};
    const std::string dot_filetext{base_filetext + ".dot"};
    save_graph_with_graph_text_to_dot(g, dot_filetext);
    const auto h = load_undirected_graph_with_graph_text_from_dot(dot_filetext);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    BOOST_CHECK(get_graph_text(g) == get_graph_text(h));
  }
  
}

BOOST_AUTO_TEST_CASE(load_undirected_graph_with_graph_text_from_dot_when_file_is_absent)
{
  const std::string dot_filetext{
    "load_undirected_graph_with_graph_text_from_dot_when_file_is_absent.dot"
  };
  assert(!is_regular_file(dot_filetext));
  BOOST_CHECK_THROW(
    load_undirected_graph_with_graph_text_from_dot(dot_filetext),
    std::invalid_argument
  );
}

#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
