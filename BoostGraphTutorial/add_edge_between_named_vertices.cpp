#include "add_edge_between_named_vertices.h"
#include "add_edge_between_named_vertices_demo.impl"
#include <boost/test/unit_test.hpp>
#include "create_empty_undirected_named_vertices_graph.h"
#include "add_named_vertex.h"

BOOST_AUTO_TEST_CASE(add_edge_between_named_vertices_thorough)
{
  {
    auto g = create_empty_undirected_named_vertices_graph();
    add_named_vertex("Bert", g);
    add_named_vertex("Ernie", g);
    add_edge_between_named_vertices("Bert", "Ernie", g);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
}

