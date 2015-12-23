#include "add_custom_edge.h"

#include "add_custom_edge_demo.impl"

#include <cassert>
#include <iostream>

#include <boost/graph/adjacency_list.hpp>
#include "create_empty_undirected_custom_edges_and_vertices_graph.h"

#include "get_custom_edge_my_edges.h"

void add_custom_edge_test() noexcept
{
  //Add 1
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_edge edge("X");
    add_custom_edge(edge, g);
    assert(boost::num_vertices(g) == 2);
    assert(boost::num_edges(g) == 1);
    const std::vector<my_custom_edge> edges{get_custom_edge_my_edges(g)};
    const std::vector<my_custom_edge> expected_edges{edge};
    assert(edges == expected_edges);
  }
  //Add 2
  {
    auto g = create_empty_undirected_custom_edges_and_vertices_graph();
    assert(boost::num_vertices(g) == 0);
    assert(boost::num_edges(g) == 0);
    const my_custom_edge edge_1("X");
    const my_custom_edge edge_2("Y");
    add_custom_edge(edge_1, g);
    add_custom_edge(edge_2, g);
    assert(boost::num_vertices(g) == 4);
    assert(boost::num_edges(g) == 2);
    const std::vector<my_custom_edge> edges{get_custom_edge_my_edges(g)};
    const std::vector<my_custom_edge> expected_edges{edge_1, edge_2};
    assert(edges == expected_edges);
  }
  add_custom_edge_demo();
  std::cout << __func__ << ": OK" << '\n';
}



