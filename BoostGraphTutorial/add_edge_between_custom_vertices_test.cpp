
#include "add_edge_between_custom_vertices.h"
#include "add_edge_between_custom_vertices_demo.impl"

#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_custom_vertices_graph.h"
#include "add_custom_vertex.h"

BOOST_AUTO_TEST_CASE(add_edge_between_custom_vertices_thorough)
{
  {
    auto g = create_empty_undirected_custom_vertices_graph();
    const my_custom_vertex va("Bert");
    const my_custom_vertex vb("Ernie");
    add_custom_vertex(va, g);
    add_custom_vertex(vb, g);
    add_edge_between_custom_vertices(va, vb, g);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
}

