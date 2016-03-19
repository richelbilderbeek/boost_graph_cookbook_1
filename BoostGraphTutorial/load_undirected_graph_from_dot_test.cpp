#include "load_undirected_graph_from_dot.h"
#include "load_undirected_graph_from_dot.impl"
#include "load_undirected_graph_from_dot_demo.impl"

#include <boost/test/unit_test.hpp>
#include "create_k2_graph.h"
#include "save_graph_to_dot.h"
#include "copy_file.h"
#include "convert_dot_to_svg.h"

BOOST_AUTO_TEST_CASE(load_undirected_graph_from_dot_thorough)
{
  //Create the picture 'load_undirected_graph_from_dot_test_k2.svg'
  //Create graphs, save it to dot
  //Create another graph by loading it, then save it to .dot, convert that .dot to .svg
  {
    const auto g = create_k2_graph();
    const std::string dot_filename{"load_undirected_graph_from_dot_test_k2.dot"};
    save_graph_to_dot(g, dot_filename);
    const auto h = load_undirected_graph_from_dot(dot_filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
  }
  
}
