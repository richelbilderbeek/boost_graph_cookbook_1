#include "add_named_edge_between_vertices.h"
#include "add_named_edge_between_vertices_demo.impl"

#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_named_edges_and_vertices_graph.h"
#include "add_named_edge_between_vertices.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(add_named_edge_between_vertices_thorough)
{
  {
    auto g = create_empty_undirected_named_edges_and_vertices_graph();
    const auto from = add_named_vertex("Bert", g);
    const auto to = add_named_vertex("Ernie", g);
    add_named_edge_between_vertices("Friends", from, to, g);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
}

