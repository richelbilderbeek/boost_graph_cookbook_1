#include <boost/test/unit_test.hpp>
#include "add_custom_and_selectable_edge.h"
#include "add_custom_and_selectable_edge_demo.impl"

#include "create_empty_directed_custom_and_selectable_edges_and_vertices_graph.h"
#include "create_empty_undirected_custom_and_selectable_edges_and_vertices_graph.h"

#include "add_custom_and_selectable_edge.h"


#include <boost/test/unit_test.hpp>

#include "create_empty_undirected_custom_and_selectable_vertices_graph.h"

BOOST_AUTO_TEST_CASE(test_add_custom_and_selectable_edge_thorough)
{
  //Add 1
  {
    auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_custom_edge edge("X");
    add_custom_and_selectable_edge(edge, true, g);
    BOOST_CHECK(boost::num_vertices(g) == 2);
    BOOST_CHECK(boost::num_edges(g) == 1);
  }
  //Add 2
  {
    auto g = create_empty_undirected_custom_and_selectable_edges_and_vertices_graph();
    BOOST_CHECK(boost::num_vertices(g) == 0);
    BOOST_CHECK(boost::num_edges(g) == 0);
    const my_custom_edge edge_1("X");
    const my_custom_edge edge_2("Y");
    add_custom_and_selectable_edge(edge_1, true, g);
    add_custom_and_selectable_edge(edge_2, false, g);
    BOOST_CHECK(boost::num_vertices(g) == 4);
    BOOST_CHECK(boost::num_edges(g) == 2);
  }
}



