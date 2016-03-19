#include "get_my_custom_edge.h"
#include "get_my_custom_edge_demo.impl"


#include <boost/test/unit_test.hpp>


#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "add_custom_edge.h"
#include "find_first_custom_edge_with_my_edge.h"

BOOST_AUTO_TEST_CASE(get_my_custom_edge_thorough)
{
  //Basic tests
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    const my_custom_edge edge{"Dex","Diggy",1.0,2.0};
    add_custom_edge(edge, g);
    const auto vd = find_first_custom_edge_with_my_edge(edge,g);
    BOOST_CHECK(get_my_custom_edge(vd,g) == edge);
  }
}
