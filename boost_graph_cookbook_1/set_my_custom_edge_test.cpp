#include "set_my_custom_edge.h"
#include "set_my_custom_edge_demo.impl"

#include <boost/test/unit_test.hpp>
#include "add_custom_edge.h"
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"
#include "find_first_custom_edge_with_my_edge.h"
#include "get_my_custom_edge.h"

BOOST_AUTO_TEST_CASE(set_my_custom_edge_thorough)
{
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    const my_custom_edge old_name{"Dex"};
    add_custom_edge(old_name, g);
    const auto vd = find_first_custom_edge_with_my_edge(old_name, g);
    BOOST_CHECK(get_my_custom_edge(vd, g) == old_name);
    const my_custom_edge new_name{"Diggy"};
    set_my_custom_edge(new_name, vd, g);
    BOOST_CHECK(get_my_custom_edge(vd, g) == new_name);
  }
  
}
