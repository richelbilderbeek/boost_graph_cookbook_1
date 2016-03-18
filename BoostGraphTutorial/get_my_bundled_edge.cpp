#include "get_my_bundled_edge.h"
#include "get_my_bundled_edge_demo.impl"

#include <boost/test/unit_test.hpp>

#include "add_bundled_vertex.h"
#include "create_empty_undirected_bundled_edges_and_vertices_graph.h"
#include "add_bundled_edge.h"
#include "find_first_bundled_edge_with_my_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

BOOST_AUTO_TEST_CASE(get_my_bundled_edge_thorough)
{
  //Basic tests
  {
    auto g = create_empty_undirected_bundled_edges_and_vertices_graph();
    const auto vd_a = add_bundled_vertex(
      my_bundled_vertex("A"), g
    );
    const auto vd_b = add_bundled_vertex(
      my_bundled_vertex("B"), g
    );
    const my_bundled_edge edge{"Dex","Diggy",1.0,2.0};
    add_bundled_edge(vd_a, vd_b, edge, g);
    const auto vd = find_first_bundled_edge_with_my_edge(edge,g);
    BOOST_CHECK(get_my_bundled_edge(vd,g) == edge);
  }
}
