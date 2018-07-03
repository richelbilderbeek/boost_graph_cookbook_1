#include "create_nasty_directed_bundled_edges_and_vertices_graph.h"
//#include "create_nasty_directed_bundled_edges_and_vertices_graph_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_bundled_edge.h"
#include "add_bundled_vertex.h"
#include "create_empty_directed_bundled_edges_and_vertices_graph.h"
#include "get_sorted_bundled_edge_my_edges.h"
#include "get_vertex_descriptors.h"
#include "load_directed_bundled_edges_and_vertices_graph_from_dot.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"

#ifndef BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
BOOST_AUTO_TEST_CASE(
  create_nasty_directed_bundled_edges_and_vertices_graph_thorough)
{
  {
    auto g = create_nasty_directed_bundled_edges_and_vertices_graph();
    const std::string filename{
      "create_nasty_directed_bundled_edges_and_vertices_graph_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h
      = load_directed_bundled_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    // get_my_bundled_edges returns the unsorted edge,
    // to compare the my_bundled_edges before and after, its results must be
    // sorted
    const auto a = get_sorted_bundled_edge_my_edges(g);
    const auto b = get_sorted_bundled_edge_my_edges(h);
    BOOST_CHECK(a == b);
  }
}
#endif // BOOST_GRAPH_COOKBOOK_1_NO_GRAPHVIZ
