#include "create_nasty_undirected_bundled_edges_and_vertices_graph.h"

#include <boost/test/unit_test.hpp>

#include "add_bundled_edge.h"
#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "save_bundled_edges_and_vertices_graph_to_dot.h"
#include "load_undirected_bundled_edges_and_vertices_graph_from_dot.h"
#include "get_sorted_bundled_edge_my_edges.h"

BOOST_AUTO_TEST_CASE(create_nasty_undirected_bundled_edges_and_vertices_graph_thorough)
{
  {
    auto g = create_nasty_undirected_bundled_edges_and_vertices_graph();
    const std::string filename{
      "create_nasty_undirected_bundled_edges_and_vertices_graph_test.dot"
    };
    save_bundled_edges_and_vertices_graph_to_dot(g, filename);
    const auto h = load_undirected_bundled_edges_and_vertices_graph_from_dot(filename);
    BOOST_CHECK(boost::num_edges(g) == boost::num_edges(h));
    BOOST_CHECK(boost::num_vertices(g) == boost::num_vertices(h));
    const auto a = get_sorted_bundled_edge_my_edges(g);
    const auto b = get_sorted_bundled_edge_my_edges(h);
    BOOST_CHECK(a == b);
  }
  
}
