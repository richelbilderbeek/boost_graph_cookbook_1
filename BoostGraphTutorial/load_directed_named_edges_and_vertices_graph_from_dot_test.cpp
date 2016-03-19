#include "load_directed_named_edges_and_vertices_graph_from_dot.h"
#include "load_directed_named_edges_and_vertices_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "copy_file.h"
#include "create_named_edges_and_vertices_markov_chain.h"
#include "convert_dot_to_svg.h"
#include "save_named_edges_and_vertices_graph_to_dot.h"
#include "helper.h"

BOOST_AUTO_TEST_CASE(load_directed_named_edges_and_vertices_graph_from_dot_thorough)
{
  //Create the picture 'load_directed_named_edges_and_vertices_graph_from_dot_test_markov_chain.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_named_edges_and_vertices_markov_chain();
    const std::string dot_filename{"load_directed_named_edges_and_vertices_graph_from_dot_test_markov_chain.dot"};
    save_named_edges_and_vertices_graph_to_dot(g, dot_filename);
    const auto old_text = helper().file_to_vector(dot_filename);
    const auto h = load_directed_named_edges_and_vertices_graph_from_dot(dot_filename);
    save_named_edges_and_vertices_graph_to_dot(h, dot_filename);
    const auto new_text = helper().file_to_vector(dot_filename);
    BOOST_CHECK(old_text == new_text);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  }
  
}
